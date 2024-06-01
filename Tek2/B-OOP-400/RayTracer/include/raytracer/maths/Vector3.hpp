#pragma once

#include "Utils.hpp"

namespace rt::maths {
    class Vector3 {
    public:
        double x;
        double y;
        double z;

    public:
        Vector3()
            : x{0}, y{0}, z{0}
        {
        }

        Vector3(double x, double y, double z)
            : x{x}, y{y}, z{z}
        {
        }

        inline double operator[](int i) const
        {
            switch(i) {
                case 1: return y;
                case 2: return z;
                default: return x;
            }
        }

        inline double& operator[](int i)
        {
            switch(i) {
                case 1: return y;
                case 2: return z;
                default: return x;
            }
        }

        inline Vector3 operator-() const
        {
            return Vector3(-x, -y, -z);
        }

        inline Vector3& operator+=(const Vector3& v)
        {
            this->x += v.x;
            this->y += v.y;
            this->z += v.z;
            return *this;
        }

        inline Vector3& operator*=(double t)
        {
            this->x *= t;
            this->y *= t;
            this->z *= t;
            return *this;
        }

        inline Vector3& operator/=(double t)
        {
            return *this *= 1/t;
        }

        inline double length() const
        {
            return std::sqrt(this->lengthSquared());
        }

        inline double lengthSquared() const
        {
            return this->x * this->x + this->y * this->y + this->z * this->z;
        }

        inline bool nearZero() const
        {
            constexpr auto threshold = 1e-8;

            return std::abs(this->x) < threshold
                && std::abs(this->y) < threshold
                && std::abs(this->z) < threshold;
        }

        static Vector3 Random() {
            return Vector3(RandomDouble(), RandomDouble(), RandomDouble());
        }

        static Vector3 Random(double min, double max) {
            return Vector3(RandomDouble(min,max), RandomDouble(min,max), RandomDouble(min,max));
        }

        static inline Vector3 RandomInUnitDisk()
        {
            auto point = Vector3(RandomDouble(-1, 1), RandomDouble(-1, 1), 0);

            while (point.lengthSquared() >= 1)
                point = Vector3(RandomDouble(-1, 1), RandomDouble(-1, 1), 0);

            return point;
        }

        static inline Vector3 RandomInUnitSphere()
        {
            auto point = Vector3::Random(-1, 1);

            while (point.lengthSquared() >= 1)
                point = Vector3::Random(-1, 1);

            return point;
        }

        static inline Vector3 RandomUnit();

        static inline Vector3 RandomOnHemisphere(const Vector3& normal);

        static inline Vector3 random_on_hemisphere(const Vector3& normal);
    };

    using Point3 = Vector3;

    inline Vector3 operator+(const Vector3& u, const Vector3& v)
    {
        return Vector3(u.x + v.x, u.y + v.y, u.z + v.z);
    }

    inline Vector3 operator-(const Vector3& u, const Vector3& v)
    {
        return Vector3(u.x - v.x, u.y - v.y, u.z - v.z);
    }

    inline Vector3 operator*(const Vector3& u, const Vector3& v)
    {
        return Vector3(u.x * v.x, u.y * v.y, u.z * v.z);
    }

    inline Vector3 operator*(double t, const Vector3& v)
    {
        return Vector3(t * v.x, t * v.y, t * v.z);
    }

    inline Vector3 operator*(const Vector3& v, double t)
    {
        return t * v;
    }

    inline Vector3 operator/(const Vector3& v, double t)
    {
        return (1 / t) * v;
    }

    inline double dot(const Vector3& u, const Vector3& v)
    {
        return u.x * v.x + u.y * v.y + u.z * v.z;
    }

    inline Vector3 cross(const Vector3& u, const Vector3& v)
    {
        return Vector3(u.y * v.z - u.z * v.y,
                    u.z * v.x - u.x * v.z,
                    u.x * v.y - u.y * v.x);
    }

    inline Vector3 normalize(const Vector3& v)
    {
        return v / v.length();
    }

    inline Vector3 reflect(const Vector3& v, const Vector3& n)
    {
        return v - 2*dot(v,n)*n;
    }

    inline Vector3 refract(const Vector3& uv, const Vector3& n, double etai_over_etat)
    {
        auto cos_theta = fmin(dot(-uv, n), 1.0);
        Vector3 r_out_perp =  etai_over_etat * (uv + cos_theta*n);
        Vector3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.lengthSquared())) * n;
        return r_out_perp + r_out_parallel;
    }

    inline Vector3 Vector3::RandomUnit()
    {
        return normalize(Vector3::RandomInUnitSphere());
    }

    inline Vector3 RandomOnHemisphere(const Vector3& normal)
    {
        Vector3 onUnitSphere = Vector3::RandomUnit();

        if (dot(onUnitSphere, normal) > 0.0)
            return onUnitSphere;
        return -onUnitSphere;
    }
}
