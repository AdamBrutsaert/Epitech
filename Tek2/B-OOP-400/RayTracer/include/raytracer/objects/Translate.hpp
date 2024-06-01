#pragma once

#include "IObject.hpp"

namespace rt::objects {
    class Translate : public IObject {
    public:
        Translate(std::shared_ptr<IObject> object, const rt::maths::Vector3& offset);
        ~Translate() = default;

        virtual bool hit(const rt::core::Ray& r, rt::maths::Interval ray_t, rt::core::Hit& rec) const override;
        virtual rt::maths::AABB boundingBox() const override;

    private:
        std::shared_ptr<IObject> _object;
        rt::maths::Vector3 _offset;
        rt::maths::AABB _bbox;
    };
}
