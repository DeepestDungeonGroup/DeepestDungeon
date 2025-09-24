/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** Vector3.hpp
*/

#ifndef VECTOR3_HPP_
    #define VECTOR3_HPP_

    #include <cmath>
    #include <concepts>
    #include <iostream>

    #include "numeric.hpp"

template <numeric Type>
class Vector3 {
    public:
        Vector3() = default;
        Vector3(Type valx, Type valy, Type valz) : x(valx), y(valy), z(valz) {}
        ~Vector3() = default;

        Type length(void) const {
            return std::sqrt(x * x + y * y + z * z);
        }
        Type dot(const Vector3 &vect) const {
            if (vect.x == 0 && vect.y == 0 && vect.z == 0)
                return 1;
            return (this->x * vect.x + this->y * vect.y + this->z * vect.z);
        }
        Vector3& normalized() const {
            Type len = length();

            if (len == 0)
                return *this;
            return *this / len;
        }

        Vector3& operator+(const Vector3 &vect) const {
            return Vector3(x + vect.x, y + vect.y, z + vect.z);
        }
        void operator+=(const Vector3 &vect) {
            x += vect.x;
            y += vect.y;
            z += vect.z;
        }
        Vector3& operator-(const Vector3 &vect) const {
            return Vector3(x - vect.x, y - vect.y, z - vect.z);
        }
        void operator-=(const Vector3 &vect) {
            x -= vect.x;
            y -= vect.y;
            z -= vect.z;
        }
        Vector3& operator*(const Vector3 &vect) const {
            return Vector3(x * vect.x, y * vect.y, z * vect.z);
        }
        void operator*=(const Vector3 &vect) {
            x *= vect.x;
            y *= vect.y;
            z *= vect.z;
        }
       Vector3& operator/(const Vector3 &vect) const {
            return Vector3(x / vect.x, y / vect.y, z / vect.z);
        }
        void operator/=(const Vector3 &vect) {
            x /= vect.x;
            y /= vect.y;
            z /= vect.z;
        }
        Vector3& operator+(Type factor) const {
            return Vector3(x + factor, y + factor, z + factor);
        }
        void operator+=(Type factor) {
            x += factor;
            y += factor;
            z += factor;
        }
        Vector3& operator-(Type factor) const {
            return Vector3(x - factor, y - factor, z - factor);
        }
        void operator-=(Type factor) {
            x -= factor;
            y -= factor;
            z -= factor;
        }
        Vector3& operator*(Type factor) const {
            return Vector3(x * factor, y * factor, z * factor);
        }
        void operator*=(Type factor) {
            x *= factor;
            y *= factor;
            z *= factor;
        }
        Vector3& operator/(Type factor) const {
            return Vector3(x / factor, y / factor, z / factor);
        }
        void operator/=(Type factor) {
            x /= factor;
            y /= factor;
            z /= factor;
        }

        Type x = 0;
        Type y = 0;
        Type z = 0;
};

    using Vector3i = Vector3<int>;
    using Vector3u = Vector3<size_t>;
    using Vector3f = Vector3<float>;
    using Vector3d = Vector3<double>;
    using Vector38b = Vector3<u_int8_t>;

inline std::ostream& operator<<(std::ostream& os, const Vector3f& vector)
{
    return os << vector.x << " " << vector.y << " " << vector.z;
}

inline std::ostream& operator<<(std::ostream& os, const Vector3u& vector)
{
    return os << vector.x << " " << vector.y << " " << vector.z;
}

inline std::ostream& operator<<(std::ostream& os, const Vector3d& vector)
{
    return os << vector.x << " " << vector.y << " " << vector.z;
}

inline std::ostream& operator<<(std::ostream& os, const Vector38b& vector)
{
    return os << vector.x << " " << vector.y << " " << vector.z;
}

#endif
