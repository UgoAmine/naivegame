#ifndef JEU_H
#define JEU_H

#include <filesystem>
#include "Board.hpp"

class Jeu {
public:
    Jeu(int argc, char* argv[]);
    ~Jeu();

private:
    WINDOW* win;
    Board*  brd;
};

#endif
