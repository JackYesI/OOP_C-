#pragma once
#include "Shape.h"
#include <fstream>



class Square : public Shape
{
	double a;
public:
	
	Square(const double& a = 1):
		a{a}
	{

	}
	void Show() const override
	{
		cout << "Square's side :: " << this->a << endl;
	}
	void Save() const override
	{
		ofstream file_obj("Input.txt", ios_base::app);
		if (!file_obj.is_open()) {
			return;
		}

		file_obj << this->a << endl;
	}
	void Load() override
	{
		ifstream file_obj("Input.txt", ios_base::app);
		if (!file_obj.is_open()) {
			return;
		}
		file_obj >> this->a;
	}
};

