#include "Foreign_Invoise.h"
using namespace std;


void Foreign_Invoise::setId()
{
	ifstream myfile;
	myfile.open("file_F_Id.txt");
	myfile >> this->Id;
	myfile.close();
	this->Id++;
	ofstream file;
	file.open("file_F_Id.txt", std::ios::trunc);
	file << this->Id;
	file.close();
}

void Foreign_Invoise::setSize()
{
	this->length = this->box.getLength();
	this->weight = this->box.getWeight();
	this->height = this->box.getHeight();
	this->width = this->box.getWigth();
}

void Foreign_Invoise::setPrice()
{
	price = box.getName() * 5 + 20 + this->weight * 20;
}

void Foreign_Invoise::setSender(const std::string& name)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		if (i < name.length())
		{
			sender[i] = name[i];
		}
		else
			sender[i] = '\0';
	}
}

void Foreign_Invoise::setReceiver(const std::string& name)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		if (i < name.length())
		{
			receiver[i] = name[i];
		}
		else
			receiver[i] = '\0';
	}
}

void Foreign_Invoise::setAdress(const std::string& adress)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		if (i < adress.length())
		{
			receiverAdress[i] = adress[i];
		}
		else
			receiverAdress[i] = '\0';
	}
}

void Foreign_Invoise::setSity(const std::string& city)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		if (i < city.length())
		{
			receiverSity[i] = city[i];
		}
		else
			receiverSity[i] = '\0';
	}
}

void Foreign_Invoise::setCountry(const std::string& city)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		if (i < city.length())
		{
			country_in[i] = city[i];
		}
		else
			country_in[i] = '\0';
	}
}

void Foreign_Invoise::PrintInvoise() const
{
	cout << "Sendler         :: " << this->sender << endl;
	cout << "Description     :: " << this->description << endl;
	cout << "Sedler Adress   :: " << this->senderAdress << endl;
	cout << "Sedler Sity     :: " << this->senderSity << endl;
	cout << "Receiver        :: " << this->receiver << endl;
	cout << "Receiver Sity   :: " << this->receiverSity << endl;
	cout << "Receiver Adress :: " << this->receiverAdress << endl;
	cout << "Box             :: " << this->box.getName() << endl;
	cout << "Length          :: " << this->length << endl;
	cout << "Weight          :: " << this->weight << endl;
	cout << "Width          :: " << this->width << endl;
	cout << "Height          :: " << this->height << endl;
}

size_t Foreign_Invoise::getId() const
{
	return this->Id;
}

size_t Foreign_Invoise::getPrice() 
{
	return this->price;
}

void Foreign_Invoise::setPay_()
{
	char s = 'y';
	cout << "Who pay (y) = default(sedler);\n(n) - switch of Receiver\n (y/n):";
	cin >> s;
	if (s == 'n') this->pay_ = false;
	else this->pay_ = true;
}

void Foreign_Invoise::closeInvoise()
{
	this->success = true;
}

std::string Foreign_Invoise::getName() const
{
	return string(this->receiver);
}

void Foreign_Invoise::editInvoise()
{
	cout << "What you want to edit:\n1) sender;\t2) receiver;\t3) adress;\t4) city;\t5) country;\n";
	char choose;
	cin >> choose;
	switch (static_cast<int>(choose) - 48)
	{
	case 1:
	{
		char new_sender[SIZE]; cout << "Enter new sender :: "; cin.ignore(); cin.getline(new_sender, SIZE);
		this->setSender(string(new_sender));
		break;
	}
	case 2:
	{
		char new_receiver[SIZE]; cout << "Enter new receiver :: "; cin.ignore(); cin.getline(new_receiver, SIZE);
		this->setSender(string(new_receiver));
		break;
	}
	case 3:
	{
		char new_adress[SIZE]; cout << "Enter new adress :: "; cin.ignore(); cin.getline(new_adress, SIZE);
		this->setSender(string(new_adress));
		break;
	}
	case 4:
	{
		char new_city[SIZE]; cout << "Enter new city :: "; cin.ignore(); cin.getline(new_city, SIZE);
		this->setSender(string(new_city));
		break;
	}
	case 5:
	{
		char new_country[SIZE]; cout << "Enter new country :: "; cin.ignore(); cin.getline(new_country, SIZE);
		this->setSender(string(new_country));
		break;
	}
	default:
		cout << "No edit\n";
		break;
	}
}

bool Foreign_Invoise::getSuccess() const
{
	return this->success;
}




