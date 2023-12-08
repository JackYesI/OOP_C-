#include "System_Work.h"

void System_Worker::writeCloseInvoise()
{
	std::vector<Invoise*> vec;
	std::ofstream file("close_data.txt", std::ios::app);
	for (auto i = data_np.begin(); i < data_np.end(); i++)
	{
		if ((*i)->getSuccess() == true) {
			vec.push_back((*i));
		}
	}
	file.write(reinterpret_cast<char*>(vec.data()), sizeof(Invoise) * vec.size());
	file.close();
}

void System_Worker::deleteCloseInvoise()
{
	for (auto i = data_np.begin(); i < data_np.end(); i++)
	{
		if ((*i)->getSuccess() == true) {
			data_np.erase(i);
		}
	}
}

void System_Worker::createInvoise()
{
	Box box;
	int box_;
	std::cout << "Choose box :: ";
	std::cin >> box_;
	switch (box_)
	{
	case 2:
	{
		Default_Invoise invoise(Box_2);
		data_np.push_back(&invoise);
		break;
	}
	case 5:
	{
		Default_Invoise invoise(Box_5);
		data_np.push_back(&invoise);
		break;
	}
	case 10:
	{
		Default_Invoise invoise(Box_10);
		data_np.push_back(&invoise);
		break;
	}
	case 15:
	{
		Default_Invoise invoise(Box_15);
		data_np.push_back(&invoise);
		break;
	}
	case 20:
	{
		Default_Invoise invoise(Box_20);
		data_np.push_back(&invoise);
		break;
	}
	case 30:
	{
		Default_Invoise invoise(Box_30);
		data_np.push_back(&invoise);
		break;
	}
	default:
		size_t length, height, width, weight;
		bool pay;
		std::cout << "Enter length    :: ";
		std::cin >> length;
		std::cout << "Enter height    :: ";
		std::cin >> height;
		std::cout << "Enter width     :: ";
		std::cin >> width;
		std::cout << "Enter weight    :: ";
		std::cin >> weight;
		std::cout << "Enter pay (1/0) :: ";
		std::cin >> pay;
		Default_Invoise invoise(None, length, height, width, weight, pay);
		data_np.push_back(&invoise);
		break;
	}
}

void System_Worker::closeInvoise(const size_t& Id)
{
	auto it = std::find_if(data_np.begin(), data_np.end(), [Id](const Invoise& inv)
		{

			return (inv.getId() == Id);
		});
	if (it != data_np.end())
	{
		(*it)->closeInvoise();
		cout << "Invoise close successfully :)\n";
	}
	else
		cout << "Do't find invoise for this Id :(\n";
}

size_t System_Worker::getPay(const size_t& Id)
{
	auto it = std::find_if(data_np.begin(), data_np.end(), [Id](const Invoise& inv)
		{

			return (inv.getId() == Id);
		});
	if (it != data_np.end())
	{
		return (*it)->getPrice();
		cout << "Invoise get price successfully :)\n";
	}
	else
		cout << "faul :(\n";
}

void System_Worker::closeInvoise(const std::string& name)
{
	auto it = std::find_if(data_np.begin(), data_np.end(), [name](const Invoise& inv)
		{

			return (inv.getName() == name);
		});
	if (it != data_np.end())
	{
		(*it)->closeInvoise();
		cout << "Invoise close successfully :)\n";
	}
	else
		cout << "Do't find invoise for this Id :(\n";
	this->writeCloseInvoise();
	this->deleteCloseInvoise();
}

size_t System_Worker::getPay(const std::string& name)
{
	auto it = std::find_if(data_np.begin(), data_np.end(), [name](const Invoise& inv)
		{

			return (inv.getName() == name);
		});
	if (it != data_np.end())
	{
		return (*it)->getPrice();
		cout << "Invoise get price successfully :)\n";
	}
	else
		cout << "faul :(\n";
}

void System_Worker::readData()
{
	std::ifstream file("data_np.txt");
	file.seekg(0, std::ios::end);
	int count = file.tellg() / sizeof(Invoise);

	file.clear();
	file.seekg(0);

	Invoise* in;
	for (size_t i = 0; i < count; i++)
	{
		file.seekg(i * sizeof(Invoise));
		file.read(reinterpret_cast<char*>(in), sizeof(Invoise));
		data_np.push_back(in);
	}
	file.close();
}

void System_Worker::clearData()
{
	data_np.clear();
}

void System_Worker::writeData()
{
	std::ofstream file("data_np.txt", std::ios::trunc);
	file.write(reinterpret_cast<char*>(data_np.data()), sizeof(Invoise) * data_np.size());
	file.close();
}

void System_Worker::ShowCloseInvoise()
{
	std::ifstream file("close_data.txt");
	std::vector<Invoise*> vec;
	file.seekg(0, std::ios::end);
	int count = file.tellg() / sizeof(Invoise);

	file.clear();
	file.seekg(0);

	Invoise* in;
	for (size_t i = 0; i < count; i++)
	{
		file.seekg(i * sizeof(Invoise));
		file.read(reinterpret_cast<char*>(in), sizeof(Invoise));
		vec.push_back(in);
	}
	file.close();
	for (auto i = vec.begin(); i < vec.end(); i++)
	{
		(*i)->PrintInvoise();
		cout << endl;
	}
}

void System_Boss::editInvoise(const size_t& Id)
{
	auto it = std::find_if(data_np.begin(), data_np.end(), [Id](const Invoise& inv)
		{

			return (inv.getId() == Id);
		});
	if (it != data_np.end())
	{
		(*it)->editInvoise();
		cout << ":)\n";
	}
	else
		cout << "faul :(\n";
}

void System_Boss::deleteInvoise(const size_t& Id)
{
	auto it = std::find_if(data_np.begin(), data_np.end(), [Id](const Invoise& inv)
		{

			return (inv.getId() == Id);
		});
	if (it != data_np.end())
	{
		data_np.erase(it);
		cout << ":)\n";
	}
	else
		cout << "faul :(\n";
}

void System_Boss::deleteInvoise(const std::string& name)
{
	auto it = std::find_if(data_np.begin(), data_np.end(), [name](const Invoise& inv)
		{

			return (inv.getName() == name);
		});
	if (it != data_np.end())
	{
		data_np.erase(it);
		cout << ":)\n";
	}
	else
		cout << "faul :(\n";
}

void System_Client::write()
{
	std::ofstream file("data_np.txt", std::ios::app);
	file.clear();
	file.seekp(0, std::ios::end);
	file.write(reinterpret_cast<char*>(&(this->invoise)), sizeof(Invoise));
	file.close();
}

void System_Client::createInvoise()
{
	Box box;
	int box_;
	std::cout << "Choose box :: ";
	std::cin >> box_;
	switch (box_)
	{
	case 2:
	{
		Default_Invoise invoise(Box_2);
		this->invoise = &invoise;
		this->write();
		break;
	}
	case 5:
	{
		Default_Invoise invoise(Box_5);
		this->invoise = &invoise;
		this->write();
		break;
	}
	case 10:
	{
		Default_Invoise invoise(Box_10);
		this->invoise = &invoise;
		this->write();
		break;
	}
	case 15:
	{
		Default_Invoise invoise(Box_15);
		this->invoise = &invoise;
		this->write();
		break;
	}
	case 20:
	{
		Default_Invoise invoise(Box_20);
		this->invoise = &invoise;
		this->write();
		break;
	}
	case 30:
	{
		Default_Invoise invoise(Box_30);
		this->write();
		this->invoise = &invoise;
		break;
	}
	default:
		size_t length, height, width, weight;
		bool pay;
		std::cout << "Enter length    :: ";
		std::cin >> length;
		std::cout << "Enter height    :: ";
		std::cin >> height;
		std::cout << "Enter width     :: ";
		std::cin >> width;
		std::cout << "Enter weight    :: ";
		std::cin >> weight;
		std::cout << "Enter pay (1/0) :: ";
		std::cin >> pay;
		Default_Invoise invoise(None, length, height, width, weight, pay);
		this->invoise = &invoise;
		this->write();
		break;
	}
}
