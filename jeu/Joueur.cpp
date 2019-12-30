#include "Joueur.hpp"
#include <iostream>

Player::Player(WINDOW* win) : numberOfTeleport(0)
{
    //  CREATES RANDOM STARTING POS FOR PLAYER (AS A VECTOR)
    setpos({random_data(1,2,48)[0],random_data(1,2,98)[0]});

    //  PRINTS PLAYER ON ITS INITIAL RANDOM POSITION
    mvwaddch(win,posJ[0],posJ[1], 'J');
    wrefresh(win);
}

Player::~Player(){}

void Player::move(char c, WINDOW* win)
{
  switch(c)
  {
    case 'z': //  NORTH
      this->moveNorth(win);
      this->action(win, mvwinch(win, posJ[0]-1, posJ[1]));
      break;
    case 'd': //  EAST
      this->moveEast(win);
      this->action(win, mvwinch(win, posJ[0], posJ[1]+1));
      break;
    case 'q': //  WEST
      this->moveWest(win);
      this->action(win, mvwinch(win, posJ[0], posJ[1]-1));
      break;
    case 's': //  SOUTH
      this->moveSouth(win);
      this->action(win, mvwinch(win, posJ[0]+1, posJ[1]));
      break;
  }

  wrefresh(win);
}

void Player::setpos(const std::vector<int> p) {posJ = p;}
void Player::setposy(const int y) {posJ[0] = y;}
void Player::setposx(const int x) {posJ[1] = x;}


void Player::moveNorth(WINDOW* window)
{
  char goal = mvwinch(window, posJ[0]-1, posJ[1]);
  if (goal == 'S')
    mvwaddch(window, 0, 0, ' ');
  else if (goal != 'X' && goal != '-')
  {
    mvwaddch(window,posJ[0],posJ[1], ' ');
    posJ[0]--;
    mvwaddch(window,posJ[0],posJ[1], 'J');
  }
}

void Player::moveEast(WINDOW* window)
{
  char goal = mvwinch(window, posJ[0], posJ[1]+1);
  if (goal == 'S')
    mvwaddch(window, 0, 0, ' ');
  else if (goal != 'X' && goal != '-')
  {
    mvwaddch(window,posJ[0],posJ[1], ' ');
    posJ[1]++;
    mvwaddch(window,posJ[0],posJ[1], 'J');
  }
}

void Player::moveSouth(WINDOW* window)
{
  char goal = mvwinch(window, posJ[0]+1, posJ[1]);
  if (goal == 'S')
    mvwaddch(window, 0, 0, ' ');
  else if (goal != 'X' && goal != '-')
  {
    mvwaddch(window,posJ[0],posJ[1], ' ');
    posJ[0]++;
    mvwaddch(window,posJ[0],posJ[1], 'J');
  }
}

void Player::moveWest(WINDOW* window)
{
  char goal = mvwinch(window, posJ[0], posJ[1]-1);
  if (goal == 'S')
    mvwaddch(window, 0, 0, ' ');
  else if (goal != 'X' && goal != '-')
  {
    mvwaddch(window,posJ[0],posJ[1], ' ');
    posJ[1]--;
    mvwaddch(window,posJ[0],posJ[1], 'J');
  }
}

void Player::action(WINDOW* window, char goal)
{
  if (goal == '*')
    this->numberOfTeleport++;
  else if (goal == '$')
  {/*
    int choixFrontiere{random_data(1,1,6)[0]};
    int i = 0;
    switch (choixFrontiere)
    {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
    }*/
  }
}
