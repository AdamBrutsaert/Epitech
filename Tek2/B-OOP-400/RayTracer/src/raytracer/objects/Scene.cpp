#include "raytracer/objects/Scene.hpp"

namespace rt::objects {
    Scene::Scene(std::shared_ptr<IObject> object)
    {
        this->add(object);
    }

    void Scene::add(std::shared_ptr<IObject> object)
    {
        this->_objects.push_back(object);
        this->_bbox = rt::maths::AABB(this->_bbox, object->boundingBox());
    }

    void Scene::add(std::shared_ptr<rt::lights::ILight> light)
    {
        this->_lights.push_back(light);
    }

    bool Scene::hit(const rt::core::Ray& r, rt::maths::Interval ray_t, rt::core::Hit& rec) const
    {
        rt::core::Hit hit;
        bool hasHit = false;
        auto closest = ray_t.max;

        for (const auto& object : _objects) {
            if (object->hit(r, rt::maths::Interval(ray_t.min, closest), hit)) {
                hasHit = true;
                closest = hit.t;
                rec = hit;
            }
        }

        return hasHit;
    }

    rt::maths::AABB Scene::boundingBox() const
    {
        return this->_bbox;
    }
}
