#include "Hamster.h"

void Hamster::sound() const
{
	cout << "Puf" << endl;
}

void Hamster::type() const
{
	cout << "Puf-men" << endl;
}

void Hamster::show() const
{
	cout << "Name :: " << this->name << endl;
	cout << "Age  :: " << this->age << endl;
	sound();
	type();
}
