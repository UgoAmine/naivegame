#include "Joueur.hpp"

Player::Player(WINDOW* win): Mobile(win, 'J'), nbtelep{0} {}

Player::~Player(){}

void Player::testGoal(WINDOW* win, Board brd, char c)
{
  switch(c)
  {
    case 'z':
    {
      char goal = mvwinch(win, pos[0]-1, pos[1]);
      if (goal == '$')
        nbtelep++;
      else if (goal == '*')
        brd.doorOpening(win);
    }
      break;
    case 'q':
    {
      char goal = mvwinch(win, pos[0], pos[1]-1);
      if (goal == '$')
        nbtelep++;
      else if (goal == '*')
        brd.doorOpening(win);
    }
      break;
    case 's':
    {
      char goal = mvwinch(win, pos[0]+1, pos[1]);
      if (goal == '$')
        nbtelep++;
      else if (goal == '*')
        brd.doorOpening(win);
    }
      break;
    case 'd':
    {
      char goal = mvwinch(win, pos[0], pos[1]+1);
      if (goal == '$')
        nbtelep++;
      else if (goal == '*')
        brd.doorOpening(win);
    }
      break;
  }
}

void Player::telepo(WINDOW* win)
{
  mvwaddch(win, pos[0], pos[1], ' ');
  do {pos = {random_data(1,1,48)[0], random_data(1,1,98)[0]};}
  while (mvwinch(win, pos[0], pos[1]) != ' ');
  mvwaddch(win, pos[0], pos[1], 'J');
  nbtelep--;
}
