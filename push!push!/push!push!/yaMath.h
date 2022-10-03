#pragma once

enum class DIRECTION
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	NONE
};

struct Vector2
{
	int x;
	int y;

	Vector2()
		:x(0), y(0)
	{

	}

	Vector2(int x, int y)
		: x(x), y(y)
	{

	}

	Vector2(const Vector2& other)
	{
		x = other.x;
		y = other.y;
	}

	Vector2& operator =(const Vector2& other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}

	bool operator ==(const Vector2& other)
	{
		return (x == other.x && y == other.y);
	}
};
typedef Vector2 Pos;
typedef Vector2 Size;