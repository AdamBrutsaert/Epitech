#include "raytracer/objects/BVH.hpp"

#include <algorithm>

namespace rt::objects {
    BVH::BVH(Scene scene)
        : BVH(scene.objects(), 0, scene.objects().size())
    {
    }

    static bool BoxCompare(
        const std::shared_ptr<IObject> a,
        const std::shared_ptr<IObject> b,
        int axis
    )
    {
        auto aAxisInterval = a->boundingBox().axisInterval(axis);
        auto bAxisInterval = b->boundingBox().axisInterval(axis);
        return aAxisInterval.min < bAxisInterval.min;
    }

    static bool BoxXCompare(const std::shared_ptr<IObject> a, const std::shared_ptr<IObject> b)
    {
        return BoxCompare(a, b, 0);
    }

    static bool BoxYCompare(const std::shared_ptr<IObject> a, const std::shared_ptr<IObject> b)
    {
        return BoxCompare(a, b, 1);
    }

    static bool BoxZCompare(const std::shared_ptr<IObject> a, const std::shared_ptr<IObject> b)
    {
        return BoxCompare(a, b, 2);
    }

    BVH::BVH(std::vector<std::shared_ptr<IObject>>& objects, std::size_t start, std::size_t end)
    {
        this->_bbox = rt::maths::AABB::Empty;

        for (std::size_t i = start; i < end; i++)
            this->_bbox = rt::maths::AABB(this->_bbox, objects[i]->boundingBox());

        int axis = this->_bbox.longestAxis();

        auto comparator = (axis == 0) ? BoxXCompare
                        : (axis == 1) ? BoxYCompare
                        : BoxZCompare;

        std::size_t objectSpan = end - start;

        if (objectSpan == 1) {
            this->_left = objects[start];
            this->_right = objects[start];
        } else if (objectSpan == 2) {
            this->_left = objects[start];
            this->_right = objects[start + 1];
        } else {
            std::sort(objects.begin() + start, objects.begin() + end, comparator);

            auto mid = start + objectSpan / 2;
            this->_left = std::make_shared<BVH>(objects, start, mid);
            this->_right = std::make_shared<BVH>(objects, mid, end);
        }
    }

    bool BVH::hit(const rt::core::Ray& r, rt::maths::Interval ray_t, rt::core::Hit& rec) const
    {
        if (!this->_bbox.hit(r, ray_t))
            return false;

        bool hitLeft = _left->hit(r, ray_t, rec);
        bool hitRight = _right->hit(r, rt::maths::Interval(ray_t.min, hitLeft ? rec.t : ray_t.max), rec);

        return hitLeft || hitRight;
    }

    rt::maths::AABB BVH::boundingBox() const
    {
        return this->_bbox;
    }
}
