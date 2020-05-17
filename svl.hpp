#include <cmath>

namespace svl
{
    template <class BaseType>
    class Vector2 {
        public:
            BaseType x, y;
        
        public:
            template <typename Scalar>
            Vector2 operator*
            (Scalar scalar)
            {
                return Vector2{x * scalar,
                               y * scalar};
            }

            template <typename Scalar>
            void operator*=
            (Scalar scalar)
            {
                x *= scalar;
                y *= scalar;
            }

            template <typename Scalar>
            Vector2 operator/
            (Scalar scalar)
            {
                return Vector2{x / scalar,
                               y / scalar};
            }

            template <typename Scalar>
            void operator/=
            (Scalar scalar)
            {
                x /= scalar;
                y /= scalar;
            }

            Vector2 operator+
            (Vector2& vector)
            {
                return Vector2{x + vector.x,
                               y + vector.y};
            }

            void operator+=
            (Vector2& vector)
            {
                x += vector.x;
                y += vector.y;
            }

            Vector2 operator-
            (Vector2& vector)
            {
                return Vector2{x - vector.x,
                               y - vector.y};
            }

            void operator-=
            (Vector2& vector)
            {
                x -= vector.x;
                y -= vector.y;
            }

            Vector2 operator=
            (const Vector2& vector)
            {
                return Vector2{ vector.x, vector.y };
            }

            float magnitude() {
                return std::sqrt(
                       std::pow(x, 2)
                       +
                       std::pow(y, 2)
                       );
            }

            Vector2 normalize() {
                float mag = magnitude();

                x /= mag;
                y /= mag;

                return Vector2{ x, y };
            }

            float dotProduct
            (Vector2& vector) {
                return (x * vector.x) +
                       (y * vector.y);
            }
    };

    typedef Vector2<double>       Vector2d;
    typedef Vector2<float>        Vector2f;
    typedef Vector2<int>          Vector2i;
    typedef Vector2<unsigned int> Vector2u;
}