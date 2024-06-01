#pragma once

#include "Scene.hpp"

namespace rt::objects {
    class BVH : public IObject {
    public:
        BVH(Scene scene);
        BVH(std::vector<std::shared_ptr<IObject>>& objects, std::size_t start, std::size_t end);
        ~BVH() = default;

        virtual bool hit(const rt::core::Ray& r, rt::maths::Interval ray_t, rt::core::Hit& rec) const override;
        virtual rt::maths::AABB boundingBox() const override;

    private:
        std::shared_ptr<IObject> _left;
        std::shared_ptr<IObject> _right;
        rt::maths::AABB _bbox;
    };
}
