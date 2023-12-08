#include "Cat.h"

void Cat::sound() const
{
	cout << "Mauw" << endl;
}

void Cat::type() const
{
	cout << "Cat" << endl;
}

void Cat::show() const
{
	cout << "Name :: " << this->name << endl;
	cout << "Age  :: " << this->age << endl;
	sound();
	type();
}
