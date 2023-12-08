#pragma once
#include <iostream>
#include <fstream>

const char* bank_name_FILE = "bank_file.txt";

class Bank
{
	size_t sum;
	size_t sum_for_days;
public:
	Bank():
		sum_for_days{0}
	{
		std::ifstream file(bank_name_FILE);
		file >> sum;
		file.close();
	}
	void getPay(const size_t& price)
	{
		this->sum_for_days += price;
	}
	size_t getSum() const
	{
		return this->sum;
	}
	size_t getSum_for_days() const
	{
		return this->sum_for_days;
	}
	void writeAll()
	{
		sum += sum_for_days;
		std::ofstream file(bank_name_FILE, std::ios::trunc);
		file << sum;
		file.close();
	}
};

