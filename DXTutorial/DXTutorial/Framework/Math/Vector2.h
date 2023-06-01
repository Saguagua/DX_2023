#pragma once
template<typename T>
struct Vector2
{
public:
	Vector2<T>()
		:x(0.0f), y(0.0f)
	{}

	Vector2<T>(float x, float y)
		:x(x), y(y)
	{}

	Vector2<T> operator+(const Vector2<T>& other)
	{
		Vector2<T> result;
		result.x = x + other.x;
		result.y = y + other.y;

		return result;
	}

	Vector2<T> operator-(const Vector2<T>& other)
	{
		Vector2<T> result;
		result.x = x - other.x;
		result.y = y - other.y;

		return result;
	}

	Vector2<T>& operator=(const Vector2<T>& other)
	{
		x = other.x;
		y = other.y;

		return this;
	}

	Vector2<T> operator+=(const Vector2<T>& other)
	{
		x += other.x;
		y += other.y;

		return *(this);
	}

	Vector2<T> operator-=(const Vector2<T>& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	T Dot(const Vector2<T>& other)
	{
		return x * other.x + y * other.y;
	}

	T Angle() const
	{
		return atan2f(y, x);
	}

	T Length()
	{
		return sqrtf(x * x + y * y);
	}

	Vector2<T> Normalize()
	{
		Vector2<T> result;
		T len = Length();

		result.x = x / len;
		result.y = y / len;

		return result;
	}

	T x = 0.0f;
	T y = 0.0f;
};

