#include "Board.hpp"
#include <iostream>

using namespace std;

/*********************************************************************
 ** Default Constructor: Initializes the 3x3 array as an empty game
 ** board.
 *********************************************************************/
Board::Board()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = '.';
        }
    }
    
    totalTurns = 0;
}

/*********************************************************************
 ** makeMove Function: Takes the x and y coordinates of each move as 
 ** well as which player just made that move, and checks to see if the
 ** space that the player entered is an empty and available space to 
 ** make a move.  If it is an available space thus legal move, then the
 ** play function returns true.  If not, then the play function returns
 ** false.
 *********************************************************************/
bool Board::makeMove(int x, int y, char turn)
{
    
    // Player x's turn
    if (turn == 'x')
    {
        // Checks if the position player x chose is available
        if (board[x][y] == '.' || board[x][y] != 'o')
        {
            // Assigns x to that position if it is available
            board[x][y] = 'x';
            return true;
        }
    }
    // Player o's turn
    else if (turn == 'o')
    {
        // Checks if the position player o chose is available
        if (board[x][y] == '.' || board[x][y]!= 'x')
        {
            // Assigns o to that position if it is available
            board[x][y] = 'o';
            return true;
        }
    }
    // Returns false if the position is already occupied
    else
    {
        return false;
    }
    
    return 0;
}

/*********************************************************************
 ** gameState Function: Checks on the 4 possible states of the game:
 ** 1) x wins, 2) o wins, 3) draw, 4) unfinished.  Since these states 
 ** are represented via an enumerated data type, their values actually
 ** correspond to 0, 1, 2, and 3 respectively.
 *********************************************************************/
int Board::gameState()
{
    int totalTurns = 0;
    
    // Checks on the state of the game
    for (int i = 0; i < 3; i++)
    {
        // Checks if there is winner
        if ( (board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]) ||
            (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        {
            // Checks if x is the winner
            if ( (board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x') ||
                (board[0][i] == 'x' && board[1][i] == 'x' && board[2][i] == 'x') ||
                (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') ||
                (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x'))
            {
                // x is the winner
                return X_WON;
            }
            // Checks if o is the winner
            else if ( (board[i][0] == 'o' && board[i][1] == 'o' && board[i][2] == 'o') ||
                     (board[0][i] == 'o' && board[1][i] == 'o' && board[2][i] == 'o') ||
                     (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') ||
                     (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o'))
            {
                // o is the winner
                return O_WON;
            }
        }
    }
        // 9 moves have been made, with no available spaces/moves left
        if (totalTurns == 9)
        {
            // The game is a draw
            return DRAW;
        }
        else
        {
            // The game is unfinished and to be continued
            return UNFINISHED;
        }
    
    return 0;
}

/*********************************************************************
 ** print Function: prints the game board
 *********************************************************************/
void Board::print()
{
    cout << endl << "  " << "0" << " " << "1" << " " << "2" << endl;
    cout << "0" << " " << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl;
    cout << "1" << " " << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl;
    cout << "2" << " " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
}