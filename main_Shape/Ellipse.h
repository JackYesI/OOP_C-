#pragma once
#include "Shape.h"

//struct Point
//{
//	int x;
//	int y;
//	Point(const int & x, const int & y):
//		x{}, y{y}
//	{
//
//	}
//};

class Ellipse : public Shape
{
	double a;
	double b;
public:
	
	Ellipse(const double& a = 1, const double& b = 1):
		a{a}, b{b}
	{

	}
	void Show()const
	{
		cout << "Litle semiaxis of ellipse (b) :: " << this->b << endl;
		cout << "Big semiaxis of ellipse (a) :: " << this->a << endl;
	}
	void Save() const override
	{
		ofstream file_obj("Input.txt", ios_base::app);
		if (!file_obj.is_open()) {
			return;
		}

		file_obj << this->a << "\n" << this->b << endl;
	}
	void Load() override
	{
		ifstream file_obj("Input.txt", ios_base::app);
		if (!file_obj.is_open()) {
			return;
		}
		file_obj >> this->a >> this->b;
	}
};

