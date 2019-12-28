#ifndef JOUEUR_H
#define JOUEUR_H

#include "Board.hpp"

class Player
{
  public:
    Player(WINDOW* );
    virtual ~Player();

    void move(char , WINDOW* );
    inline std::vector<int> getpos() const {return posJ;}
    inline int getposy() const {return posJ[0];}
    inline int getposx() const {return posJ[1];}

    void setpos(const std::vector<int>);
    void setposy(const int);
    void setposx(const int);

    void doorOpening();
    void telepIncrem();

    void moveNorth(WINDOW*);
    void moveEast(WINDOW*);
    void moveSouth(WINDOW*);
    void moveWest(WINDOW*);

  private:
    std::vector<int> posJ;
};

#endif // JOUEUR_H
