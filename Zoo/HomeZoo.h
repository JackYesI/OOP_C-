#pragma once
#include <vector>
#include "Animal.h"
#include "dog.h"
#include "Cat.h"
#include "Hamster.h"
#include "Parrot.h"

//class Zoo
//{
//	vector<Animal*>* zoo;
//public:
//	Zoo(vector<Animal*>* ani):
//		zoo{ani}
//	{
//		
//	}
//	void Show() const;
//	void add();
//};
class Zoo
{
	vector<Animal*> zoo;
public:
	Zoo(vector<Animal*>& ani) :
		zoo{ ani }
	{
		
	}
	~Zoo()
	{
		zoo.~vector();
	}
	void Show() const;
	void add();
	void buyAll();
	void pop(const size_t& index);
};
