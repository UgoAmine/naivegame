#include "Joueur.hpp"
#include <iostream>

bool Perdu(Player j, std::vector<Mobile> mst)
{
  bool b = false;
  for (int i = 0; i < int(mst.size()); i++)
    b = b || (j.getPos() == mst[i].getPos());
  return b;
};

bool isOnBorder(Player j)
{
  return ((j.getPos()[0] == 0)||(j.getPos()[0] == 49)||(j.getPos()[1] == 0)||(j.getPos()[1] == 99));
}

int main(int argc, char *argv[])
{
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  halfdelay(10);

  char c;

  WINDOW* win = newwin(70, 130, 0, 0);
  start_color();
  init_pair(1,COLOR_YELLOW, COLOR_BLACK);
  init_pair(2,COLOR_RED, COLOR_BLACK);
  init_pair(3,COLOR_GREEN, COLOR_BLACK);
  init_pair(4,COLOR_BLUE, COLOR_BLACK);
  init_pair(5,COLOR_CYAN, COLOR_BLACK);

  Board brd(win);

  int numberOfMonsters = 20;

  std::vector<Mobile> monstList;
  for (int i = 0; i < numberOfMonsters; i++)
  {
    wattron(win,COLOR_PAIR(3));
    Mobile m(win);
    monstList.push_back(m);
  }
  wattron(win,COLOR_PAIR(2));
  Player jr(win);

  bool isOnBorder = false;

  while (Perdu(jr, monstList) == false && isOnBorder == false)
  {
    c = wgetch(win);

    //  DEPLACEMENT MONSTRES
    wattron(win,COLOR_PAIR(3));
    for (int i = 0; i < numberOfMonsters; i++)
    {
      switch(random_data(1, 1, 4)[0])
      {
        case 1:
        {
          char goal = mvwinch(win, monstList[i].getPos()[0]-1, monstList[i].getPos()[1]);
          if (goal == ' ' || goal == 'J')
          monstList[i].move(win, 'z');
        }
          break;
        case 2:
        {
          char goal = mvwinch(win, monstList[i].getPos()[0]+1, monstList[i].getPos()[1]);
          if (goal == ' ' || goal == 'J')
          monstList[i].move(win, 's');
        }
          break;
        case 3:
        {
          char goal = mvwinch(win, monstList[i].getPos()[0], monstList[i].getPos()[1]-1);
          if (goal == ' ' || goal == 'J')
          monstList[i].move(win, 'q');
        }
          break;
        case 4:
        {
          char goal = mvwinch(win, monstList[i].getPos()[0], monstList[i].getPos()[1]+1);
          if (goal == ' ' || goal == 'J')
          monstList[i].move(win, 'd');
        }
          break;
      }
    }

    //  DEPLACEMENT JOUEUR
    wattron(win,COLOR_PAIR(2));
    jr.testGoal(win, brd, c);
    jr.move(win, c);
    if (c == 't' && jr.getNbTelep() > 0)
      jr.telepo(win);

    isOnBorder = ((jr.getPos()[0] == 0)||(jr.getPos()[0] == 49)||(jr.getPos()[1] == 0)||(jr.getPos()[1] == 99));
  }


  endwin();

  return 0;
}
