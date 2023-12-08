#pragma once
#include <iostream>
using namespace std;


class Animal abstract
{
protected:
	string name;
	size_t age;
public:
	Animal(const string& name = string(), const size_t& age = size_t()) :
		name{ name }, age{ age }
	{

	}
	string getName() const;
	size_t getAge() const;
	void setName(const string& name)
	{
		this->name = name;
	}
	void setAge(const size_t& age)
	{
		this->age = age;
	}
	virtual void sound() const = 0;
	virtual void type() const = 0;
	virtual void show() const = 0;
};



