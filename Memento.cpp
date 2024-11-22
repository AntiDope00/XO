#include "Memento.h"


Memento::Memento(char** board, int size, char currentPlayer){ 
    state = new GameState(board,size,currentPlayer); 
}
Memento::~Memento() {
    delete state;
    state = nullptr;
}


