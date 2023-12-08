#include "Parrot.h"

void Parrot::sound() const
{
	cout << "Car-car" << endl;
}

void Parrot::type() const
{
	cout << "I'm Parrot" << endl;
}

void Parrot::show() const
{
	cout << "Name :: " << this->name << endl;
	cout << "Age  :: " << this->age << endl;
	sound();
	type();
}
