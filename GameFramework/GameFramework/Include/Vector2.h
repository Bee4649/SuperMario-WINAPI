#pragma once

#include <math.h>

const float	PI = 3.14159f;

struct Vector2
{
	float	x, y;

	Vector2() :
		x(0.f),
		y(0.f)
	{
	}

	Vector2(float _x, float _y) :
		x(_x),
		y(_y)
	{
	}

	Vector2(const Vector2& v) :
		x(v.x),
		y(v.y)
	{
	}

	void operator = (const Vector2& v)
	{
		x = v.x;
		y = v.y;
	}

	void operator = (float f)
	{
		x = f;
		y = f;
	}

	bool operator == (const Vector2& v)	const
	{
		return x == v.x && y == v.y;
	}

	bool operator != (const Vector2& v)	const
	{
		return x != v.x || y != v.y;
	}

	// +
	Vector2 operator + (const Vector2& v)	const
	{
		Vector2	result;

		result.x = x + v.x;
		result.y = y + v.y;

		return result;
	}

	Vector2 operator + (float f)	const
	{
		Vector2	result;

		result.x = x + f;
		result.y = y + f;

		return result;
	}

	Vector2 operator + (int i)	const
	{
		Vector2	result;

		result.x = x + (float)i;
		result.y = y + (float)i;

		return result;
	}

	// +=
	void operator += (const Vector2& v)
	{
		x += v.x;
		y += v.y;
	}

	void operator += (float f)
	{
		x += f;
		y += f;
	}

	void operator += (int i)
	{
		x += (float)i;
		y += (float)i;
	}

	// -
	Vector2 operator - (const Vector2& v)	const
	{
		Vector2	result;

		result.x = x - v.x;
		result.y = y - v.y;

		return result;
	}

	Vector2 operator - (float f)	const
	{
		Vector2	result;

		result.x = x - f;
		result.y = y - f;

		return result;
	}

	Vector2 operator - (int i)	const
	{
		Vector2	result;

		result.x = x - (float)i;
		result.y = y - (float)i;

		return result;
	}

	// -=
	void operator -= (const Vector2& v)
	{
		x -= v.x;
		y -= v.y;
	}

	void operator -= (float f)
	{
		x -= f;
		y -= f;
	}

	void operator -= (int i)
	{
		x -= (float)i;
		y -= (float)i;
	}

	// *
	Vector2 operator * (const Vector2& v)	const
	{
		Vector2	result;

		result.x = x * v.x;
		result.y = y * v.y;

		return result;
	}

	Vector2 operator * (float f)	const
	{
		Vector2	result;

		result.x = x * f;
		result.y = y * f;

		return result;
	}

	Vector2 operator * (int i)	const
	{
		Vector2	result;

		result.x = x * (float)i;
		result.y = y * (float)i;

		return result;
	}

	// *=
	void operator *= (const Vector2& v)
	{
		x *= v.x;
		y *= v.y;
	}

	void operator *= (float f)
	{
		x *= f;
		y *= f;
	}

	void operator *= (int i)
	{
		x *= (float)i;
		y *= (float)i;
	}

	// /
	Vector2 operator / (const Vector2& v)	const
	{
		Vector2	result;

		result.x = x / v.x;
		result.y = y / v.y;

		return result;
	}

	Vector2 operator / (float f)	const
	{
		Vector2	result;

		result.x = x / f;
		result.y = y / f;

		return result;
	}

	Vector2 operator / (int i)	const
	{
		Vector2	result;

		result.x = x / (float)i;
		result.y = y / (float)i;

		return result;
	}

	// /=
	void operator /= (const Vector2& v)
	{
		x /= v.x;
		y /= v.y;
	}

	void operator /= (float f)
	{
		x /= f;
		y /= f;
	}

	void operator /= (int i)
	{
		x /= (float)i;
		y /= (float)i;
	}

	float Angle(const Vector2& v)	const
	{
		// 너비 길이
		// float Width = v.x - x;
		// 높이 길이
		// float Height = v.y - y;
		return 0.f;
	}
};
