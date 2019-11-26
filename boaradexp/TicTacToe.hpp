#include "Board.hpp"
#include <iostream>

using namespace std;

#ifndef TicTacToe_h
#define TicTacToe_h

class TicTacToe
{
    private:
        // which player's turn it is
        char p;
    public:
        // gameBoard object of the Board class
        Board gameBoard;
    
        // which player's turn it is
        char turn;
    
        // total number of turns taken in the game
        int totalTurns;
    
        // character variable to be passed to the TicTacToe constructor
        TicTacToe(char);
    
        // play Function
        void play();
};

#endif /* TicTacToe_h */