#ifndef MONSTRE_H
#define MONSTRE_H

#include "Board.hpp"


class Monstre
{
public:
    Monstre(WINDOW* );
    void move(WINDOW* );
    inline std::vector<int> getpos() {return posM;}
    void setpos(std::vector<int> );
    virtual ~Monstre();

private:
    std::vector<int> posM;
};

#endif // MONSTRE_H
