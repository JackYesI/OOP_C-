#pragma once
#include <iostream>
class Mystring
{
private:
	char* arr;
	size_t size;
	static size_t counter;
	void add(char sym);
public:
	Mystring() : Mystring(80)
	{
	}
	Mystring(size_t size)
	{
		this->size = size;
		this->arr = new char[size + 1];
		counter++;
	}
	Mystring(const Mystring& string)
	{
		this->size = string.size;
		this->arr = new char[size + 1];
		for (size_t i = 0; i < this->size; i++)
		{
			this->arr[i] = string.arr[i];
		}
		this->arr[this->size] = '\0';
		counter++;
	}
	Mystring(std::string str)
	{
		this->size = str.length();
		this->arr = new char[str.length() + 1];
		for (size_t i = 0; i < this->size; i++)
		{
			this->arr[i] = str[i];
		}
		this->arr[this->size] = '\0';
		counter++;
	}
	~Mystring()
	{
		if (this->arr != nullptr)
			delete[] this->arr;
	}
	void operator =(const Mystring& other);
	void operator =(const std::string& other);
	inline void print();
	void ConsoleFill();
	inline static size_t getCounter()
	{
		return counter;
	}
};

inline void Mystring::print()
{
	std::cout << this->arr << std::endl;
}
