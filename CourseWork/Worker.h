#pragma once
#include "System_Work.h"
#include "Bank.h"

//class Worker
//{
//protected:
//	System_Worker sys;
//	Bank kasa;
//public:
//	Worker() = default;
//	virtual void Work();
//};
//
//
//class Boss : public Worker
//{
//public:
//	Boss() = default;
//	void Work() override;
//};

__interface IWorker
{
public:
	void Work();
};

class Worker : public IWorker
{
	System_Worker sys;
	Bank kasa;
public:
	void Work() override;
};

class Boss : public IWorker
{
	System_Boss sys;
	Bank kasa;
public:
	void Work() override;
};