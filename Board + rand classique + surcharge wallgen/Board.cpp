#include "Board.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


Board::Board()                      // GENERATES BORDERS + EMPTY INTERIOR
{
    for(int i=0; i<30; i++)
        for(int j=0; j<30; j++)
            brd[i][j] = (i==0)||(i==29)||(j==0)||(j==29) ? 'X' : ' ';
}

Board::~Board(){}

void Board::wallgen(int num) //WALL GENERATION
{
    for(int j=0; j<num; j++)
    {
        int i = 0;
        int wallSize = rand()%18 + 3;   // GENERATES A WALL SIZE BETWEEN 3 AND 20
        int wallType = rand()%4;        // GENERATES A WALL TYPE BETWEEN 0 AND 3
        int xOrigin = rand()%26+2;      // GENERATE X ORIGIN BETWEEN 2 AND 27
        int yOrigin = rand()%26+2;      // GENERATE Y ORIGIN BETWEEN 2 AND 27

        switch(wallType)
        {
        case 0: //RIGHT - HORIZONTAL
            while ((i < wallSize) & (i + yOrigin < 29))
            {
                brd[xOrigin    ][yOrigin + i] ='X';
                brd[xOrigin + 1][yOrigin + i] =' ';
                brd[xOrigin - 1][yOrigin + i] =' ';
                i++;
            };
            break;
        case 1: //DOWN - VERTICAL
            while ((i < wallSize) & (i + xOrigin < 29))
            {
                brd[xOrigin + i][yOrigin    ] ='X';
                brd[xOrigin + i][yOrigin + 1] =' ';
                brd[xOrigin +i ][yOrigin - 1] =' ';
                i++;
            };
            break;
        case 2: //DOWN - RIGHT DIAGONAL
            while ((xOrigin + i + 1 < 29) & (yOrigin + i + 1 < 29) & (i < wallSize))
            {
                brd[xOrigin + i    ][yOrigin  + i    ] ='X';
                brd[xOrigin + i    ][yOrigin  + i - 1] =' ';
                brd[xOrigin + i - 1][yOrigin  + i    ] =' ';
                brd[xOrigin + i + 1][yOrigin  + i - 1] =' ';
                brd[xOrigin + i - 1][yOrigin  + i + 1] =' ';
                i++;
            };
            break;
        case 3: // TOP - RIGHT DIAGONAL
            while ((i < wallSize) & (xOrigin - i - 1 > 0) & (yOrigin + i + 1 < 29))
            {
                brd[xOrigin - i    ][yOrigin + i    ] ='X';
                brd[xOrigin - i - 1][yOrigin + i    ] =' ';
                brd[xOrigin -i     ][yOrigin + i + 1] =' ';
                brd[xOrigin - i - 1][yOrigin + i - 1] =' ';
                brd[xOrigin - i + 1][yOrigin + i + 1] =' ';
                i++;
            };
            break;
        }
    }

}

void Board::prt() //PRINTS BOARD
{
    for (int i =0  ; i < 30; i++)
        for (int j = 0; j < 30; j++)
            (j==29) ? std::cout << brd[i][j] << std::endl : std::cout << brd[i][j];
}


