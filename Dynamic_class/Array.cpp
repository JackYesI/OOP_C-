#include "Array.h"

void Array::changeSize(size_t new_size)
{
	int* ptr = new int[new_size];
	for (size_t i = 0; i < new_size; i++)
	{
		if (i >= this->size)
			ptr[i] = 0;
		else
			ptr[i] = this->value[i];
	}
	this->size = new_size;
	if (this->value != nullptr)
		delete[] this->value;
	this->value = ptr;
}

void Array::sort(int left, int rigth)
{
	int tmp_l = left;
	int tmp_r = rigth;
	int pivot = this->value[left];
	while (left < rigth)
	{
		while (this->value[rigth] > pivot && left < rigth) rigth--;
		if (rigth != left) {
			this->value[left] = this->value[rigth];
			left++;
		}
		while (this->value[left] < pivot && left < rigth) left++;
		if (rigth != left) {
			this->value[rigth] = this->value[left];
			rigth--;
		}
	}
	this->value[left] = pivot;
	int index = left;
	left = tmp_l;
	rigth = tmp_r;
	if (index > left) {
		sort(left, index - 1);
	}
	if (index < rigth) {
		sort(index + 1, rigth);
	}
}

int Array::min()
{
	if (size == 0) return -1;
	int min = value[0];
	for (size_t i = 1; i < size; i++)
	{
		if (min > value[i]) min = value[i];
	}
	return min;
}

int Array::max()
{
	if (size == 0) return -1;
	int max = value[0];
	for (size_t i = 1; i < size; i++)
	{
		if (max < value[i]) max = value[i];
	}
	return max;
}

void Array::Fillin()
{
	int x;
	for (size_t i = 0; i < this->size; i++)
	{
		std::cout << "Enter " << i << " value :: "; std::cin >> x;
		this->value[i] = x;
	}
}