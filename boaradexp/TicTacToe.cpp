#include "Board.hpp"
#include "TicTacToe.hpp"
#include <iostream>

using namespace std;

/*********************************************************************
 ** Constructor: Assigns turn to the value that the user chose as the 
 ** first player
 *********************************************************************/
TicTacToe::TicTacToe(char inputFirstTurn)
{
    turn = inputFirstTurn;
}

/*********************************************************************
 ** play Function: The play function starts the game and keeps looping
 ** to ask the correct player for their move and sending it to the game
 ** board with the makeMove function until someone has won or it's a
 ** as indicated by the gameState function, and then the outcome of the
 ** game is declare.
 *********************************************************************/
void TicTacToe::play()
{
    int x, y;
    char inputMove, inputFirstTurn;
    int gameState = UNFINISHED;
    
    // Print the game board for the first player to determine their move
    // gameBoard.print();
    
    /*cout << "Please enter which player will go first (x or o)." << endl;
    cin >> inputFirstTurn;
    cout << "Please enter the coordinates of player " << inputFirstTurn << "'s first move" << endl;
    cin >> x >> y;
    
    inputMove = gameBoard.makeMove(x, y, turn);*/
    
    while(inputMove == true && gameState == UNFINISHED)
    {
        // Print game board for player to determine next move
        gameBoard.print();
        
        cout << "It is player " << turn << "'s turn." << endl;
        cout << "Please make enter the coordinates of your move." << endl;
        cin >> x >> y;
        
        inputMove = gameBoard.makeMove(x, y, turn);
        
        if (inputMove == true)
        {
            gameBoard.totalTurns++;
        
            if (turn == 'x')
            {
                turn = 'o';
            }
            else if (turn == 'o')
            {
                turn = 'x';
            }
        }
        
        if (inputMove == false)
        {
            // Error message
            cout << "That space is taken." << endl;
            cin >> x >> y;
        }
    }
    
    if (inputMove == true)
    {
        gameState = gameBoard.gameState();
        
        // Player x is the winner
        if (gameState == 0)
        {
            gameBoard.print();
            cout << "***** x wins!!! *****" << endl;
        }
        // Player o is the winner
        else if (gameState == 1)
        {
            gameBoard.print();
            cout << "***** o wins!!! *****" << endl;
        }
        // The game is a draw
        else if (gameState == 2)
        {
            gameBoard.print();
            cout << "***** The game is a draw! *****" << endl;
        }
    }
}

/*********************************************************************
 ** main Function: Asks the user which player should go first, creates 
 ** a new TicTacToe object, and starts the game.
 *********************************************************************/
int main()
{
    int x, y;
    char inputFirstTurn, inputMove;
    
    Board gameBoard;
    
    gameBoard.print();
    
    cout << "Please enter which player will go first (x or o)." << endl;
    cin >> inputFirstTurn;
    cout << "Please enter the coordinates of player " << inputFirstTurn << "'s first move" << endl;
    cin >> x >> y;
    
    inputMove = gameBoard.makeMove(x, y, inputFirstTurn);
    
    TicTacToe game(inputFirstTurn);
    
    game.play();
    
    return 0;
}