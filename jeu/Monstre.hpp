#ifndef MONSTRE_H
#define MONSTRE_H

#include "Board.hpp"

class Monstre
{
public:
    Monstre(WINDOW*);
    virtual ~Monstre();

    inline std::vector<int> getpos() const {return posM;}
    void setpos(const std::vector<int> );

    void move(WINDOW*);
    void moveNorth(WINDOW*);
    void moveEast(WINDOW*);
    void moveSouth(WINDOW*);
    void moveWest(WINDOW*);

private:
    std::vector<int> posM;
};

#endif // MONSTRE_H
