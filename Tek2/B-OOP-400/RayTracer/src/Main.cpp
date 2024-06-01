#include "raytracer/core/Camera.hpp"
#include "raytracer/core/Configuration.hpp"

#include "raytracer/objects/Scene.hpp"
#include "raytracer/objects/BVH.hpp"
#include "raytracer/objects/Sphere.hpp"
#include "raytracer/objects/Plane.hpp"
#include "raytracer/objects/Disc.hpp"
#include "raytracer/objects/Cylinder.hpp"
#include "raytracer/objects/Cone.hpp"

#include "raytracer/materials/Flat.hpp"
#include "raytracer/materials/Lambertian.hpp"
#include "raytracer/materials/Dielectric.hpp"
#include "raytracer/materials/Metal.hpp"

#include "raytracer/lights/Ambient.hpp"
#include "raytracer/lights/Directional.hpp"

using namespace rt::core;
using namespace rt::materials;
using namespace rt::maths;
using namespace rt::objects;
using namespace rt::lights;

Scene CreateComplexScene()
{
    Scene world;

    auto groundMaterial = std::make_shared<Lambertian>(Color(0.5, 0.5, 0.5));
    world.add(std::make_shared<Sphere>(Point3(0, -1000, 0), 1000, groundMaterial));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choseMaterial = RandomDouble();
            Point3 center(a + 0.9 * RandomDouble(), 0.2, b + 0.9 * RandomDouble());

            if ((center - Point3(4, 0.2, 0)).length() > 0.9) {
                std::shared_ptr<IMaterial> sphereMaterial;

                if (choseMaterial < 0.8) {
                    auto albedo = Color::Random() * Color::Random();
                    sphereMaterial = std::make_shared<Lambertian>(albedo);
                    world.add(std::make_shared<Sphere>(center, 0.2, sphereMaterial));
                } else if (choseMaterial < 0.95) {
                    auto albedo = Color::Random(0.5, 1);
                    auto fuzz = RandomDouble(0, 0.5);
                    sphereMaterial = std::make_shared<Metal>(albedo, fuzz);
                    world.add(std::make_shared<Sphere>(center, 0.2, sphereMaterial));
                } else {
                    sphereMaterial = std::make_shared<Dielectric>(1.5);
                    world.add(std::make_shared<Sphere>(center, 0.2, sphereMaterial));
                }
            }
        }
    }

    auto material1 = std::make_shared<Dielectric>(1.5);
    world.add(std::make_shared<Sphere>(Point3(0, 1, 0), 1.0, material1));

    auto material2 = std::make_shared<Lambertian>(Color(0.4, 0.2, 0.1));
    world.add(std::make_shared<Sphere>(Point3(-4, 1, 0), 1.0, material2));

    auto material3 = std::make_shared<Metal>(Color(0.7, 0.6, 0.5), 0.0);
    world.add(std::make_shared<Sphere>(Point3(4, 1, 0), 1.0, material3));

    world = Scene(std::make_shared<BVH>(world));
    world.add(std::make_shared<Ambient>(Color(1.0, 1.0, 1.0), 1.0));

    return world;
}

Scene CreateSimpleScene()
{
    Scene world;

    // Sphere
    auto sphereMaterial = std::make_shared<Flat>(Color(1.0, 0.0, 0.0));
    world.add(std::make_shared<Sphere>(Point3(0, 0, -1), 0.5, sphereMaterial));

    auto planeMaterial = std::make_shared<Lambertian>(Color(0.5, 0.5, 0.5));
    world.add(std::make_shared<Plane>(Vector3(0, 1, 0), Vector3(0, -1.0, 0), planeMaterial));

    world = Scene(std::make_shared<BVH>(world));

    // Lights
    world.add(std::make_shared<Directional>(Vector3(0, -1, -1), Color(1.0, 1.0, 1.0), 1.0));
    world.add(std::make_shared<Ambient>(Color(1.0, 1.0, 1.0), 0.001));

    return world;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <config file>" << std::endl;
        return 84;
    }

    try {
        Configuration config;
        config.load(argv[1]);

        Camera camera = SceneFactory::CreateCamera(config);
        Scene scene = SceneFactory::CreateScene(config);
        camera.render(scene);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    return 0;
}
