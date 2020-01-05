#ifndef JOUEUR_H
#define JOUEUR_H

#include "Mobile.hpp"
#include "Board.hpp"

class Player : public Mobile
{
  public:
    Player(WINDOW*);
    virtual ~Player();

    inline int getNbTelep() const {return nbtelep;}
    inline void setNbTelep(const int tel) {nbtelep = tel;}

    void testGoal(WINDOW*, Board, char);
    void telepo(WINDOW*);

  private:
    int nbtelep;
};

#endif // JOUEUR_H
