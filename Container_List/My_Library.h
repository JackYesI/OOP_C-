#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <list>
#include <forward_list>
#include <vector>
#include "MyDate.h"
using std::endl;
using std::cin;
using std::string;
using std::cout;
using std::ostream;
using std::forward_list;


const int SIZE = 20;

class Book
{
	char autor[SIZE];
	char name[SIZE];
	Date date_of;
	bool available;
public:
	Book() = default;
	Book(const size_t& day_of_date, const size_t& mounth_of_date, const size_t& year_of_date, const string& author_name, const string& book_name):
		 available{false}
	{
		date_of.setDate(day_of_date, mounth_of_date, year_of_date);
		for (size_t i = 0; i < SIZE; i++)
		{
			if (i < author_name.size())
				autor[i] = author_name[i];
			else
				autor[i] = '\0';
			if (i < book_name.size())
				name[i] = book_name[i];
			else
				name[i] = '\0';
		}
	}
	friend ostream& operator <<(ostream& os, const Book& book);
	void showName() const;
	void showAutor() const;
	string getName() const;
	string getAuhor() const;
	void setAvailable();
	bool getAvailable() const;
	Date getDate() const;
	void setName(const string& name);
	void setAuthor(const string& author);
	void setDate(const Date& date);
};

class Library
{
	std::list<Book> lib{};
	size_t count;
public:
	Library()
	{
		std::fstream file("data.dat", std::ios_base::out | std::ios_base::in | std::ios_base::binary);
		file.seekg(0, std::ios::end);
		this->count = file.tellg() / sizeof(Book);
		file.clear();
		file.seekg(0);
		Book book;
		for (size_t i = 0; i < this->count; i++)
		{
			file.seekg(i * sizeof(Book));
			file.read(reinterpret_cast<char*>(&book), sizeof(Book));
			lib.push_front(book);
		}
		file.close();

	}
	void addBook();
	void print() const;
	void addBook(const Book& book);
	void search(const string& name, const string& author);
	void editBook(const string& name, const string& author);
	void searchBooks(const string& author);
	void giveBook(const string& name);
	void takeBook(const string& name);
	void sortByAutorNextByName();
	void pop(const string& autor, const string& name, const size_t& day, const size_t& mounth, const size_t& year);
	void popIndex(const size_t& index);
	void writeFile();
};

