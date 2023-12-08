#include "dog.h"

void dog::sound() const
{
	std::cout << "Gav" << std::endl;
}

void dog::type() const
{
	cout << "Dog" << endl;
}

void dog::show() const
{
	cout << "Name :: " << this->name << endl;
	cout << "Age  :: " << this->age << endl;
	sound();
	type();
}
