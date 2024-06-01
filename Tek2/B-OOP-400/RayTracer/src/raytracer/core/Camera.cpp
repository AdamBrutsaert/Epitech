#include "raytracer/core/Camera.hpp"
#include "raytracer/core/Display.hpp"
#include "raytracer/materials/IMaterial.hpp"

#include <thread>
#include <chrono>
#include <vector>
#include <iomanip>
#include <random>

namespace rt::core {
    Camera::Camera(
        double aspectRatio,
        std::size_t imageWidth,

        std::size_t samplesPerPixel,
        std::size_t maxDepth,

        double verticalFov,
        const rt::maths::Point3& lookFrom,
        const rt::maths::Point3& lookAt,
        const rt::maths::Vector3& up,

        double defocusAngle,
        double focusDistance,

        std::size_t threadCount,
        std::size_t threadBlockSize,

        const rt::materials::Color& background,

        const std::string& outputFile
    )
    {
        // Image settings
        this->_aspectRatio = aspectRatio;
        this->_imageWidth = imageWidth;
        this->_imageHeight = static_cast<std::size_t>(imageWidth / aspectRatio);
        this->_imageHeight += this->_imageHeight == 0;

        // Ray settings
        this->_samplesPerPixel = samplesPerPixel;
        this->_sampleScale = 1.0 / samplesPerPixel;
        this->_maxDepth = maxDepth;

        // Camera settings
        auto theta = rt::maths::DegreesToRadians(verticalFov);
        auto h = std::tan(theta / 2.0);
        auto viewportHeight = 2.0 * h * focusDistance;
        auto viewportWidth = viewportHeight * (double(this->_imageWidth) / double(this->_imageHeight));

        auto w = normalize(lookFrom - lookAt);
        auto u = normalize(cross(up, w));
        auto v = cross(w, u);

        auto viewportHorizontal = viewportWidth * u;
        auto viewportVertical = viewportHeight * -v;
        auto viewportTopLeft = lookFrom - (focusDistance * w) - (viewportHorizontal / 2.0) - (viewportVertical / 2.0);

        this->_imagePlanePixelHorizontal = viewportHorizontal / this->_imageWidth;
        this->_imagePlanePixelVertical = viewportVertical / this->_imageHeight;
        this->_imagePlaneCenter = lookFrom;
        this->_imagePlanePixelTopLeft = viewportTopLeft + 0.5 * (this->_imagePlanePixelHorizontal + this->_imagePlanePixelVertical);

        // Defocus settings
        auto defocusRadius = focusDistance * std::tan(rt::maths::DegreesToRadians(defocusAngle / 2.0));
        this->_defocusAngle = defocusAngle;
        this->_defocusDiskHorizontal = u * defocusRadius;
        this->_defocusDiskVertical = v * defocusRadius;

        // Multithreading settings
        this->_threadCount = threadCount;
        this->_threadBlockSize = threadBlockSize;

        // Lighting
        this->_background = background;

        // Output
        this->_outputFile.open(outputFile);
    }

    static rt::maths::Vector3 SampleSquare()
    {
        return rt::maths::Vector3(rt::maths::RandomDouble() - 0.5, rt::maths::RandomDouble() - 0.5, 0);
    }

    static rt::maths::Point3 DefocusDiskSample(const rt::maths::Vector3& center, const rt::maths::Vector3& u, const rt::maths::Vector3& v)
    {
        auto p = rt::maths::Vector3::RandomInUnitDisk();
        return center + (p.x * u) + (p.y * v);
    }

    void Camera::renderThread(
        const rt::objects::Scene& world,
        std::vector<rt::materials::Color>& pixels,
        std::deque<Chunk>& chunksQueue,
        std::mutex& chunksQueueMutex
    )
    {
        while (true) {
            Chunk chunk;

            {
                std::lock_guard<std::mutex> lock(chunksQueueMutex);

                if (chunksQueue.empty())
                    break;

                chunk = chunksQueue.front();
                chunksQueue.pop_front();
            }

            for (std::size_t y = 0; y < chunk.height; y++) {
                for (std::size_t x = 0; x < chunk.width; x++) {
                    rt::materials::Color color{0, 0, 0};

                    for (std::size_t sample = 0; sample < this->_samplesPerPixel; sample++) {
                        Ray r = this->getRay(chunk.x + x, chunk.y + y);
                        color += this->getRayColor(r, 0, world);
                    }

                    pixels[(chunk.y + y) * this->_imageWidth + (chunk.x + x)] = color * this->_sampleScale;
                }
            }
        }
    }

    void Camera::render(
        const rt::objects::Scene& world
    )
    {
        // Generating chunks
        std::deque<Chunk> chunksQueue;

        for (std::size_t y = 0; y < this->_imageHeight; y += this->_threadBlockSize) {
            for (std::size_t x = 0; x < this->_imageWidth; x += this->_threadBlockSize) {
                chunksQueue.push_back(Chunk{
                    x,
                    y,
                    std::min(this->_threadBlockSize, this->_imageWidth - x),
                    std::min(this->_threadBlockSize, this->_imageHeight - y)
                });
            }
        }

        // shuffle chunks - because its visually better on SFML rendering
        std::shuffle(chunksQueue.begin(), chunksQueue.end(), std::mt19937(std::random_device()()));

        std::size_t totalChunks = chunksQueue.size();

        // Output
        std::clog << "Allocating render buffer..." << std::flush;
        std::vector<rt::materials::Color> pixels(this->_imageHeight * this->_imageWidth, rt::materials::Color(0, 0, 0));

        // Spawning threads
        std::mutex chunksQueueMutex;
        std::vector<std::thread> threads;
        const auto now = std::chrono::system_clock::now();

        for (std::size_t i = 0; i < this->_threadCount; i++) {
            threads.push_back(std::thread(
                &Camera::renderThread,
                this,
                std::ref(world),
                std::ref(pixels),
                std::ref(chunksQueue),
                std::ref(chunksQueueMutex)
            ));
        }

        // Initializing SFML
        rt::core::Display display(this->_imageWidth, this->_imageHeight);

        // Displaying progress
        while (true) {
            display.poolEvent();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            double percent = 0.0;

            {
                std::lock_guard<std::mutex> lock(chunksQueueMutex);
                percent = 100.0 * (totalChunks - chunksQueue.size()) / totalChunks;
            }

            std::clog << "\rRemaining chunks (" << this->_threadCount << " threads): " << chunksQueue.size()
                << " (" << std::fixed << std::setprecision(2) << percent << "%)..." << std::flush;

            // Displaying image
            display.updatePixels(pixels);
            display.update();

            {
                std::lock_guard<std::mutex> lock(chunksQueueMutex);

                if (chunksQueue.size() == 0)
                    break;
            }
        }

        // Join threads
        for (auto& thread : threads)
            thread.join();

        // Display final image
        display.updatePixels(pixels);
        display.update();

        // Output to file
        this->_outputFile << "P3\n" << this->_imageWidth << " " << this->_imageHeight << "\n255\n";
        for (const auto& pixel : pixels)
            rt::materials::WritePixel(this->_outputFile, pixel);
        this->_outputFile.close();

        std::clog << "\rDone in " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - now).count()
            << "s. Closing window in 5 seconds." << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(5));
        display.close();
    }

    Ray Camera::getRay(std::size_t x, std::size_t y) const
    {
        auto offset = SampleSquare();
        auto pixelSample = this->_imagePlanePixelTopLeft
                            + ((x + offset.x) * this->_imagePlanePixelHorizontal)
                            + ((y + offset.y) * this->_imagePlanePixelVertical);

        auto origin = (this->_defocusAngle <= 0)
            ? this->_imagePlaneCenter
            : DefocusDiskSample(this->_imagePlaneCenter, this->_defocusDiskHorizontal, this->_defocusDiskVertical);
        auto direction = pixelSample - origin;

        return Ray(origin, direction);
    }

    rt::materials::Color Camera::getRayColor(
        const Ray& r,
        std::size_t depth,
        const rt::objects::Scene& world
    ) const
    {
        if (depth == this->_maxDepth)
            return rt::materials::Color(0,0,0);

        Hit hit;

        if (!world.hit(r, rt::maths::Interval(0.001, rt::maths::infinity), hit)) {
            if (depth == 0) return this->_background;
            return rt::materials::Color(1,1,1);
        }

        rt::materials::Color lighting{0, 0, 0};
        for (const auto& light : world.lights())
            lighting += light->illuminate(hit, world);

        Ray scattered;
        rt::materials::Color attenuation;

        if (!hit.material->scatter(r, hit, attenuation, scattered))
            return lighting * attenuation;

        return lighting * attenuation * this->getRayColor(scattered, depth + 1, world);
    }
}
