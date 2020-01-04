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
      if (mvwinch(win, posJ[0]-1, posJ[1]) == '$')
        this->doorOpening(win, mvwinch(win, posJ[0]-1, posJ[1]));
      else if (mvwinch(win, posJ[0]-1, posJ[1]) == '*')
        numberOfTeleport++;
      break;
    case 'd': //  EAST
      this->moveEast(win);
      if (mvwinch(win, posJ[0], posJ[1]+1) == '$')
        this->doorOpening(win, mvwinch(win, posJ[0]-1, posJ[1]));
      else if (mvwinch(win, posJ[0], posJ[1]+1) == '*')
        numberOfTeleport++;
      break;
    case 'q': //  WEST
      this->moveWest(win);
      if (mvwinch(win, posJ[0], posJ[1]-1) == '$')
        this->doorOpening(win, mvwinch(win, posJ[0], posJ[1]-1));
      else if (mvwinch(win, posJ[0], posJ[1]-1) == '*')
        numberOfTeleport ++;
      break;
    case 's': //  SOUTH
      this->moveSouth(win);
      if (mvwinch(win, posJ[0]+1, posJ[1]) == '$')
        this->doorOpening(win, mvwinch(win, posJ[0]+1, posJ[1]));
      else if (mvwinch(win, posJ[0]+1, posJ[1]) == '*')
        numberOfTeleport++;
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

void Player::doorOpening(WINDOW* window, char goal)
{
  bool doorFound{false};
  while (doorFound == false) //  UNTIL A DOOR IS FOUND
  {
    int choixFrontiere{random_data(1,1,6)[0]};
    switch (choixFrontiere)
    {
      case 1: //  LEFT BORDER
      {
        int posFrontiere{random_data(1, 1, 48)[0]};
        wmove(window, posFrontiere, 0);
        if (posFrontiere % 2 == 0) // CHECKS DOORS ABOVE POS
        {
          int j{0};
          while (j < posFrontiere && mvwinch(window, posFrontiere-j, 0) != '+')
            j++;
          if (j < posFrontiere)
            mvwaddch(window, posFrontiere-j, 0, '+');
            doorFound = true;
        }
        else // CHECKS DOOR UNDER POS
        {
          int j{0};
          while (j < 49 - posFrontiere && mvwinch(window, posFrontiere+j, 0) != '+')
            j++;
          if (j < 49 - posFrontiere)
            mvwaddch(window, posFrontiere+j, 0, '+');
            doorFound = true;
        }
      }
        break;
      case 2: //  RIGHT BORDER
      {
        int posFrontiere{random_data(1, 1, 48)[0]};
        wmove(window, posFrontiere, 99);
        if (posFrontiere % 2 == 0) // CHECKS DOORS ABOVE POS
        {
          int j{0};
          while (j < posFrontiere && mvwinch(window, posFrontiere-j, 99) != '+')
            j++;
          if (j < posFrontiere)
            mvwaddch(window, posFrontiere-j, 99, '+');
            doorFound = true;
        }
        else // CHECKS DOOR UNDER POS
        {
          int j{0};
          while (j < 49 - posFrontiere && mvwinch(window, posFrontiere+j, 99) != '+')
            j++;
          if (j < 49 - posFrontiere)
            mvwaddch(window, posFrontiere+j, 99, '+');
            doorFound = true;
        }
      }
        break;
      case 3: //  UPPER BORDER
      {
        int posFrontiere{random_data(1, 1, 98)[0]};
        wmove(window, 0, posFrontiere);
        if (posFrontiere % 2 == 0) // CHECKS DOORS LEFT OF POS
        {
          int j{0};
          while (j < posFrontiere && mvwinch(window, 0, posFrontiere-j) != '+')
            j++;
          if (j < posFrontiere)
            mvwaddch(window, 0, posFrontiere-j, '+');
            doorFound = true;
        }
        else // CHECKS DOOR RIGHT OF POS
        {
          int j{0};
          while (j < 99 - posFrontiere && mvwinch(window, 0, posFrontiere+j) != '+')
            j++;
          if (j < 99 - posFrontiere)
            mvwaddch(window, 0, posFrontiere+j, '+');
            doorFound = true;
        }
      }
        break;
      case 4: //  UPPER BORDER (SAME CODE AS CASE 3)
      {
        int posFrontiere{random_data(1, 1, 98)[0]};
        wmove(window, 0, posFrontiere);
        if (posFrontiere % 2 == 0) // CHECKS DOORS LEFT OF POS
        {
          int j{0};
          while (j < posFrontiere && mvwinch(window, 0, posFrontiere-j) != '+')
            j++;
          if (j < posFrontiere)
            mvwaddch(window, 0, posFrontiere-j, '+');
            doorFound = true;
        }
        else // CHECKS DOOR RIGHT OF POS
        {
          int j{0};
          while (j < 99 - posFrontiere && mvwinch(window, 0, posFrontiere+j) != '+')
            j++;
          if (j < 99 - posFrontiere)
            mvwaddch(window, 0, posFrontiere+j, '+');
            doorFound = true;
        }
      }
        break;
      case 5: //  BOTTOM BORDER
      {
        int posFrontiere{random_data(1, 1, 98)[0]};
        wmove(window, 49, posFrontiere);
        if (posFrontiere % 2 == 0) // CHECKS DOORS LEFT OF POS
        {
          int j{0};
          while (j < posFrontiere && mvwinch(window, 49, posFrontiere-j) != '+')
            j++;
          if (j < posFrontiere)
            mvwaddch(window, 49, posFrontiere-j, '+');
            doorFound = true;
        }
        else // CHECKS DOOR RIGHT OF POS
        {
          int j{0};
          while (j < 99 - posFrontiere && mvwinch(window, 49, posFrontiere+j) != '+')
            j++;
          if (j < 99 - posFrontiere)
            mvwaddch(window, 49, posFrontiere+j, '+');
            doorFound = true;
        }
      }
        break;
      case 6: //  BOTTOM BORDER (SAME CODE AS CASE 5)
      {
        int posFrontiere{random_data(1, 1, 98)[0]};
        wmove(window, 49, posFrontiere);
        if (posFrontiere % 2 == 0) // CHECKS DOORS LEFT OF POS
        {
          int j{0};
          while (j < posFrontiere && mvwinch(window, 49, posFrontiere-j) != '+')
            j++;
          if (j < posFrontiere)
            mvwaddch(window, 49, posFrontiere-j, '+');
            doorFound = true;
        }
        else // CHECKS DOOR RIGHT OF POS
        {
          int j{0};
          while (j < 99 - posFrontiere && mvwinch(window, 49, posFrontiere+j) != '+')
            j++;
          if (j < 99 - posFrontiere)
            mvwaddch(window, 49, posFrontiere+j, '+');
            doorFound = true;
        }
      }
        break;
    }
  }
}
