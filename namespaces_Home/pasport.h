#pragma once
#include <iostream>
using namespace std;

namespace pasport {
	class Passport
	{
	protected:
		string name;
		string sex;
		string date;
		string dateOfExpity;
		string nationality;
	public:
		Passport(const string& name, const string& sex, const string& date, const string& dateOfExpity, const string& nationality) : name{ name }, sex{ sex }, date{ date }, dateOfExpity{ dateOfExpity }, nationality{ nationality }
		{

		}
		void Print() const
		{
			cout << "Name           :: " << this->name << endl;
			cout << "Sex            :: " << this->sex << endl;
			cout << "Date           :: " << this->date << endl;
			cout << "Date Of Expity :: " << this->dateOfExpity << endl;
			cout << "Nationality    :: " << this->nationality << endl;
		}
		string getName() const
		{
			return this->name;
		}
		string getSex() const
		{
			return this->sex;
		}
		string getDate() const
		{
			return this->date;
		}
		string getDateOfExpity() const
		{
			return this->dateOfExpity;
		}
		string getNationality() const
		{
			return this->nationality;
		}
		void setName(const string& name)
		{
			this->name = name;
		}
		void setSex(const string& sex)
		{
			this->sex = sex;
		}
		void setDate(const string& date)
		{
			this->date = date;
		}
		void setDateOfExpity(const string& dateOfExpity)
		{
			this->dateOfExpity = dateOfExpity;
		}
		void setNationality(const string& nationality)
		{
			this->nationality = nationality;
		}
	};
}