#include "raytracer/objects/Translate.hpp"

namespace rt::objects {
    Translate::Translate(std::shared_ptr<IObject> object, const rt::maths::Vector3& offset)
        : _object(object), _offset(offset), _bbox(object->boundingBox() + offset)
    {
    }

    bool Translate::hit(const rt::core::Ray& r, rt::maths::Interval ray_t, rt::core::Hit& rec) const
    {
        rt::core::Ray offsetRay(r.origin - this->_offset, r.direction);

        if (!this->_object->hit(offsetRay, ray_t, rec))
            return false;

        rec.point += this->_offset;
        return true;
    }

    rt::maths::AABB Translate::boundingBox() const
    {
        return this->_bbox;
    }
}
