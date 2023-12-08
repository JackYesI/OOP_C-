#pragma once
#include <iostream>
class Array
{
public:
	Array() = default;
	Array(size_t size)
	{
		this->size = size;
		value = new int[size];
	}
	Array(Array& other)
	{
		this->size = other.size;
		int* ptr = new int[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			ptr[i] = other.value[i];
		}
		if (this->value != nullptr)
			delete[] this->value;
		this->value = ptr;
	}
	~Array()
	{
		if (this->value != nullptr)
			delete[] this->value;
	}
	inline void Fill();
	inline void Show();
	void Fillin();
	void changeSize(size_t new_size);
	void sort(int left, int rigth);
	inline size_t getSize();
	int min();
	int max();
private:
	int* value = nullptr;
	size_t size;
};

inline void Array::Fill()
{
	for (size_t i = 0; i < size; i++)
	{
		value[i] = 1;
	}
}

inline void Array::Show()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << value[i] << "\t";
	}
	std::cout << std::endl;
}

inline size_t Array::getSize()
{
	return this->size;
}



