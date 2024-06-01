#pragma once

#include <string>
#include <libconfig.h++>

#include "Camera.hpp"
#include "raytracer/objects/Scene.hpp"

namespace rt::core {
    class Configuration {
    public:
        Configuration() = default;
        Configuration(const Configuration&) = delete;
        Configuration(Configuration&&) = delete;
        ~Configuration() = default;

        Configuration& operator=(const Configuration&) = delete;
        Configuration& operator=(Configuration&&) = delete;

        /// Loads the configuration from the specified path
        void load(const std::string& path);

        /// Returns the configuration
        inline const libconfig::Config& get() const { return this->_config; }

    private:
        libconfig::Config _config;
    };

    class SceneFactory {
    public:
        static Camera CreateCamera(const Configuration& config);
        static rt::objects::Scene CreateScene(const Configuration& config);
    };
}
