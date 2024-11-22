#include "Caretaker.h"
#include <stdexcept> 


void Caretaker::save(Memento* memento) {
    history.push_back(memento);
}

Memento* Caretaker::undo() {
    if (history.empty()) {
        throw std::runtime_error("No more states to undo!");
    }
    Memento* memento = history.back();
    history.pop_back();
    return memento;
}

Memento* Caretaker::retrieveMemento(){
     if (history.empty()) {
        throw std::runtime_error("No saved states to retrieve!");
    }
    return history.back();
}

bool Caretaker::hasHistory() const {
    return !history.empty();
}

// Clear the history
void Caretaker::clear() {
     for (Memento* memento : history) {
        delete memento;
    }
    history.clear();
}
