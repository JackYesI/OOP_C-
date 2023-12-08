#pragma once
#include "Shape.h"


class Circle : public Shape
{
	double r;
	const double PI = 3.14;
public:
	
	Circle(const double& r = 1):
		r{r}
	{

	}
	void Show() const override
	{
		cout << "Circle's radius :: " << this->r << endl;
	}
	void Save() const override
	{
		ofstream file_obj("Input.txt", ios_base::app);
		if (!file_obj.is_open()) {
			return;
		}
		
		file_obj << this->r << endl;
	}
	void Load() override
	{
		ifstream file_obj("Input.txt", ios_base::app);
		if (!file_obj.is_open()) {
			return;
		}
		file_obj >> this->r;
	}
};

