#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <random>     // mt19937 (Mersene Twister) and uniform_int_distribution
#include <algorithm>  // generate (used for random data)
#include <vector>     // vector
#include <iterator>   // begin, end, and ostream_iterator
#include <functional> // bind (used for random data generator)
#include <ncurses.h>

std::vector<int> random_data(int n , int a, int b); //random data generator function(number of data, lower bound, upperbound )

class Board
{
private:
    int size;
public:
Board(int , WINDOW *  );

~Board();
};



#endif // Board
