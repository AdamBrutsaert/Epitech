#pragma once

#include "raytracer/objects/Scene.hpp"
#include "raytracer/materials/Color.hpp"

#include <mutex>
#include <deque>
#include <fstream>

namespace rt::core {
    struct Chunk {
        std::size_t x, y;
        std::size_t width, height;
    };

    class Camera {
    public:
        Camera(
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
        );

        void render(const rt::objects::Scene& world);

    private:
        // Image settings
        double _aspectRatio;
        std::size_t _imageWidth;
        std::size_t _imageHeight;

        // Ray settings
        std::size_t _samplesPerPixel;
        double _sampleScale;
        std::size_t _maxDepth;

        // Camera settings
        rt::maths::Vector3 _imagePlaneCenter;
        rt::maths::Vector3 _imagePlanePixelTopLeft;
        rt::maths::Vector3 _imagePlanePixelHorizontal;
        rt::maths::Vector3 _imagePlanePixelVertical;

        // Defocus settings
        double _defocusAngle;
        rt::maths::Vector3 _defocusDiskHorizontal;
        rt::maths::Vector3 _defocusDiskVertical;

        // Multithreading settings
        std::size_t _threadCount;
        std::size_t _threadBlockSize;

        // Lighting
        rt::materials::Color _background;

        // Output
        std::ofstream _outputFile;

    private:
        void renderThread(
            const rt::objects::Scene& world,
            std::vector<rt::materials::Color>& pixels,
            std::deque<Chunk>& chunksQueue,
            std::mutex& chunksQueueMutex
        );

        Ray getRay(std::size_t i, std::size_t j) const;
        rt::materials::Color getRayColor(
            const Ray& r,
            std::size_t depth,
            const rt::objects::Scene& world
        ) const;
    };

    class CameraBuilder {
    public:
        CameraBuilder() = default;
        CameraBuilder(const CameraBuilder&) = default;
        CameraBuilder(CameraBuilder&&) = default;
        ~CameraBuilder() = default;

        CameraBuilder& operator=(const CameraBuilder&) = default;
        CameraBuilder& operator=(CameraBuilder&&) = default;

        inline CameraBuilder& withAspectRatio(double aspectRatio)
        {
            this->_aspectRatio = aspectRatio;
            return *this;
        }

        inline CameraBuilder& withImageWidth(std::size_t imageWidth)
        {
            this->_imageWidth = imageWidth;
            return *this;
        }

        inline CameraBuilder& withSamplesPerPixel(std::size_t samplesPerPixel)
        {
            this->_samplesPerPixel = samplesPerPixel;
            return *this;
        }

        inline CameraBuilder& withMaxDepth(std::size_t maxDepth)
        {
            this->_maxDepth = maxDepth;
            return *this;
        }

        inline CameraBuilder& withVerticalFov(double verticalFov)
        {
            this->_verticalFov = verticalFov;
            return *this;
        }

        inline CameraBuilder& withLookFrom(const rt::maths::Point3& lookFrom)
        {
            this->_lookFrom = lookFrom;
            return *this;
        }

        inline CameraBuilder& withLookAt(const rt::maths::Point3& lookAt)
        {
            this->_lookAt = lookAt;
            return *this;
        }

        inline CameraBuilder& withUp(const rt::maths::Vector3& up)
        {
            this->_up = up;
            return *this;
        }

        inline CameraBuilder& withDefocusAngle(double defocusAngle)
        {
            this->_defocusAngle = defocusAngle;
            return *this;
        }

        inline CameraBuilder& withFocusDistance(double focusDistance)
        {
            this->_focusDistance = focusDistance;
            return *this;
        }

        inline CameraBuilder& withThreadCount(std::size_t threadCount)
        {
            this->_threadCount = threadCount;
            return *this;
        }

        inline CameraBuilder& withThreadBlockSize(std::size_t threadBlockSize)
        {
            this->_threadBlockSize = threadBlockSize;
            return *this;
        }

        inline CameraBuilder& withBackground(const rt::materials::Color& background)
        {
            this->_background = background;
            return *this;
        }

        inline CameraBuilder& withOutputFile(const std::string& outputFile)
        {
            this->_outputFile = outputFile;
            return *this;
        }

        inline Camera build()
        {
            return Camera(
                this->_aspectRatio,
                this->_imageWidth,

                this->_samplesPerPixel,
                this->_maxDepth,

                this->_verticalFov,
                this->_lookFrom,
                this->_lookAt,
                this->_up,

                this->_defocusAngle,
                this->_focusDistance,

                this->_threadCount,
                this->_threadBlockSize,

                this->_background,

                this->_outputFile
            );
        }

    private:
        // Image settings
        double _aspectRatio = 1.0;
        std::size_t _imageWidth = 100;

        // Ray settings
        std::size_t _samplesPerPixel = 10;
        std::size_t _maxDepth = 10;

        // Camera settings
        double _verticalFov = 90;
        rt::maths::Point3 _lookFrom = rt::maths::Point3(0,0,0);
        rt::maths::Point3 _lookAt = rt::maths::Point3(0,0,-1);
        rt::maths::Vector3 _up = rt::maths::Vector3(0,1,0);

        // Defocus settings
        double _defocusAngle = 0;
        double _focusDistance = 10;

        // Multithreading settings
        std::size_t _threadCount = 1;
        std::size_t _threadBlockSize = 50;

        // Lighting
        rt::materials::Color _background = rt::materials::Color(0,0,0);

        // Output
        std::string _outputFile = "output.ppm";
    };
}
