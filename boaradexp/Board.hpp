#ifndef Board_h
#define Board_h

// enumerated variable data type GameState to return a value for the
// gameState function
enum GameState {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
private:
    
public:
    // 3x3 game board
    char board[3][3];
    
    // Default Constructor
    Board();
    
    // makeMove Function
    bool makeMove(int, int, char);
    
    // gameState Function
    int gameState();
    
    // print Function
    void print();
    
    // which player's turn it is
    char turn;
    
    // total number of turns taken in the game
    int totalTurns;
};

#endif /* Board_h */