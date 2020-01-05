#include "Porte.hpp"

Porte::Porte(WINDOW* win)
{
  sym = '-';
  switch(random_data(1,1,4)[0])
  {
    case 1: // LEFT BORDER
      do {pos = {random_data(1, 1, 48)[0], 0};}
      while (mvwinch(win, pos[0], pos[1]) == '-' || mvwinch(win, pos[0], pos[1]+1) == 'X');
      break;
    case 2: // RIGHT BORDER
      do {pos = {random_data(1, 1, 48)[0], 99};}
      while (mvwinch(win, pos[0], pos[1]) == '-' || mvwinch(win, pos[0], pos[1]-1) == 'X');
      break;
    case 3: // UPPER BORDER
      do {pos = {0, random_data(1, 1, 98)[0]};}
      while (mvwinch(win, pos[0], pos[1]) == '-' || mvwinch(win, pos[0]+1, pos[1]) == 'X');
      break;
    case 4: // BOTTOM BORDER
      do {pos = {49, random_data(1, 1, 98)[0]};}
      while (mvwinch(win, pos[0], pos[1]) == '-' || mvwinch(win, pos[0]-1, pos[1]) == 'X');
      break;
  }
  mvwaddch(win, pos[0], pos[1], sym);
}

Porte::~Porte(){}
