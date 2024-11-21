#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "Memento.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>

class Game { // Represents the main game logic, board state, and interaction with players.
public:
    Game(); // Constructor to set up the board

    void boadOverview();
    bool makeMove(int pos);
    char checkWinner();
    char getBoard(int row, int col);
    void displayBoard();
    ~Game(); // Destructor

private:
    char** board;       // 3x3 board 
    char currentPlayer;
    int size = 3;
};

#endif // GAME_H
