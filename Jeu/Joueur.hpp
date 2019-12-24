#ifndef JOUEUR_H
#define JOUEUR_H

#include "Board.hpp"



class Player
{
  public:
    Player(WINDOW* );
    void move(char , WINDOW* );
    inline std::vector<int> getpos() {return posJ;}
    virtual ~Player();
    void setpos(std::vector<int> );
  private:
    std::vector<int> posJ;
};

#endif // JOUEUR_H
