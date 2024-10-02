#include <limits>
#include <cmath>   
#include "Vector2.h"
#define PI 3.14159265358979323846264338327950288F

Vector2::Vector2(float _x, float _y) :x(_x), y(_y) {}
Vector2::Vector2() { x = 0; y = 0; }

const Vector2 Vector2::zero(0, 0);
const Vector2 Vector2::down(0, -1);
const Vector2 Vector2::left(-1, 0);
const Vector2 Vector2::right(1, 0);
const Vector2 Vector2::up(0, 1);
const Vector2 Vector2::positiveInfinity(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
const Vector2 Vector2::negativeInfinity(std::numeric_limits<float>::min(), std::numeric_limits<float>::min());

Vector2 operator+(const Vector2& v1, const Vector2& v2) { return Vector2(v1.x + v2.x, v1.y + v2.y); }
Vector2 operator-(const Vector2& v1, const Vector2& v2) { return Vector2(v1.x - v2.x, v1.y - v2.y); }
Vector2 operator*(const Vector2& v1, const Vector2& v2) { return Vector2(v1.x * v2.x, v1.y * v2.y); }
Vector2 operator*(const Vector2& v1, float d) { return Vector2(v1.x * d, v1.y * d); }
Vector2 operator*(float d, const Vector2& v1) { return Vector2(v1.x * d, v1.y * d); }
Vector2 operator/(const Vector2& v1, const Vector2& v2) { return Vector2(v1.x / v2.x, v1.y / v2.y); }
Vector2 operator/(const Vector2& v1, float d) { return Vector2(v1.x / d, v1.y / d); }
bool operator ==(const Vector2& v1, const Vector2& v2) { return v1.x == v2.x && v1.y == v2.y ? true : false; }
std::ostream& operator<<(std::ostream& os, const Vector2& v) { return os << "(" << v.x << "," << v.y << ")"; }

float Vector2::magnitude() const {
	return sqrt(x * x + y * y);
}

void Vector2::normalize() {
	float mag = Vector2::magnitude();
	
	if (mag > 0.00001) {
		x = x / mag;
		y = y / mag;
	}
	else {
		x = 0;
		y = 0;
	}
}

Vector2 Vector2::normalized() const {
	return Vector2(x / magnitude(), y / magnitude());
}

float Vector2::sqrMagnitude() {
	return (x * x + y * y);
}

Vector2 Vector2::Lerp(const Vector2& a, const Vector2& b, float t) {
	return  a + (b - a) * t;
}

float Vector2::Distance(const Vector2& a, const Vector2& b) {
	return (b - a).magnitude();
}
float Vector2::Dot(const Vector2& lhs, const Vector2& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

Vector2 Vector2::Scale(const Vector2& a, const Vector2& b) {
	return a * b;
}

Vector2 Vector2::LerpUnclamped(const Vector2& a, const Vector2& b, float t) {
	if (t < 0) t = 0;
	if (t > 1) t = 1;
	
	return Lerp(a, b, t);
}

Vector2 Vector2::ClampMagnitude(const Vector2& vector, float maxLength) {
	return (vector.magnitude() > maxLength) ? vector.normalized() * maxLength : vector;
}

Vector2 Vector2::Max(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(std::max(lhs.x, rhs.x), std::max(lhs.y, rhs.y));
}

Vector2 Vector2::Min(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(std::min(lhs.x, rhs.x), std::min(lhs.y, rhs.y));
}

float Vector2::AngleInDegrees(const Vector2& from, const Vector2& to) {
	return (180 / PI) * acos(Vector2::Dot(from, to) / (from.magnitude() * to.magnitude()));
}

float Vector2::AngleInRadians(const Vector2& from, const Vector2& to) {
	return acos(Vector2::Dot(from, to) / (from.magnitude() * to.magnitude()));
}

Vector2 Vector2::MoveTowards(const Vector2& current, const Vector2& target, float maxDistanceDelta) {
	float distance = Vector2::Distance(current, target);

	if (distance < maxDistanceDelta || distance == 0) {
		return target;
	}
	else{
		return current + (target - current) / distance * maxDistanceDelta;
	}
}

Vector2 Vector2::Perpendicular(const Vector2& inDirection) {
	return Vector2(-inDirection.y, inDirection.x);
}
Vector2 Vector2::PerpendicularClockwise(const Vector2& inDirection) {
	return Vector2(inDirection.y, -inDirection.x);
}

Vector2 Vector2::Reflect(const Vector2& inDirection, const Vector2& inNormal) {
	return inDirection - 2 * inNormal * Vector2::Dot(inDirection, inNormal);
}

float Vector2::SignedAngleInDegrees(const Vector2& from, const Vector2& to) {
	return (180 / PI) * SignedAngleInRadians(from, to);
}

float Vector2::SignedAngleInRadians(const Vector2& from, const Vector2& to) {
	return -atan2(to.y * from.x - to.x * from.y, to.x * from.x + to.y * from.y);
}

Vector2 Vector2::Project(const Vector2& from, const Vector2& to) {
	return Vector2::Dot(from, to.normalized()) * to.normalized();
}

float Vector2::Cross(const Vector2& a, const Vector2& b) {
	return a.x * b.y - a.y * b.x;
}

float Vector2::AngleFullDegrees(const Vector2& a, const Vector2& b) {
	float angleInDegrees = Vector2::AngleInDegrees(a, b);
	
	if (Vector2::Cross(a, b) > 0){
		return 360 - angleInDegrees;
	}
	else{
		return  angleInDegrees;
	}
}

float Vector2::AngleFullRadians(const Vector2& a, const Vector2& b) {
	float angleInRadians = Vector2::AngleInRadians(a, b);
	
	if (Vector2::Cross(a, b) > 0){
		return 2 * PI - angleInRadians;
	}
	else{
		return angleInRadians;
	}
}

void  Vector2::RotatedRadians(float angle) {
	angle *= -1;
	float originalX = x;
	float originalY = y;
	x = originalX * cos(angle) - originalY * sin(angle);
	y = originalX * sin(angle) + originalY * cos(angle);

	if (angle <= -2 * PI || angle >= 2 * PI) {
		angle = 0;
	}
}

void  Vector2::RotatedDegrees(float angle) {
	angle = angle * PI / 180;
	RotatedRadians(angle);
}
