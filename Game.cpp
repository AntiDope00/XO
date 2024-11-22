#include "Game.h"
#include "GameState.h"
#include "Memento.h"
Game::Game() {
    board = new char*[3];
    for (int i = 0; i < 3; i++) {
        board[i] = new char[3];
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';

}
void Game::boadOverview() {
    std::cout << "1|2|3 \n";
    std::cout << "4|5|6 \n";
    std::cout << "7|8|9 \n";
}

bool Game::makeMove(int pos) {
    if (pos < 1 || pos > 9) {
        std::cout << "Invalid move: out of bounds!\n";
        return false;
    }

    switch (pos) {
        case 1:
            if (board[0][0] != ' ') {
                std::cout << "Invalid move: cell already occupied!\n";
                return false;
            } else {
                board[0][0] = currentPlayer;
            }
            break;
        case 2:
            if (board[0][1] != ' ') {
                std::cout << "Invalid move: cell already occupied!\n";
                return false;
            } else {
                board[0][1] = currentPlayer;
            }
            break;
        case 3:
            if (board[0][2] != ' ') {
                std::cout << "Invalid move: cell already occupied!\n";
                return false;
            } else {
                board[0][2] = currentPlayer;
            }
            break;
        case 4:
            if (board[1][0] != ' ') {
                std::cout << "Invalid move: cell already occupied!\n";
                return false;
            } else {
                board[1][0] = currentPlayer;
            }
            break;
        case 5:
            if (board[1][1] != ' ') {
                std::cout << "Invalid move: cell already occupied!\n";
                return false;
            } else {
                board[1][1] = currentPlayer;
            }
            break;
        case 6:
            if (board[1][2] != ' ') {
                std::cout << "Invalid move: cell already occupied!\n";
                return false;
            } else {
                board[1][2] = currentPlayer;
            }
            break;
        case 7:
            if (board[2][0] != ' ') {
                std::cout << "Invalid move: cell already occupied!\n";
                return false;
            } else {
                board[2][0] = currentPlayer;
            }
            break;
        case 8:
            if (board[2][1] != ' ') {
                std::cout << "Invalid move: cell already occupied!\n";
                return false;
            } else {
                board[2][1] = currentPlayer;
            }
            break;
        case 9:
            if (board[2][2] != ' ') {
                std::cout << "Invalid move: cell already occupied!\n";
                return false;
            } else {
                board[2][2] = currentPlayer;
            }
            break;
        default:
             std::cout << "Invalid choice. Please try again.\n";
            break;
    }

   // updateState();

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';


    return true;
}

char Game::checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
     bool fullBoard = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                fullBoard = false;
                break;
            }
        }
        if (!fullBoard) break;
    }

    // If the board is full and no winner, it's a draw
    if (fullBoard) {
        return 'D';  // 'D' for Draw
    }
    return ' ';
}

char Game::getBoard(int row, int col) {
    return board[row][col];
}



void Game::displayBoard() {
    std::cout << "\nCurrent Board:\n";
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            std::cout << " " << board[row][col];
            if (col < size - 1) {
                std::cout << " |";
            }
        }
        std::cout << "\n";
        if (row < size - 1) {
            for (int col = 0; col < size; ++col) {
                std::cout << "---";
                if (col < size - 1) {
                    std::cout << "+";
                }
            }
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}
void Game::lastBoard() {
    std::cout << "\nLast Game Board:\n";
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            std::cout << " " << board[row][col];
            if (col < size - 1) {
                std::cout << " |";
            }
        }
        std::cout << "\n";
        if (row < size - 1) {
            for (int col = 0; col < size; ++col) {
                std::cout << "---";
                if (col < size - 1) {
                    std::cout << "+";
                }
            }
            std::cout << "\n";
        }
    }
    std::cout << "\n";
    std::cout << "* Player " << checkWinner() << " wins! *\n";
}
 Memento* Game::createMemento(){
    return new Memento(this->board, this->size, this->currentPlayer);

 }
    void Game::restoreMemento(Memento* mem){
        GameState *state= mem->state;
        board = state->getBoard();
        currentPlayer = state->getPlayer();
        size = state->getSize();



    }


Game::~Game() {
    for (int i = 0; i < 3; ++i) {
        delete[] board[i];
    }
    delete[] board;

}
