#pragma once
class Vector2
{
public:
	Vector2()
		: x(0), y(0)
	{
	}

	Vector2(int x, int y)
		: x((float)x), y((float)y)
	{
	}

	Vector2(float x, float y)
		: x(x), y(y)
	{

	}

	Vector2(const Vector2& other)
		: x(other.x), y(other.y)
	{
	}

	Vector2 operator+(const Vector2& other) const
	{
		Vector2 result;
		result.x = (*this).x + other.x;
		result.y = this->y + other.y;

		return result;
	}

	Vector2 operator-(const Vector2& other) const
	{
		Vector2 result;
		result.x = (*this).x - other.x;
		result.y = this->y - other.y;

		return result;
	}

	Vector2 operator*(const float& value) const
	{
		Vector2 result;
		return result = Vector2(this->x * value, this->y * value);
	}

	Vector2 operator*(const double& value) const
	{
		Vector2 result;

		return result = Vector2(float(this->x * value), float(this->y * value));
	}

	Vector2& operator=(const Vector2& other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}
	Vector2& operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}
	bool operator!=(const Vector2& other) const 
	{
		return x != other.x || y != other.y;
	}

	float Length()const
	{
		float result = sqrtf(x * x + y * y);

		return result;
	}
	float Distance(const Vector2& other) const
	{
		Vector2 result = *this - other;

		return result.Length();
	}

	float Dot(const Vector2& other) const
	{
		float result = x * other.x + y * other.y;
		return result;
	}

	float Cross(const Vector2& other) const
	{
		float result = x * other.y - other.x * y;

		return result;
	}

	float Angle() const
	{
		float result = atan2f(y, x);
		return result;
	}

	Vector2 NorMalVector2() const
	{
		Vector2 result;
		float length = Length();
		result.x = x / length;
		result.y = y / length;

		return result;
	}

	void Normalize()
	{
		float length = Length();
		x /= length;
		y /= length;
	}

public:
	float x = 0.0f;
	float y = 0.0f;
};
