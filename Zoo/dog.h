#pragma once
#include "Animal.h"

class dog : public Animal
{
public:
	dog(const string& name, const size_t& age) : Animal(name, age)
	{

	}
	void sound() const override;
	void type() const override;
	void show() const override;
};

