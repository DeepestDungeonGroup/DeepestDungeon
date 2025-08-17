/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** Vector2.hpp
*/

#ifndef VECTOR2_HPP_
    #define VECTOR2_HPP_

    #include <cmath>
    #include <concepts>
    #include <iostream>

    #include "numeric.hpp"

template <numeric Type>
class Vector2 {
    public:
        Vector2() = default;
        Vector2(Type valx, Type valy) : x(valx), y(valy) {}
        ~Vector2() = default;

        Type length(void) const {
            return std::sqrt(x * x + y * y);
        }
        Type dot(const Vector2 &vect) const {
            if (vect.x == 0 && vect.y == 0)
                return 1;
            return (this->x * vect.x + this->y * vect.y);
        }
        Vector2& normalized() const {
            Type len = length();

            if (len == 0)
                return *this;
            return *this / len;
        }

        Vector2& operator+(const Vector2 &vect) const {
            return Vector2(x + vect.x, y + vect.y);
        }
        void operator+=(const Vector2 &vect) {
            x += vect.x;
            y += vect.y;
        }
        Vector2& operator-(const Vector2 &vect) const {
            return Vector2(x - vect.x, y - vect.y);
        }
        void operator-=(const Vector2 &vect) {
            x -= vect.x;
            y -= vect.y;
        }
        Vector2& operator*(const Vector2 &vect) const {
            return Vector2(x * vect.x, y * vect.y);
        }
        void operator*=(const Vector2 &vect) {
            x *= vect.x;
            y *= vect.y;
        }
       Vector2& operator/(const Vector2 &vect) const {
            return Vector2(x / vect.x, y / vect.y);
        }
        void operator/=(const Vector2 &vect) {
            x /= vect.x;
            y /= vect.y;
        }
        Vector2& operator+(Type factor) const {
            return Vector2(x + factor, y + factor);
        }
        void operator+=(Type factor) {
            x += factor;
            y += factor;
        }
        Vector2& operator-(Type factor) const {
            return Vector2(x - factor, y - factor);
        }
        void operator-=(Type factor) {
            x -= factor;
            y -= factor;
        }
        Vector2& operator*(Type factor) const {
            return Vector2(x * factor, y * factor);
        }
        void operator*=(Type factor) {
            x *= factor;
            y *= factor;
        }
        Vector2& operator/(Type factor) const {
            return Vector2(x / factor, y / factor);
        }
        void operator/=(Type factor) {
            x /= factor;
            y /= factor;
        }

        Type x = 0;
        Type y = 0;
};

    using Vector2i = Vector2<int>;
    using Vector2u = Vector2<size_t>;
    using Vector2f = Vector2<float>;
    using Vector2d = Vector2<double>;
    using Vector28b = Vector2<u_int8_t>;

inline std::ostream& operator<<(std::ostream& os, const Vector2f& vector)
{
    return os << vector.x << " " << vector.y;
}

inline std::ostream& operator<<(std::ostream& os, const Vector2u& vector)
{
    return os << vector.x << " " << vector.y;
}

inline std::ostream& operator<<(std::ostream& os, const Vector2d& vector)
{
    return os << vector.x << " " << vector.y;
}

inline std::ostream& operator<<(std::ostream& os, const Vector28b& vector)
{
    return os << vector.x << " " << vector.y;
}

#endif
