#include <iostream>
#include "Game.h"

int main()
{
    /*std::fstream file("games.dat", std::ios_base::out | std::ios_base::in | std::ios_base::binary);
    Game game("Dark Souls: Remastered", 100, Action);
    file.write((char*)&game, sizeof(Game));*/
    Game game("Dark Souls: Remastered", 100, Action);
    Game game_2("sd", 95, Action);
    Game game_3("den", 95, Action);
    Game game_4("acca", 95, Action);

    Binaty_Game games("games.dat");

    /*games.printFile();
    games.addGame(game_2);
    games.addGame(game_3);
    games.addGame(game_4);
    games.printFile();
    games.addGame(game);*/
 /*   games.printFile();*/
    /*games.searchGame_role(Action);*/
    /*games.editData(2, game);*/
    /*games.clearFile("games.dat");*/
   
    
    
    /*games.popGame(0, "games.dat");*/
    games.printFile();
    /*games.addGame(game);*/
    
}

