#include "HomeZoo.h"

//void Zoo::Show() const
//{
//	for (size_t i = 0; i < 1; i++)
//	{
//		cout << zoo->back()->getName() << endl;
//		zoo[0][1]->show();
//	}
//}
void Zoo::Show() const
{
	if (zoo.size() != 0)
	{
		for (size_t i = 0; i < this->zoo.size(); i++)
		{
			zoo[i]->show();
		}
	}
	else
		cout << "Zoo is empty" << endl;
}

void Zoo::add()
{
	cout << "Enter animal what you want to create ";
	string name;
	cin >> name;
	while (true)
	{
		if (name == "Cat")
		{
			string name_;
			size_t age_;
			cout << "Enter name ";
			cin >> name_;
			cout << "Enter age ";
			cin >> age_;
			zoo.push_back(new Cat(name_, age_));
			return;
		}
		else if (name == "Dog")
		{
			string name_;
			size_t age_;
			cout << "Enter name ";
			cin >> name_;
			cout << "Enter age ";
			cin >> age_;
			zoo.push_back(new dog(name_, age_));
			return;
		}
		else if (name == "Hamster")
		{
			string name_;
			size_t age_;
			cout << "Enter name ";
			cin >> name_;
			cout << "Enter age ";
			cin >> age_;
			zoo.push_back(new Hamster(name_, age_));
			return;
		}
		else if (name == "Parrot")
		{
			string name_;
			size_t age_;
			cout << "Enter name ";
			cin >> name_;
			cout << "Enter age ";
			cin >> age_;
			zoo.push_back(new Parrot(name_, age_));
			return;
		}
		else
		{
			cout << "Cat or Parrot or Dog or Hamster;\n";
		}
	}
}

void Zoo::buyAll()
{
	zoo.clear();
}

void Zoo::pop(const size_t& index)
{
	if (zoo.size() != 0)
		zoo.erase(zoo.begin() + index);
	else
		cout << "Zoo is empty" << endl;
}
