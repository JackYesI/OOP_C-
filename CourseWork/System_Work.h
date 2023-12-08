#pragma once
#include "Default_Invoise.h"
#include"Foreign_Invoise.h"
#include "Internet_Invoise.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

//const char* FILE_NAME_ = "data_np.txt";

class System_Worker
{
protected:
	std::vector<Invoise *> data_np{};
	void writeCloseInvoise();
	void deleteCloseInvoise();
public:
	System_Worker() = default;
	void createInvoise();
	void closeInvoise(const size_t& Id);
	size_t getPay(const size_t& Id);
	void closeInvoise(const std::string& name);
	size_t getPay(const std::string& name);
	void readData();
	void clearData();
	void writeData();
	void ShowCloseInvoise();
};

class System_Boss : public System_Worker
{
public:
	System_Boss() = default;
	void editInvoise(const size_t& Id);
	void deleteInvoise(const size_t& Id);
	void deleteInvoise(const std::string& name);
};


class System_Client
{
private:
	Invoise* invoise = nullptr;
	void write();
public:
	void createInvoise();
};

