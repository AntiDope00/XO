#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include <vector>
#include <utility> 
class Game;
class GameState {
public:
    GameState(char** board, int size, char player);
    char** getBoard();
    int getSize();
    char getPlayer();


    ~GameState();
    private:
        char** board;
        int size = 3;
        char player;

};



#endif  // GAMESTATE_H

