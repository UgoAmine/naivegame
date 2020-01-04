#include "Monstre.hpp"
#include <iostream>


Monstre::Monstre(WINDOW* win)
{
    //CREATES A VECTOR OF RANDOM STARTING POS FOR MONSTER
    setpos({random_data(1,2,48)[0],random_data(1,2,98)[0]});

    //PRINTS MONSTER ON ITS INITIAL RANDOM POSITION
    mvwaddch(win, posM[0],posM[1], 'S');
}

Monstre::~Monstre(){}

void Monstre::setpos(const std::vector<int> p) {posM = p;}

void Monstre::move(WINDOW* win)
{
  switch(random_data(1,1,4)[0])
  {
    case 1:
        this->moveNorth(win);
      break;
    case 2:
        this->moveEast(win);
      break;
    case 3:
        this->moveSouth(win);
      break;
    case 4:
        this->moveWest(win);
      break;
  }
  wrefresh(win);
}

void Monstre::moveNorth(WINDOW* window)
{
  char goal = mvwinch(window, posM[0]-1, posM[1]);
  if (goal == 'J')
    mvwaddch(window, 0, 0, ' ');
  else if ((goal != 'X') && (goal != '+') && (goal != '-'))
  {
    mvwaddch(window,posM[0],posM[1], ' ');
    posM[0]--;
    mvwaddch(window,posM[0],posM[1], 'S');
  }
}

void Monstre::moveEast(WINDOW* window)
{
  char goal = mvwinch(window, posM[0], posM[1]+1);
  if (goal == 'J')
    mvwaddch(window, 0, 0, ' ');
  else if ((goal != 'X') && (goal != '+') && (goal != '-'))
  {
    mvwaddch(window,posM[0],posM[1], ' ');
    posM[1]++;
    mvwaddch(window,posM[0],posM[1], 'S');
  }
}

void Monstre::moveSouth(WINDOW* window)
{
  char goal = mvwinch(window, posM[0]+1, posM[1]);
  if (goal == 'J')
    mvwaddch(window, 0, 0, ' ');
  else if ((goal != 'X') && (goal != '+') && (goal != '-'))
  {
    mvwaddch(window,posM[0],posM[1], ' ');
    posM[0]++;
    mvwaddch(window,posM[0],posM[1], 'S');
  }
}

void Monstre::moveWest(WINDOW* window)
{
  char goal = mvwinch(window, posM[0], posM[1]-1);
  if (goal == 'J')
    mvwaddch(window, 0, 0, ' ');
  else if ((goal != 'X') && (goal != '+') && (goal != '-'))
  {
    mvwaddch(window,posM[0],posM[1], ' ');
    posM[1]--;
    mvwaddch(window,posM[0],posM[1], 'S');
  }
}
