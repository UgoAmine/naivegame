#include "Joueur.hpp"
#include <iostream>

bool Perdu(Player j, std::vector<Mobile> mst)
{
  bool b = false;
  for (int i = 0; i < int(mst.size()); i++)
    b = b || (j.getPos() == mst[i].getPos());
  return b;
};


int main(int argc, char *argv[])
{
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  halfdelay(10);

  char c;

  WINDOW* win = newwin(70, 130, 0, 0);
  Board brd(win);
  int numberOfMonsters = 1;

  std::vector<Mobile> monstList;
  for (int i = 0; i < numberOfMonsters; i++)
  {
    Mobile m(win);
    monstList.push_back(m);
  }

  Player jr(win);

  while (Perdu(jr, monstList) == false)
  {
    c = wgetch(win);

    //  DEPLACEMENT MONSTRES
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
    jr.testGoal(win, brd, c);
    jr.move(win, c);
    if (c == 't' && jr.getNbTelep() > 0)
      jr.telepo(win);
  }

  endwin();

  return 0;
}
