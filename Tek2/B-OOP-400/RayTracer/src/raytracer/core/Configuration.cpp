#include "raytracer/core/Configuration.hpp"

#include "raytracer/objects/Sphere.hpp"
#include "raytracer/objects/Plane.hpp"
#include "raytracer/objects/Cylinder.hpp"
#include "raytracer/objects/Cone.hpp"
#include "raytracer/objects/Translate.hpp"
#include "raytracer/objects/RotateY.hpp"
#include "raytracer/objects/BVH.hpp"

#include "raytracer/lights/Ambient.hpp"
#include "raytracer/lights/Directional.hpp"

#include "raytracer/materials/Flat.hpp"
#include "raytracer/materials/Lambertian.hpp"
#include "raytracer/materials/Metal.hpp"
#include "raytracer/materials/Dielectric.hpp"

namespace rt::core {
    void Configuration::load(const std::string& path)
    {
        this->_config.readFile(path.c_str());
    }

    // Camera
    static void ParseVector3(const libconfig::Setting& setting, rt::maths::Vector3& vector)
    {
        double x, y, z;

        setting.lookupValue("x", x);
        setting.lookupValue("y", y);
        setting.lookupValue("z", z);

        vector = rt::maths::Vector3(x, y, z);
    }

    static void ParseColor(const libconfig::Setting& setting, rt::materials::Color& vector)
    {
        double r, g, b;

        setting.lookupValue("r", r);
        setting.lookupValue("g", g);
        setting.lookupValue("b", b);

        vector = rt::materials::Color(r, g, b);
    }

    static void ParseCameraImage(CameraBuilder& builder, const Configuration& config)
    {
        try {
            const libconfig::Setting& image = config.get().lookup("image");

            int width;
            int height;
            rt::materials::Color background;
            std::string outputFile;

            image.lookupValue("width", width);
            image.lookupValue("height", height);
            ParseColor(image["background"], background);
            image.lookupValue("output", outputFile);

            if (width <= 0 || height <= 0)
                throw std::runtime_error("Invalid image width or height");

            if (outputFile.empty())
                throw std::runtime_error("Invalid image output");

            builder.withImageWidth(width);
            builder.withAspectRatio(static_cast<double>(width) / height);
            builder.withBackground(background);
            builder.withOutputFile(outputFile);

            std::clog << "[Camera] Image width: " << width << std::endl;
            std::clog << "[Camera] Aspect ratio: " << static_cast<double>(width) / height << std::endl;
            std::clog << "[Camera] Background: " << background.x << ", " << background.y << ", " << background.z << std::endl;
            std::clog << "[Camera] Output: " << outputFile << std::endl;
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid image configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid image configuration");
        }
    }

    static void ParseCameraRendering(CameraBuilder& builder, const Configuration& config)
    {
        try {
            const libconfig::Setting& rendering = config.get().lookup("rendering");

            int samplesPerPixel;
            int maxRecursion;
            int threadCount;
            int threadChunkSize;

            rendering.lookupValue("samples", samplesPerPixel);
            rendering.lookupValue("maxRecursion", maxRecursion);
            rendering.lookupValue("threadCount", threadCount);
            rendering.lookupValue("threadChunkSize", threadChunkSize);

            if (samplesPerPixel <= 0 || maxRecursion <= 0)
                throw std::runtime_error("Invalid rendering samples or maxDepth");

            builder.withSamplesPerPixel(samplesPerPixel);
            builder.withMaxDepth(maxRecursion);
            builder.withThreadCount(threadCount);
            builder.withThreadBlockSize(threadChunkSize);

            std::clog << "[Camera] Samples per pixel: " << samplesPerPixel << std::endl;
            std::clog << "[Camera] Max recursion: " << maxRecursion << std::endl;
            std::clog << "[Camera] Thread count: " << threadCount << std::endl;
            std::clog << "[Camera] Thread chunk size: " << threadChunkSize << std::endl;
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid rendering configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid rendering configuration");
        }
    }

    static void ParseCameraCamera(CameraBuilder& builder, const Configuration& config)
    {
        try {
            const libconfig::Setting& camera = config.get().lookup("camera");

            rt::maths::Point3 lookFrom;
            rt::maths::Point3 lookAt;
            rt::maths::Vector3 up;
            double verticalFov;
            double defocusAngle;
            double focusDistance;

            ParseVector3(camera["lookFrom"], lookFrom);
            ParseVector3(camera["lookAt"], lookAt);
            ParseVector3(camera["up"], up);
            camera.lookupValue("verticalFov", verticalFov);
            camera.lookupValue("defocusAngle", defocusAngle);
            camera.lookupValue("focusDistance", focusDistance);

            if (verticalFov <= 0)
                throw std::runtime_error("Invalid camera fov");

            if (lookFrom.x == lookAt.x && lookFrom.y == lookAt.y && lookFrom.z == lookAt.z)
                throw std::runtime_error("Invalid camera lookFrom and lookAt");

            if (up.x == 0 && up.y == 0 && up.z == 0)
                throw std::runtime_error("Invalid camera up");

            if (defocusAngle < 0 || defocusAngle > 1)
                throw std::runtime_error("Invalid camera defocusAngle");

            if (focusDistance < 0)
                throw std::runtime_error("Invalid camera focusDistance");

            builder.withLookFrom(lookFrom);
            builder.withLookAt(lookAt);
            builder.withUp(up);
            builder.withVerticalFov(verticalFov);
            builder.withDefocusAngle(defocusAngle);
            builder.withFocusDistance(focusDistance);

            std::clog << "[Camera] Look from: " << lookFrom.x << ", " << lookFrom.y << ", " << lookFrom.z << std::endl;
            std::clog << "[Camera] Look at: " << lookAt.x << ", " << lookAt.y << ", " << lookAt.z << std::endl;
            std::clog << "[Camera] Up: " << up.x << ", " << up.y << ", " << up.z << std::endl;
            std::clog << "[Camera] Vertical fov: " << verticalFov << std::endl;
            std::clog << "[Camera] Defocus angle: " << defocusAngle << std::endl;
            std::clog << "[Camera] Focus distance: " << focusDistance << std::endl;
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid camera configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid camera configuration");
        }
    }

    Camera SceneFactory::CreateCamera(const Configuration &config)
    {
        CameraBuilder builder;

        ParseCameraImage(builder, config);
        ParseCameraRendering(builder, config);
        ParseCameraCamera(builder, config);

        return builder.build();
    }

    static std::shared_ptr<rt::materials::IMaterial> ParseFlatMaterial(libconfig::Setting& material)
    {
        rt::materials::Color color;

        try {
            ParseColor(material["color"], color);
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid flat material configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid flat material configuration");
        }

        return std::make_shared<rt::materials::Flat>(color);
    }

    static std::shared_ptr<rt::materials::IMaterial> ParseLambertianMaterial(libconfig::Setting& material)
    {
        rt::materials::Color albedo;

        try {
            ParseColor(material["albedo"], albedo);
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid lambertian material configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid lambertian material configuration");
        }

        return std::make_shared<rt::materials::Lambertian>(albedo);
    }

    static std::shared_ptr<rt::materials::IMaterial> ParseMetalMaterial(libconfig::Setting& material)
    {
        rt::materials::Color albedo;
        double fuzz = 0.0;

        try {
            ParseColor(material["albedo"], albedo);
            material.lookupValue("fuzziness", fuzz);
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid metal material configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid metal material configuration");
        }

        return std::make_shared<rt::materials::Metal>(albedo, fuzz);
    }

    static std::shared_ptr<rt::materials::IMaterial> ParseDielectricMaterial(libconfig::Setting& material)
    {
        double refractionIndex = 0.0;

        try {
            material.lookupValue("refractionIndex", refractionIndex);
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid dielectric material configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid dielectric material configuration");
        }

        return std::make_shared<rt::materials::Dielectric>(refractionIndex);
    }

    static std::shared_ptr<rt::materials::IMaterial> ParseMaterial(libconfig::Setting& material)
    {
        std::string type;

        try {
            material.lookupValue("type", type);

            if (type == "flat") return ParseFlatMaterial(material);
            if (type == "lambertian") return ParseLambertianMaterial(material);
            if (type == "metal") return ParseMetalMaterial(material);
            if (type == "dielectric") return ParseDielectricMaterial(material);
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid material configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid material configuration");
        }
        throw std::runtime_error("Invalid material type");
    }

    static std::shared_ptr<rt::objects::IObject> ParseSphere(libconfig::Setting& sphere)
    {
        rt::maths::Point3 center;
        double radius = 0.0;
        std::shared_ptr<rt::materials::IMaterial> material;

        rt::maths::Vector3 translate;
        bool isTranslated = false;

        rt::maths::Vector3 rotate;
        bool isRotated = false;

        try {
            ParseVector3(sphere["center"], center);
            sphere.lookupValue("radius", radius);
            material = ParseMaterial(sphere["material"]);
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid sphere configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid sphere configuration");
        }

        try {
            ParseVector3(sphere["translate"], translate);
            isTranslated = true;
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid sphere translation configuration");
        }

        try {
            ParseVector3(sphere["rotate"], rotate);
            isRotated = true;
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid sphere rotation configuration");
        }

        std::clog << "[Scene] Sphere: Center = " << center.x << ", " << center.y << ", " << center.z
            << "; Radius = " << radius;

        if (isTranslated)
            std::clog << "; Translate = " << translate.x << ", " << translate.y << ", " << translate.z;

        if (isRotated)
            std::clog << "; Rotate = " << rotate.x << ", " << rotate.y << ", " << rotate.z;

        std::clog << std::endl;

        std::shared_ptr<rt::objects::IObject> object = std::make_shared<rt::objects::Sphere>(center, radius, material);

        if (isRotated)
            object = std::make_shared<rt::objects::RotateY>(object, rotate.y);

        if (isTranslated)
            object = std::make_shared<rt::objects::Translate>(object, translate);

        return object;
    }

    static void ParseSpheres(rt::objects::Scene& scene, libconfig::Setting& objects)
    {
        try {
            libconfig::Setting& spheres = objects.lookup("spheres");
            for (int i = 0; i < spheres.getLength(); i++)
                scene.add(ParseSphere(spheres[i]));
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            // Ignore
        }
    }

    static std::shared_ptr<rt::objects::IObject> ParsePlane(libconfig::Setting& plane)
    {
        rt::maths::Point3 position;
        rt::maths::Vector3 normal;
        std::shared_ptr<rt::materials::IMaterial> material;

        rt::maths::Vector3 translate;
        bool isTranslated = false;

         rt::maths::Vector3 rotate;
        bool isRotated = false;

        try {
            ParseVector3(plane["position"], position);
            ParseVector3(plane["normal"], normal);
            material = ParseMaterial(plane["material"]);
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid plane configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid plane configuration");
        }

        try {
            ParseVector3(plane["translate"], translate);
            isTranslated = true;
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid plane translation configuration");
        }

        try {
            ParseVector3(plane["rotate"], rotate);
            isRotated = true;
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid plane rotation configuration");
        }

        std::clog << "[Scene] Plane: Position = " << position.x << ", " << position.y << ", " << position.z
            << "; Normal = " << normal.x << ", " << normal.y << ", " << normal.z;

        if (isTranslated)
            std::clog << "; Translate = " << translate.x << ", " << translate.y << ", " << translate.z;

        if (isRotated)
            std::clog << "; Rotate = " << rotate.x << ", " << rotate.y << ", " << rotate.z;

        std::clog << std::endl;

        std::shared_ptr<rt::objects::IObject> object = std::make_shared<rt::objects::Plane>(normal, position, material);

        if (isRotated)
            object = std::make_shared<rt::objects::RotateY>(object, rotate.y);

        if (isTranslated)
            object = std::make_shared<rt::objects::Translate>(object, translate);

        return object;
    }

    static void ParsePlanes(rt::objects::Scene& scene, libconfig::Setting& objects)
    {
        try {
            libconfig::Setting& planes = objects.lookup("planes");
            for (int i = 0; i < planes.getLength(); i++)
                scene.add(ParsePlane(planes[i]));
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            // Ignore
        }
    }

    static std::shared_ptr<rt::objects::IObject> ParseCylinder(libconfig::Setting& cylinder)
    {
        rt::maths::Point3 position;
        double radius = 0.0;
        std::shared_ptr<rt::materials::IMaterial> material;

        rt::maths::Vector3 translate;
        bool isTranslated = false;

        rt::maths::Vector3 rotate;
        bool isRotated = false;

        try {
            ParseVector3(cylinder["position"], position);
            cylinder.lookupValue("radius", radius);
            material = ParseMaterial(cylinder["material"]);
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid plane configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid plane configuration");
        }

        try {
            ParseVector3(cylinder["translate"], translate);
            isTranslated = true;
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid plane translation configuration");
        }

        try {
            ParseVector3(cylinder["rotate"], rotate);
            isRotated = true;
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid plane rotation configuration");
        }

        std::clog << "[Scene] Cylinder: Position = " << position.x << ", " << position.y << ", " << position.z
            << "; Radius = " << radius;

        if (isTranslated)
            std::clog << "; Translate = " << translate.x << ", " << translate.y << ", " << translate.z;

        if (isRotated)
            std::clog << "; Rotate = " << rotate.x << ", " << rotate.y << ", " << rotate.z;

        std::clog << std::endl;

        std::shared_ptr<rt::objects::IObject> object = std::make_shared<rt::objects::Cylinder>(position, radius, material);

        if (isRotated)
            object = std::make_shared<rt::objects::RotateY>(object, rotate.y);

        if (isTranslated)
            object = std::make_shared<rt::objects::Translate>(object, translate);

        return object;
    }

    static void ParseCylinders(rt::objects::Scene& scene, libconfig::Setting& objects)
    {
        try {
            libconfig::Setting& cylinders = objects.lookup("cylinders");
            for (int i = 0; i < cylinders.getLength(); i++)
                scene.add(ParseCylinder(cylinders[i]));
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            // Ignore
        }
    }

    static std::shared_ptr<rt::objects::IObject> ParseCone(libconfig::Setting& cone)
    {
        rt::maths::Point3 position;
        double angle = 0.0;
        std::shared_ptr<rt::materials::IMaterial> material;

        rt::maths::Vector3 translate;
        bool isTranslated = false;

        rt::maths::Vector3 rotate;
        bool isRotated = false;

        try {
            ParseVector3(cone["apex"], position);
            cone.lookupValue("angle", angle);
            material = ParseMaterial(cone["material"]);
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid plane configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid plane configuration");
        }

        try {
            ParseVector3(cone["translate"], translate);
            isTranslated = true;
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid plane translation configuration");
        }

        try {
            ParseVector3(cone["rotate"], rotate);
            isRotated = true;
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid plane rotation configuration");
        }

        std::clog << "[Scene] Cone: Apex = " << position.x << ", " << position.y << ", " << position.z
            << "; Angle = " << angle;

        if (isTranslated)
            std::clog << "; Translate = " << translate.x << ", " << translate.y << ", " << translate.z;

        if (isRotated)
            std::clog << "; Rotate = " << rotate.x << ", " << rotate.y << ", " << rotate.z;

        std::clog << std::endl;

        std::shared_ptr<rt::objects::IObject> object = std::make_shared<rt::objects::Cone>(position, angle, material);

        if (isRotated)
            object = std::make_shared<rt::objects::RotateY>(object, rotate.y);

        if (isTranslated)
            object = std::make_shared<rt::objects::Translate>(object, translate);

        return object;
    }

    static void ParseCones(rt::objects::Scene& scene, libconfig::Setting& objects)
    {
        try {
            libconfig::Setting& cones = objects.lookup("cones");
            for (int i = 0; i < cones.getLength(); i++)
                scene.add(ParseCone(cones[i]));
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            // Ignore
        }
    }

    static std::shared_ptr<rt::lights::Ambient> ParseAmbient(libconfig::Setting& ambient)
    {
        rt::materials::Color color;
        double intensity = 1.0;

        try {
            ParseColor(ambient["color"], color);
            ambient.lookupValue("intensity", intensity);
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid ambient configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid ambient configuration");
        }

        std::clog << "[Scene] Ambient: Color = " << color.x << ", " << color.y << ", " << color.z
            << "; Intensity = " << intensity << std::endl;

        return std::make_shared<rt::lights::Ambient>(color, intensity);
    }

    static void ParseAmbients(rt::objects::Scene& scene, libconfig::Setting& lights)
    {
        try {
            libconfig::Setting& ambients = lights.lookup("ambients");
            for (int i = 0; i < ambients.getLength(); i++)
                scene.add(ParseAmbient(ambients[i]));
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            // Ignore
        }
    }

    static std::shared_ptr<rt::lights::Directional> ParseDirectional(libconfig::Setting& directional)
    {
        rt::maths::Vector3 direction;
        rt::materials::Color color;
        double intensity;

        try {
            ParseVector3(directional["direction"], direction);
            ParseColor(directional["color"], color);
            directional.lookupValue("intensity", intensity);
        } catch (const libconfig::SettingNotFoundException& e) {
            throw std::runtime_error("Invalid directional configuration");
        } catch (const libconfig::SettingTypeException& e) {
            throw std::runtime_error("Invalid directional configuration");
        }

        std::clog << "[Scene] Directional: Direction = " << direction.x << ", " << direction.y << ", " << direction.z
            << "; Color = " << color.x << ", " << color.y << ", " << color.z
            << "; Intensity = " << intensity << std::endl;

        return std::make_shared<rt::lights::Directional>(direction, color, intensity);
    }

    static void ParseDirectionals(rt::objects::Scene& scene, libconfig::Setting& lights)
    {
        try {
            libconfig::Setting& directionals = lights.lookup("directionals");
            for (int i = 0; i < directionals.getLength(); i++)
                scene.add(ParseDirectional(directionals[i]));
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            // Ignore
        }
    }

    rt::objects::Scene SceneFactory::CreateScene(const Configuration& config)
    {
        rt::objects::Scene scene;

        try {
            libconfig::Setting& objects = config.get().lookup("objects");
            ParseSpheres(scene, objects);
            ParsePlanes(scene, objects);
            ParseCylinders(scene, objects);
            ParseCones(scene, objects);
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            // Ignore
        }

        scene = rt::objects::Scene(std::make_shared<rt::objects::BVH>(scene));

        //Light
        try {
            libconfig::Setting& lights = config.get().lookup("lights");
            ParseAmbients(scene, lights);
            ParseDirectionals(scene, lights);
        } catch (const libconfig::SettingNotFoundException& e) {
            // Ignore
        } catch (const libconfig::SettingTypeException& e) {
            // Ignore
        }

        return scene;
    }
}
