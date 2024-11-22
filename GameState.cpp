#include "GameState.h"
#include "Game.h"


GameState::GameState(char** board, int size, char player) {
    this->size = size;
    this->player = player;
    this->board = new char*[size];
    for (int i = 0; i < size; ++i) {
        this->board[i] = new char[size];
        for (int j = 0; j < size; ++j) {
            this->board[i][j] = board[i][j];
        }
    }
}

char** GameState::getBoard(){
    return this->board;
}

int GameState::getSize(){
    return this->size;
}

char GameState::getPlayer(){
    return this->player;
}

GameState::~GameState() {
    for (int i = 0; i < size; ++i) {
        delete[] board[i];  // Delete each row
    }
    delete[] board;  // Delete the array of row pointers
}
