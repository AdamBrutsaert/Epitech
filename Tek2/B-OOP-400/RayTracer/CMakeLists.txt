cmake_minimum_required(VERSION 3.22)

project(RayTracer,
    VERSION 1.0
    DESCRIPTION "A simple RayTracer running on CPU"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(RayTracer)

set(SOURCES
    src/Main.cpp
    src/raytracer/core/Camera.cpp
    src/raytracer/core/Configuration.cpp
    src/raytracer/core/Display.cpp
    src/raytracer/maths/Interval.cpp
    src/raytracer/maths/AABB.cpp
    src/raytracer/maths/Utils.cpp
    src/raytracer/materials/Color.cpp
    src/raytracer/materials/Flat.cpp
    src/raytracer/materials/Lambertian.cpp
    src/raytracer/materials/Metal.cpp
    src/raytracer/materials/Dielectric.cpp
    src/raytracer/objects/Scene.cpp
    src/raytracer/objects/BVH.cpp
    src/raytracer/objects/Sphere.cpp
    src/raytracer/objects/Plane.cpp
    src/raytracer/objects/Disc.cpp
    src/raytracer/objects/Cylinder.cpp
    src/raytracer/objects/Cone.cpp
    src/raytracer/objects/Translate.cpp
    src/raytracer/objects/RotateY.cpp
    src/raytracer/lights/Ambient.cpp
    src/raytracer/lights/Directional.cpp
)

# Outputing the binary in the root directory
set_target_properties(RayTracer
    PROPERTIES
    OUTPUT_NAME "raytracer"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

target_include_directories(RayTracer PRIVATE include)
target_sources(RayTracer PRIVATE ${SOURCES})

target_link_libraries(RayTracer PRIVATE config++)
target_link_libraries(RayTracer PRIVATE sfml-graphics sfml-window sfml-system)

set_property(TARGET RayTracer PROPERTY CXX_STANDARD 20)
target_compile_options(RayTracer PRIVATE -Wall -Wextra)
target_compile_options(RayTracer PRIVATE $<$<CONFIG:DEBUG>:-O0 -g>)
target_compile_options(RayTracer PRIVATE $<$<CONFIG:RELEASE>:-O3>)
