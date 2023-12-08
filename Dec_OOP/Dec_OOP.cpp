#include <iostream>
#include <string>
using namespace std;

class Contact
{
public:
	Contact()
	{
		strCopy(this->name, "NoName");
		this->home_phone = "NoNumber";
		this->phone = "NoNumber";
		this->work_phone = "NoNumber";
		setInfo("NoInfo");
	}
	Contact(const char* name): Contact(name, "NoNumber", "NoNumber", "NoNumber"){}
	Contact(const char* name,const string& home_phone,const string& work_phone,const string& phone): Contact(name, home_phone, work_phone, phone, "Noinfo"){}
	Contact(const char* name, const string& home_phone, const string& work_phone, const string& phone, const string& info)
	{
		strCopy(this->name, name);
		this->home_phone = home_phone;
		this->phone = work_phone;
		this->work_phone = phone;
		setInfo(info);
	}
	~Contact()
	{
		if (this->name != nullptr)
			delete[] this->name;
	}
	void strCopy(char*& dest, const char* source)
	{
		// memory leak
		if (!isValidName(source)) return;
		if (dest != nullptr) {
			delete[] dest;
		}
		dest = new char[strlen(source) + 1];
		strcpy_s(dest, strlen(source) + 1, source);
	}
	inline const char* getName() const
	{
		return this->name;
	}
	inline const string getHome_phone() const
	{
		return this->home_phone;
	}
	inline const string getWork_phone() const
	{
		return this->work_phone;
	}
	inline const string getPhone() const
	{
		return this->phone;
	}
	inline const string getInfo() const
	{
		return this->info;
	}
	void setName(const char* name) 
	{
		if (!isValidName(name)) return;
		strCopy(this->name, name);
	}
	void setHome_phone(const string& home_phone)
	{
		if (!isValidFirstElemPhone(home_phone)) return;
		else if (!isValidPhone(home_phone)) return;
		this->home_phone = home_phone;
	}
	void setWork_phone(const string& work_phone)
	{
		if (!isValidFirstElemPhone(work_phone)) return;
		else if (!isValidPhone(work_phone)) return;
		this->work_phone = work_phone;
	}
	void setPhone(const string& phone)
	{
		if (!isValidFirstElemPhone(phone)) return;
		else if (!isValidPhone(phone)) return;
		this->phone = phone;
	}
	void setInfo(const string& info)
	{
		if (!isValidInfo(info)) return;
		this->info = info;
	}
	inline bool isValidName(const char* name) const
	{
		return name != nullptr and name[0] != '\0' and name[0] != ' ' and name[1] != ' ' and name[2] != ' ';
	}
	bool isValidPhone(const string& phone)
	{
		for (size_t i = 0; i < phone.length(); i++)
		{
			if (!(47 <= phone[i] and phone[i] <= 57)) return false;
		}
		return true;
	}
	inline bool isValidFirstElemPhone(const string& phone) const
	{
		return phone[0] == 43;
	}
	inline bool isValidInfo(const string& phone) const
	{
		return phone[0] != ' ' and phone != "";
	}
	void Show() const
	{
		cout << "contact name  :: " << getName() << endl;
		cout << "home number   :: " << getHome_phone() << endl;
		cout << "work number   :: " << getWork_phone() << endl;
		cout << "itself number :: " << getPhone() << endl;
		cout << "information   :: " << getInfo() << endl << endl;
	}
private:
	char* name = nullptr;
	string home_phone = "";
	string work_phone = "";
	string phone = "";
	string info = "";
};



int main()
{
	Contact ivan, anna("Anna"), denys("Denys", "+0965878222", "+0965878222", "+0965878222");
	Contact oksana("Oksana", "+0965878221", "+0965878222", "+0965878223", "lorem ipsum");
	ivan.Show();
	anna.Show();
	denys.Show();
	oksana.Show();
}

