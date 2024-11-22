#include "Game.h"
#include "Caretaker.h"
#include <iostream>
#include <memory>
#include <thread> 
#include <chrono>  
#include <vector>

void displayMenu() {
    std::cout << "\n******************************\n";
    std::cout << "*        Tic-Tac-Toe        *\n";
    std::cout << "******************************\n";

    

 
    std::cout << "\n******************************\n";
    std::cout << "1. Start a New Game\n";
    std::cout << "2. Show Last 3 Game Results \n";
    std::cout << "3. Display Help\n";
    std::cout << "4. Quit\n";
    std::cout << "Enter your choice: ";
}


void displayHelp() {
    std::cout << "\n******************************\n";
    std::cout << "*           Help            *\n";
    std::cout << "******************************\n";
    std::cout << "1. Players take turns placing their marker (X or O) on the board.\n";
    std::cout << "2. The first player to get three markers in a row (horizontal, vertical, or diagonal) wins.\n";
    std::cout << "3. If the board is full and no one has won, the game ends in a draw.\n";
    std::cout << "4. You can undo your last move using the Undo option.\n";
}
void displayLoading(){
    char grid[3][3] = { {'X', 'X', ' '}, {' ', 'O', ' '}, {' ', ' ', 'O'} };
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << grid[i][j];
            if (j < 2) std::cout << " |";
        }
        std::cout << "\n";
        if (i < 2) {
            std::cout << "---+---+---\n";  // Grid separators
        }

        // Adding a delay to create a loading effect
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Half a second delay between rows
    }
}

int main() {
    bool running = true;
    Game* game = nullptr;
    std::vector<Caretaker> temp;
    Memento* mem = nullptr;
    int i = 0;
    displayLoading();
    while (running) {
        
        displayMenu();
        int choice;

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();                
            std::cin.ignore(1000, '\n');    
            continue;                      
        }

        switch (choice) {
        case 1:
            
            game = new Game();
            game->boadOverview();
            while (game->checkWinner() == ' ') {
                game->displayBoard();
                
                int pos;
                bool validMove = false;
                do {
                    std::cout << "Enter your move (1-9): ";
                    
                    if (!(std::cin >> pos)) {
                        std::cout << "Invalid input. Please enter a number.\n";
                        std::cin.clear();
                        std::cin.ignore(1000, '\n'); 
                        continue;                      
                    }
                    validMove = game->makeMove(pos);
                    if (!validMove) {
                        std::cout << "Invalid move. Try again.\n";
                    }
                } while (!validMove);
            }
            if (temp.size() < 3) {           
            Caretaker caretaker;
            caretaker.save(game->createMemento());
            temp.push_back(caretaker);
            } else {
            temp[i].clear();
            temp[i].save(game->createMemento());
            i = (i + 1) % 3; 
        }
            
            
            game->displayBoard();
            std::cout << "\n******************************\n";
            if(game->checkWinner()=='X' || game->checkWinner() == 'O'){
                std::cout << "* Player " << game->checkWinner() << " wins! *\n";
            }else if(game->checkWinner() == 'D'){
                std::cout << "* GAME ENDS IN DRAW *\n";
            }
            std::cout << "******************************\n";
            break;


        case 2:

          if (!temp.empty()) {
            bool historyFound = false;
            for (int j = temp.size() - 1; j >= 0; --j) {
                if (temp[j].hasHistory()) {
                    historyFound = true;
                    game->restoreMemento(temp[j].retrieveMemento());
                    game->lastBoard();
                }
            }

            if (!historyFound) {
                std::cout << "No previous games to show.\n";
            }
        } 

    break;

        case 3:
            displayHelp();
            break;

        case 4: // Quit
            running = false;
            std::cout << "******************************\n";
            std::cout << "*  Thanks for playing!      *\n";
            std::cout << "******************************\n";
            break;
            delete mem;
                mem = nullptr;
            delete game;
                game = nullptr;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
