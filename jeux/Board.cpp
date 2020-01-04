#include "Board.hpp"
#include <string>

Board::Board(WINDOW* win): height{50}, width{100}, maxWallSize{33}, numberOfWalls{66}, numberOfDiamDoor{3}, numberOfCharg{10}
{
  wallGen(win, maxWallSize, numberOfWalls);
  borderGen(win);
  doorGen(win, numberOfDiamDoor);
  chargGen(win, numberOfCharg);
  diamGen(win, numberOfDiamDoor);

  wrefresh(win);
}

Board::~Board(){}

void Board::effacer(WINDOW* win, int y, int x)
{
  mvwaddch(win, y-1, x-1, ' ');
  mvwaddch(win, y-1,   x, ' ');
  mvwaddch(win, y-1, x+1, ' ');
  mvwaddch(win, y,   x-1, ' ');
  mvwaddch(win, y,     x, ' ');
  mvwaddch(win, y,   x+1, ' ');
  mvwaddch(win, y+1, x-1, ' ');
  mvwaddch(win, y+1,   x, ' ');
  mvwaddch(win, y+1, x+1, ' ');
}

void Board::doorOpening(WINDOW* win)
{
  mvwaddch(win, doorList.back().getPos()[0],doorList.back().getPos()[1], '+');
  doorList.pop_back();
}

void Board::wallGen(WINDOW* win, int numberOfWalls, int maxWallSize)
{
  for (int j = 0; j < numberOfWalls; j++)
  {
    //  SETTING RANDOM WALL SIZE
    int wallsize{random_data(1,5,maxWallSize)[0]};

    //  SETTING RANDOM STARTING POSITION FOR THE WALL
    std::vector<int> rndpos = random_data(1,2,height-3);
    rndpos.push_back(random_data(1,2,width-3)[0]);

    int i=0;
    int k=0;
    //  CHOOSING A RANDOM TYPE OF WALL
    switch (random_data(1,1,8)[0])
    {
      case 1: //HORIZONTAL RIGHT
      {
        while ((i < wallsize) & (rndpos[1]+i < width-1))
        {
          effacer(win, rndpos[0], rndpos[1]+i);
          i++;
        }
        while ((k < wallsize) & (rndpos[1]+k < width-1))
        {
          mvwaddch(win, rndpos[0], rndpos[1]+k,'X');
          k++;
        }
        break;
      }

      case 2: //HORIZONTAL LEFT
      {
        while ((i < wallsize) & (rndpos[1]-i > 0))
        {
          effacer(win, rndpos[0], rndpos[1]-i);
          i++;
        }
        while ((k < wallsize) & (rndpos[1]-k > 0))
        {
          mvwaddch(win, rndpos[0], rndpos[1]-k,'X');
          k++;
        }
        break;
      }

      case 3: // DOWN VERTICAL
      {
        while ((i < wallsize) & (rndpos[0]+i < height-1))
        {
          effacer(win, rndpos[0]+i, rndpos[1]);
          i++;
        }
        while ((k < wallsize) & (rndpos[0]+k < height-1))
        {
          mvwaddch(win, rndpos[0]+k, rndpos[1],'X');
          k++;
        }
        break;
      }

      case 4: // UP VERTICAL
      {
        while ((i < wallsize) & (rndpos[0]-i > 0))
        {
          effacer(win, rndpos[0]-i, rndpos[1]);
          i++;
        }
        while ((k < wallsize) & (rndpos[0]-k > 0))
        {
          mvwaddch(win, rndpos[0]-k, rndpos[1],'X');
          k++;
        }
        break;
      }

      case 5: // DIAGONAL DOWN-RIGHT
      {
        while ((i < wallsize) & (rndpos[0]+i < height-1) & (rndpos[1]+i < width-1))
        {
          effacer(win, rndpos[0]+i  , rndpos[1]+i);
          i++;
        }
        while ((k < wallsize) & (rndpos[0]+k < height-1) & (rndpos[1]+k < width-1))
        {
          mvwaddch(win, rndpos[0]+k, rndpos[1]+k,'X');
          k++;
        }
        break;
      }

      case 6: // DIAGONAL UP-RIGHT
      {
        while ((i < wallsize) & (rndpos[0]-i > 0) & (rndpos[1]+i < width-1))
        {
          effacer(win, rndpos[0]-i, rndpos[1]+i);
          i++;
        }
        while ((k < wallsize) & (rndpos[0]-k > 0) & (rndpos[1]+k < width-1))
        {
          mvwaddch(win, rndpos[0]-k, rndpos[1]+k,'X');
          k++;
        }
        break;
      }

      case 7: // DIAGONAL UP-LEFT
      {
        while ((i < wallsize) & (rndpos[0]-i > 0) & (rndpos[1]-i > 0))
        {
          effacer(win, rndpos[0]-i, rndpos[1]-i);
          i++;
        }
        while ((k < wallsize) & (rndpos[0]-k > 0) & (rndpos[1]-k > 0))
        {
          mvwaddch(win, rndpos[0]-k, rndpos[1]-k,'X');
          k++;
        }
        break;
      }

      case 8: // DIAGONAL DOWN-LEFT
      {
        while ((i < wallsize) & (rndpos[0]+i < height-1) & (rndpos[1]-i > 0))
        {
          effacer(win, rndpos[0]+i  , rndpos[1]-i);
          i++;
        }
        while ((k < wallsize) & (rndpos[0]+k < height-1) & (rndpos[1]-k > 0))
        {
          mvwaddch(win, rndpos[0]+k, rndpos[1]-k,'X');
          k++;
        }
        break;
      }
    }
  }
}

void Board::borderGen(WINDOW* win)
{
  for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
      if ((i == 0) || (i == height-1) || (j == 0) || (j == width-1))
        mvwaddch(win, i, j, 'X');
}

void Board::doorGen(WINDOW* win, int numberOfDiamDoor)
{
  for(int i = 0; i < numberOfDiamDoor; i++)
  {
    Porte p(win);
    doorList.push_back(p);
  }
}

void Board::chargGen(WINDOW* win, int numberOfCharg)
{
  for(int i = 0; i < numberOfCharg; i++)
  {
    Element c(win, '$');
    chargList.push_back(c);
  }
}

void Board::diamGen(WINDOW* win, int numberOfDiamDoor)
{
  for(int i = 0; i < numberOfDiamDoor; i++)
  {
    Element d(win, '*');
    diamList.push_back(d);
  }
}
