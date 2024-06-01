#pragma once

#include "IObject.hpp"
#include "raytracer/lights/ILight.hpp"

#include <vector>

namespace rt::objects {
    class Scene : public IObject {
    public:
        Scene() = default;
        Scene(std::shared_ptr<IObject> object);

        void add(std::shared_ptr<IObject> object);
        void add(std::shared_ptr<rt::lights::ILight> light);

        virtual bool hit(const rt::core::Ray& r, rt::maths::Interval ray_t, rt::core::Hit& rec) const override;
        virtual rt::maths::AABB boundingBox() const override;

        inline std::vector<std::shared_ptr<IObject>>& objects() { return this->_objects; }
        inline const std::vector<std::shared_ptr<rt::lights::ILight>>& lights() const { return this->_lights; }

    private:
        std::vector<std::shared_ptr<IObject>> _objects;
        std::vector<std::shared_ptr<rt::lights::ILight>> _lights;
        rt::maths::AABB _bbox;
    };
}
