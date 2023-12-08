#pragma once
#include "Animal.h"

class Parrot : public Animal
{
public:
	Parrot(const string& name, const size_t& age) : Animal(name, age)
	{

	}
	void sound() const override;
	void type() const override;
	void show() const override;
};

