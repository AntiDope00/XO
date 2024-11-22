#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>
#include "GameState.h"

class Memento {
public:

    Memento(char** board, int size, char currentPlayer); 
    ~Memento();

private:
    friend class Game;
    GameState* state;
};

#endif // MEMENTO_H
