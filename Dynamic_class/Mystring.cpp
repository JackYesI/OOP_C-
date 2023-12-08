#include "Mystring.h"

void Mystring::add(char sym)
{
	size_t size_ = this->size + 1;
	char* ptr = new char[size_ + 1];
	for (size_t i = 0; i < this->size; i++)
	{
		ptr[i] = this->arr[i];
	}
	ptr[this->size] = sym;
	ptr[this->size + 1] = '\0';
	this->size = this->size + 1;
	if (this->arr != nullptr)
		delete[] this->arr;
	this->arr = ptr;
}

void Mystring::operator=(const Mystring& other)
{
	this->size = other.size;
	char* ptr = new char[other.size + 1];
	for (size_t i = 0; i < this->size; i++)
	{
		ptr[i] = other.arr[i];
	}
	ptr[this->size] = '\0';
	if (this->arr != nullptr)
		delete[] this->arr;
	this->arr = ptr;
}

void Mystring::operator=(const std::string& other)
{
	this->size = other.length();
	char* ptr = new char[other.length() + 1];
	for (size_t i = 0; i < this->size; i++)
	{
		ptr[i] = other[i];
	}
	ptr[this->size] = '\0';
	if (this->arr != nullptr)
		delete[] this->arr;
	this->arr = ptr;
}

void Mystring::ConsoleFill()
{
	char g;
	this->size = 0;
	while (true)
	{
		std::cin.get(g);
		if (g == '\n') break;
		else
			add(g);
	}
}

size_t Mystring::counter = 0;
