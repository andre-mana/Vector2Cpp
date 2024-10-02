#pragma once
#include <iostream>

class Vector2 {
public:
	float x, y;

	Vector2(float _x, float _y);
	Vector2();

	static const Vector2 zero;
	static const Vector2 down;
	static const Vector2 left;
	static const Vector2 up;
	static const Vector2 right;
	static const Vector2 positiveInfinity;
	static const Vector2 negativeInfinity;

	friend Vector2 operator+(const Vector2& v1, const Vector2& v2);
	friend Vector2 operator-(const Vector2& v1, const Vector2& v2);
	friend Vector2 operator*(const Vector2& v1, const Vector2& v2);
	friend Vector2 operator*(const Vector2& v1, float d);
	friend Vector2 operator*(float d, const Vector2& v1);
	friend Vector2 operator/(const Vector2& v1, const Vector2& v2);
	friend Vector2 operator/(const Vector2& v1, float d);
	friend bool operator==(const Vector2& v1, const Vector2& v2);
	friend std::ostream& operator<<(std::ostream& os, const Vector2& v);

	float magnitude() const;
	float sqrMagnitude();
	void normalize();
	Vector2 normalized() const;
	void RotatedDegrees(float angle);
	void RotatedRadians(float angle);

	static Vector2 Lerp(const Vector2& a, const Vector2& b, float t);
	static Vector2 LerpUnclamped(const Vector2& a, const  Vector2& b, float t);
	static float Distance(const Vector2& a, const Vector2& b);
	static Vector2 ClampMagnitude(const Vector2& vector, float maxLength);
	static float Dot(const Vector2& lhs, const Vector2& rhs);
	static Vector2 Max(const Vector2& lhs, const Vector2& rhs);
	static Vector2 Min(const Vector2& lhs, const Vector2& rhs);
	static float AngleInDegrees(const Vector2& from, const Vector2& to);
	static float AngleInRadians(const Vector2& from, const Vector2& to);
	static Vector2 MoveTowards(const Vector2& current, const Vector2& target, float maxDistanceDelta);
	static Vector2 Perpendicular(const Vector2& inDirection);
	static Vector2 PerpendicularClockwise(const Vector2& inDirection);
	static Vector2 Reflect(const Vector2& inDirection, const Vector2& inNormal);
	static Vector2 Scale(const Vector2& a, const Vector2& b);
	static float SignedAngleInDegrees(const Vector2& from, const Vector2& to);
	static float SignedAngleInRadians(const Vector2& from, const Vector2& to);
	static float Cross(const Vector2& a, const Vector2& b);
	static float AngleFullDegrees(const Vector2& a, const Vector2& b);
	static float AngleFullRadians(const Vector2& a, const Vector2& b);
	static Vector2 Project(const Vector2& from, const Vector2& to);
};