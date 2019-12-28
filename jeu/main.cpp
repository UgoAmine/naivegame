#include "Joueur.hpp"
#include "Monstre.hpp"
#include <vector>

int main(int argc, char *argv[])
{
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  halfdelay(10);

  char c;

  WINDOW * win = newwin(50, 100 , 0 , 0);
  Board brd(66,win);
  Player jr(win);
  Monstre mst (win);

  while (jr.getpos() != mst.getpos())
  {
    c=wgetch(win);
    mst.move(win);
    jr.move(c, win);
  }

  endwin();

  return 0;
}
