#pragma once

#include "IObject.hpp"

namespace rt::objects {
    class RotateY : public IObject {
    public:
        RotateY(std::shared_ptr<IObject> object, double angle);
        ~RotateY() = default;

        virtual bool hit(const rt::core::Ray& r, rt::maths::Interval ray_t, rt::core::Hit& rec) const override;
        virtual rt::maths::AABB boundingBox() const override;

    private:
        std::shared_ptr<IObject> _object;
        double _sin_theta;
        double _cos_theta;
        rt::maths::AABB _bbox;
    };
}
