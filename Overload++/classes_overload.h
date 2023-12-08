#pragma once
#include <iostream>
using namespace std;
class Circle
{
private:
	float radius;
public:
	Circle() : Circle(0)
	{

	}
	Circle(const float& radius)
	{
		this->radius = radius;
	}
	bool operator == (Circle circle) const
	{
		if (this->radius == circle.radius) return 1;
		else
			return 0;
	}
	bool operator > (Circle circle) const
	{
		if (lenght() > circle.lenght())
			return 1;
		else
			return 0;
	}
	void operator += (float radius)
	{
		this->radius = this->radius + radius;
	}
	void operator -= (float radius)
	{
		this->radius = this->radius - radius;
	}
	float lenght() const
	{
		return 2 * 3.14 * this->radius;
	}
};

class Airplan
{
public:
	Airplan() : Airplan("default", 0, 100)
	{}
	Airplan(const string& kind, const int& count_human, const int& max_human)
	{
		this->count_human = count_human;
		this->kind = kind;
		this->max_human = max_human;
	}
	bool operator == (Airplan airplan) const
	{
		if (this->kind == airplan.kind) return 1;
		else
			return 0;
	}
	bool operator > (Airplan airplan) const
	{
		if (this->max_human > airplan.max_human) return 1;
		else
			return 0;
	}
	Airplan& operator ++()
	{
		if (!isMax())
		{
			++count_human;
			return *this;
		}
		else
		{
			return *this;
		}
	}
	Airplan& operator --()
	{
		if (!isMin())
		{
			--count_human;
			return *this;
		}
		else
			return *this;
	}
	inline bool isMax()
	{
		return this->count_human == this->max_human ? 1 : 0;
	}
	inline bool isMin()
	{
		return this->count_human == 0 ? 1 : 0;
	}
	inline int getCount_human() const
	{
		return this->count_human;
	}

private:
	string kind;
	int count_human;
	int max_human;

};


