#include <cmath>

namespace svl {
	class Vector {
		public:
			float x, y;

			Vector(float x, float y) : x(x), y(y) {}
			Vector(const Vector& copy) : x(copy.x), y(copy.y) {}
			
			Vector& operator=(const Vector& vector) {
				x = vector.x;
				y = vector.y;

				return *this;
			}

			template <typename Scalar>
			Vector operator*(Scalar scalar) {
				return Vector(x * scalar, y * scalar);
			}

			template <typename Scalar>
			Vector operator*=(Scalar scalar) {
				return Vector(x *= scalar, y *= scalar);
			}

			template <typename Scalar>
			Vector operator/(Scalar scalar) {
				return Vector(x / scalar, y / scalar);
			}

			template <typename Scalar>
			Vector operator/=(Scalar scalar) {
				return Vector(x /= scalar, y /= scalar);
			}

			Vector operator+(const Vector& vector) const {
				return Vector(x + vector.x, y + vector.y);
			}

			Vector operator+=(const Vector& vector) {
				return Vector(x += vector.x, y += vector.y);
			}

			Vector operator-(const Vector& vector) const {
				return Vector(x - vector.x, y - vector.y);
			}

			Vector operator-=(const Vector& vector) {
				return Vector(x -= vector.x, y -= vector.y);
			}

			float getMagnitude() const {
				return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
			}

			void setMagnitude(float magnitude) {
				normalize();

				(*this) *= magnitude;
			}

			Vector normalize() {
				float magnitude = getMagnitude();

				if (magnitude == 0)
					return *this;

				x /= magnitude;
				y /= magnitude;

				return Vector(x, y);
			}

			float dotProduct(const Vector& vector) const {
				return (x * vector.x) + (y * vector.y);
			}

			bool limit(const float LIMIT) {
				if (getMagnitude() > LIMIT) {
					setMagnitude(LIMIT);

					return true;
				} else {
					return false;
				}
			}
	};

	const Vector ZERO = Vector(0.0f, 0.0f);
	const Vector LEFT = Vector(-1.0f, 0.0f);
	const Vector RIGHT = Vector(1.0f, 0.0f);
	const Vector UP = Vector(0.0f, -1.0f);
	const Vector DOWN = Vector(0.0f, 1.0f);
}