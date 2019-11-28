#include <iostream>
#include <random>     // mt19937 (Mersene Twister) and uniform_int_distribution
#include <algorithm>  // generate (used for random data)
#include <vector>     // vector
#include <iterator>   // begin, end, and ostream_iterator
#include <functional> // bind (used for random data generator)


std::vector<int> random_data(int n , int a, int b); //random data generator function(number of data, lower bound, upperbound )

class Board
{
private:
    char brd[30][30];
    int size;
    int m_lvl;

public:

Board();

void wallgen();

void prt(); //print board

~Board();
};
