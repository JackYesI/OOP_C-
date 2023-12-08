#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
	double a;
	double b;
public:
	
	Rectangle(const double& a = 1, const double& b = 1) :
		a{ a }, b{ b }
	{

	}
	void Show() const override
	{
		cout << "Rectangle's first side :: " << this->a << endl;
		cout << "Rectangle's second side :: " << this->b << endl;
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

