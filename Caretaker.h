#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <list>
#include <memory> 

class Caretaker {
private:
    std::list<Memento*> history;

public:
    void save(Memento* memento);
    Memento* undo();
    Memento* retrieveMemento();
    bool hasHistory() const;
    void clear();
};

#endif // CARETAKER_H
