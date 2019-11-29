#include "Board.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int rand_int(int a, int b)
{
    return rand()%(b-a) + a;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    Board b;
    b.wallgen(15);
    b.prt();



    return 0;
}
