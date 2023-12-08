#pragma once
#include "Animal.h"

class Hamster : public Animal
{
public:
	Hamster(const string& name, const size_t& age) : Animal(name, age)
	{

	}
	void sound() const override;
	void type() const override;
	void show() const override;
};

