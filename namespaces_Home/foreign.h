#pragma once
#include "pasport.h"

using namespace pasport;

namespace Foreing {
	class ForeignPassport : public Passport
	{
		string number;
		string vizy;
	public:
		ForeignPassport(const string& name, const string& sex, const string& date, const string& dateOfExpity, const string& nationality, const string& number, const string& vizy) :
			Passport(name, sex, date, dateOfExpity, nationality), number{ number }, vizy{ vizy }
		{
			this->vizy += "\n";
		}
		ForeignPassport(const Passport& passport, const string& number, const string& vizy) :
			Passport(passport), number{ number }, vizy{ vizy }
		{
			this->vizy += "\n";
		}
		void Print() const
		{
			Passport::Print();
			cout << "Number of foreign passport is " << this->number << endl;
			cout << "All vizy:\n " << this->vizy << endl;
		}
		string getNumber() const
		{
			return this->number;
		}
		string getVizy() const
		{
			return this->vizy;
		}
		void setNumber(const string& number)
		{
			this->number = number;
		}
		void setVizy(const string& vizy)
		{
			this->vizy += vizy + ";\n";
		}
	};
}
