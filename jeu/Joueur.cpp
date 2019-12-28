#include "Joueur.hpp"
#include <iostream>


Player::Player(WINDOW* win)
{
    //  CREATES A VECTOR OF RANDOM STARTING POS FOR PLAYER
    setpos({random_data(1,2,48)[0],random_data(1,2,98)[0]});

    //  PRINTS PLAYER ON ITS INITIAL RANDOM POSITION
    mvwaddch(win,posJ[0],posJ[1], 'J');
    wrefresh(win);
}

void Player::moveNorth(WINDOW* window)
{
  mvwaddch(window,posJ[0],posJ[1], ' ');
  posJ[0]--;
  mvwaddch(window,posJ[0],posJ[1], 'J');
}

void Player::moveEast(WINDOW* window)
{
  mvwaddch(window,posJ[0],posJ[1], ' ');
  posJ[1]++;
  mvwaddch(window,posJ[0],posJ[1], 'J');
}

void Player::moveSouth(WINDOW* window)
{
  mvwaddch(window,posJ[0],posJ[1], ' ');
  posJ[0]++;
  mvwaddch(window,posJ[0],posJ[1], 'J');
}

void Player::moveWest(WINDOW* window)
{
  mvwaddch(window,posJ[0],posJ[1], ' ');
  posJ[1]--;
  mvwaddch(window,posJ[0],posJ[1], 'J');
}

void Player::doorOpening()
{
  //A IMPLEMENTER
}

void Player::telepIncrem()
{
  //A IMPLEMENTER
}

void Player::move(char c, WINDOW* win)
{
  switch(c)
  {
    case 'z': //  NORTH
      if (mvwinch(win, posJ[0]-1, posJ[1]) == '$')
      {
        this->doorOpening();
        this->moveNorth(win);
      }
      else if (mvwinch(win, posJ[0]-1, posJ[1]) == '*')
      {
        this->telepIncrem();
        this->moveNorth(win);
      }
      else if (mvwinch(win, posJ[0]-1, posJ[1]) == ' ')
      {
        this->moveNorth(win);
      }
      break;
    case 'd': //  EAST
      if (mvwinch(win, posJ[0], posJ[1]+1) == '$')
      {
        this->doorOpening();
        this->moveEast(win);
      }
      else if (mvwinch(win, posJ[0], posJ[1]+1) == '*')
      {
        this->telepIncrem();
        this->moveEast(win);
      }
      else if (mvwinch(win, posJ[0], posJ[1]+1) == ' ')
      {
        this->moveEast(win);
      }
      break;
    case 'q': //  WEST
      if (mvwinch(win, posJ[0], posJ[1]-1) == '$')
      {
        this->doorOpening();
        this->moveWest(win);
      }
      else if (mvwinch(win, posJ[0], posJ[1]-1) == '*')
      {
        this->telepIncrem();
        this->moveWest(win);
      }
      else if (mvwinch(win, posJ[0], posJ[1]-1) == ' ')
      {
        this->moveWest(win);
      }
      break;
    case 's': //  SOUTH
      if (mvwinch(win, posJ[0]+1, posJ[1]) == '$')
      {
        this->doorOpening();
        this->moveSouth(win);
      }
      else if (mvwinch(win, posJ[0]+1, posJ[1]) == '*')
      {
        this->telepIncrem();
        this->moveSouth(win);
      }
      else if (mvwinch(win, posJ[0]+1, posJ[1]) == ' ')
      {
        this->moveSouth(win);
      }
      break;
  }

  wrefresh(win);
}

void Player::setpos(const std::vector<int> p) {posJ = p;}
void Player::setposy(const int y) {posJ[0] = y;}
void Player::setposx(const int x) {posJ[0] = x;}


Player::~Player(){}
