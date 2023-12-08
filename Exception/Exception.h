#pragma once
#include <iostream>


class MyException
{
protected:
	std::string massage;
public:
	MyException(const std::string& massage = "Default Exception") :
		massage{massage}
	{

	}
	void what() const
	{
		std::cout << typeid(*this).name() << "\t" << this->massage << std::endl;
	}
};

class ExistLogginException : public MyException
{
public:
	ExistLogginException(const std::string& massage = "loggin == loggin") :
		MyException(massage)
	{

	}
	void what() const
	{
		MyException::what();
	}
};

class WrongPasswordLengthException : public MyException
{
public:
	WrongPasswordLengthException(const std::string& massage = "Login's length must be more than 7 characters") :
		MyException(massage)
	{

	}
	void what() const
	{
		MyException::what();
	}
};

class FormatPasswordException : public MyException
{
public:
	FormatPasswordException(const std::string& massage = "must be at least number and character and big character and special symbol") :
		MyException(massage)
	{

	}
	void what() const
	{
		MyException::what();
	}
};

class InvalidLoginException : public MyException
{
public:
	InvalidLoginException(const std::string& massage = "Invalid login !!!!") :
		MyException(massage)
	{

	}
	void what() const
	{
		MyException::what();
	}
};

class InvalidPasswordException : public MyException
{
public:
	InvalidPasswordException(const std::string& massage = "Invalid password !!!!") :
		MyException(massage)
	{

	}
	void what() const
	{
		MyException::what();
	}
};

