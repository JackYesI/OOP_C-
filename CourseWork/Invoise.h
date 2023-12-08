#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::cin;


const int SIZE = 50;
const int description_SIZE = 100;


class Invoise abstract
{
protected:
	char sender[SIZE];
	char receiver[SIZE];
	char description[description_SIZE];
	size_t length;
	size_t height;
	size_t width;
	size_t weight;
	char senderSity[SIZE];
	char receiverSity[SIZE];
	char senderAdress[SIZE];
	char receiverAdress[SIZE];
	bool pay_;
	bool success;
public:
	Invoise(const size_t& length = 10, const size_t height = 10, const size_t width = 10, const size_t& weight = 1, const bool pay_ = 1) :
		length{ length }, height{ height }, width{ width }, weight{ weight }, pay_{ pay_ }
	{
		this->success = 0;
		std::cout << "Enter name of sender          :: "; std::cin.ignore(); std::cin.getline(this->sender, SIZE);
		std::cout << "Enter description of delivery :: "; std::cin.ignore(); std::cin.getline(this->description, SIZE);
		std::cout << "Enter sity of sendler         :: "; std::cin.ignore(); std::cin.getline(this->senderSity, SIZE);
		std::cout << "Enter adress of sendler       :: "; std::cin.ignore(); std::cin.getline(this->senderAdress, SIZE);
		std::cout << "Enter name of receiver        :: "; std::cin.ignore(); std::cin.getline(this->receiver, SIZE);
		std::cout << "Enter receiver sity           :: "; std::cin.ignore(); std::cin.getline(this->receiverSity, SIZE);
		std::cout << "Enter receiver adress         :: "; std::cin.ignore(); std::cin.getline(this->receiverAdress, SIZE);
	}
	virtual void PrintInvoise() const = 0;
	virtual size_t getId() const = 0;
	virtual void closeInvoise() = 0;
	virtual size_t getPrice() = 0;
	virtual std::string getName() const = 0;
	virtual void editInvoise() = 0;
	virtual bool getSuccess() const = 0;
};

