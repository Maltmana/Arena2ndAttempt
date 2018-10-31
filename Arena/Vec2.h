#pragma once
template<class T>
class Vec2
{
public:
	Vec2() = default;
	Vec2(T x, T y)
		:
		x{ x },
		y{ y }
	{
	};

	~Vec2()
	{
	};

public:
	T x;
	T y;

private:

};

