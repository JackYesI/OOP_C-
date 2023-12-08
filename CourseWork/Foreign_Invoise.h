#pragma once
#include "Invoise.h"
#include "Box.h"



class Foreign_Invoise : public Invoise
{
	Box box;
	size_t price;
	size_t Id;
	char country_out[SIZE];
	char country_in[SIZE];
	void setId();
	void setSize();
	void setPrice();
	void setSender(const std::string& name);
	void setReceiver(const std::string& name);
	void setAdress(const std::string& adress);
	void setSity(const std::string& city);
	void setCountry(const std::string& city);
public:
	Foreign_Invoise(const Name_Box& name, const size_t& length = 10, const size_t height = 10, const size_t width = 10, const size_t& weight = 1, const bool pay_ = 1) :Invoise(length, height, width, weight, pay_)
	{
		box.setName(name);
		if (box.getName() != None) this->setSize();
		this->setId();
		std::cout << "Enter country out :: "; std::cin.ignore(); std::cin.getline(this->country_out, SIZE);
		std::cout << "Enter country in  :: "; std::cin.ignore(); std::cin.getline(this->country_in, SIZE);
	}
	virtual void PrintInvoise() const override;
	size_t getId() const override;
	size_t getPrice() override;
	void setPay_();
	void closeInvoise() override;
	std::string getName() const override;
	void editInvoise() override;
	bool getSuccess() const override;
};

