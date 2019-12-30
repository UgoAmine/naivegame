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

  WINDOW* win = newwin(70, 130, 0, 0);
  /* Bien que la map soit de largeur 100, on rajoute quelques colonnes/lignes
     pour s'autoriser à écrire des choses quant à l'état du jeu.
  */
  Board brd(win);
  Player jr(win);
  Monstre mst (win);

  while (mvwinch(win, 0, 0) == 'X')
  {
    c = wgetch(win);
    mst.move(win);
    jr.move(c, win);
  }

  endwin();

  return 0;
}
