#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

const size_t SIZE = 50;
enum Categoria
{
	No ,horror, ecshn, Action, Strategy, Role_playing_game, Simulator, Adventures
};

class Game
{
	char name[SIZE];
	Categoria role = No;
	int popularity = 0;
public:
	Game() = default;
	Game(const char* name, const int& popularity, const Categoria& role) :
	 popularity{ popularity }, role{ role }
	{
		strcpy_s(this->name, name);
	}
	void print() const
	{
		std::cout << "Name game is " << this->name;
		std::cout << "\ngame ganre is " << this->role;
		std::cout << "\ngame popularity is " << this->popularity << std::endl;
	}
	std::string getName() const
	{
		return name;
	}
	Categoria getRole() const
	{
		return this->role;
	}
	int getPopularity() const
	{
		return this->popularity;
	}
	void setRole(const Categoria& role)
	{
		this->role = role;
	}
	void setPopular(const int& popular)
	{
		this->popularity = popular;
	}
	void setName(std::string& nameStr)
	{
		for (size_t i = 0; i < nameStr.size(); i++)
		{
			name[i] = nameStr[i];
		}
		name[nameStr.size()] = '\0';
		
	}
};

class Binaty_Game
{
	std::fstream file;
	size_t count;
public:
	Binaty_Game(const std::string& file_name)
	{
		file.open(file_name, std::ios_base::out | std::ios_base::in | std::ios_base::binary);
		file.seekg(0, std::ios::end);
		this->count = file.tellg() / sizeof(Game);
	}
	~Binaty_Game()
	{
		this->file.close();
	}
	void printFile() 
	{
		file.clear();
		file.seekg(0);
		Game game;
		for (size_t i = 0; i < this->count; i++)
		{
			file.seekg(i * sizeof(Game));
			file.read(reinterpret_cast<char*>(&game), sizeof(Game));
			game.print();
		}
	}
	void addGame(Game& game)
	{
		file.clear();
		file.seekg(sizeof(Game) * count);
		file.write((char*)&game, sizeof(Game));
		++count;
	}
	void searchGame(const char* name)
	{
		file.clear();
		file.seekg(0);
		Game game;
		for (size_t i = 0; i < this->count; i++)
		{
			file.seekg(i * sizeof(Game));
			file.read(reinterpret_cast<char*>(&game), sizeof(Game));
			if (name == game.getName())
			{
				game.print();
				return;
			}
		}
		std::cout << "Do't find\n";
	}
	void searchGame_role(const Categoria& role)
	{
		file.clear();
		file.seekg(0);
		Game game;
		for (size_t i = 0; i < this->count; i++)
		{
			file.seekg(i * sizeof(Game));
			file.read(reinterpret_cast<char*>(&game), sizeof(Game));
			if (role == game.getRole())
			{
				game.print();
			}
		}
	}
	void editData(const size_t& index, Game& game)
	{
		if (index < 0 or index >= this->count)
			return;
		file.clear();
		file.seekg(sizeof(Game) * index);
		file.write((char*)&game, sizeof(Game));
	}
	void clearFile(const std::string& file_name)
	{
		file.close();
		std::ofstream ofs;
		ofs.open(file_name);
		ofs.close();
		file.open(file_name, std::ios_base::out | std::ios_base::in | std::ios_base::binary);
		file.seekg(0, std::ios::end);
		this->count = file.tellg() / sizeof(Game);
	}
	void popGame(const size_t index, const std::string& file_name)
	{
		if (index < 0 or index >= this->count)
			return;
		std::vector<Game> vec;
		file.clear();
		file.seekg(0);
		Game game;
		for (size_t i = 0; i < this->count; i++)
		{
			file.seekg(i * sizeof(Game));
			file.read(reinterpret_cast<char*>(&game), sizeof(Game));
			if (i != index)
				vec.push_back(game);
		}
		this->clearFile(file_name);
		this->count = vec.size();

		file.clear();
		file.seekg(0);
		file.write(reinterpret_cast<char*>(vec.data()), sizeof(Game) * vec.size());
	}
};

