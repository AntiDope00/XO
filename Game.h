#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "Memento.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>

class Game {
public:
    Game();

    void boadOverview();
    bool makeMove(int pos);
    char checkWinner();
    char getBoard(int row, int col);
    void displayBoard();
    void lastBoard();
    Memento* createMemento();
    void restoreMemento(Memento* mem);
    ~Game(); // Destructor

private:
    char** board;       // 3x3 board 
    char currentPlayer;
    int size = 3;
    GameState* currentState;
};

#endif
