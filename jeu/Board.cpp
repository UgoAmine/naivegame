#include "Board.hpp"
#include <string>

#define print(x) std::cout<< x


std::vector<int> random_data(int n , int a, int b) //random data generator function(number of data, lower bound, upperbound )
{
  std::random_device r;
  std::seed_seq      seed{r(), r(), r(), r(), r(), r(), r(), r()};
  std::mt19937       eng(seed); // a source of random data
  std::uniform_int_distribution<int> dist(a,b);
  std::vector<int> v(n);

  generate(begin(v), end(v), bind(dist, eng));
  return v;
}

Board::Board(WINDOW* win)
{
  int height{50}, width{100}, maxWallSize{33}, numberOfWalls{66};
  int numberOfDoors{10}, numberOfCharg{10}, numberOfDiam{20};

  wallGen(win, height, width, maxWallSize, numberOfWalls);
  borderGen(win, height, width);
  doorGen(win, height, width, numberOfDoors);
  chargGen(win, height, width, numberOfCharg);
  diamGen(win, height, width, numberOfDiam);

  wrefresh(win);

}

Board::~Board(){}

void Board::effacer(WINDOW* fenetre, int y, int x)
{
  mvwaddch(fenetre, y-1, x-1, ' ');
  mvwaddch(fenetre, y-1,   x, ' ');
  mvwaddch(fenetre, y-1, x+1, ' ');
  mvwaddch(fenetre, y,   x-1, ' ');
  mvwaddch(fenetre, y,     x, ' ');
  mvwaddch(fenetre, y,   x+1, ' ');
  mvwaddch(fenetre, y+1, x-1, ' ');
  mvwaddch(fenetre, y+1,   x, ' ');
  mvwaddch(fenetre, y+1, x+1, ' ');
}

void Board::wallGen(WINDOW* fenetre, int hauteur, int largeur, int nombreDeMurs, int tailleMurMax)
{
  for (int j = 0; j < nombreDeMurs; j++)
  {
    //  SETTING RANDOM WALL SIZE
    int wallsize{random_data(1,5,tailleMurMax)[0]};

    //  SETTING RANDOM STARTING POSITION FOR THE WALL
    std::vector<int> rndpos = random_data(1,2,hauteur-3);
    rndpos.push_back(random_data(1,2,largeur-3)[0]);

    int i=0;
    int k=0;
    //  CHOOSING A RANDOM TYPE OF WALL
    switch (random_data(1,1,8)[0])
    {
      case 1: //HORIZONTAL RIGHT
      {
        while ((i < wallsize) & (rndpos[1]+i < largeur-1))
        {
          effacer(fenetre, rndpos[0], rndpos[1]+i);
          i++;
        }
        while ((k < wallsize) & (rndpos[1]+k < largeur-1))
        {
          mvwaddch(fenetre, rndpos[0], rndpos[1]+k,'X');
          k++;
        }
        break;
      }

      case 2: //HORIZONTAL LEFT
      {
        while ((i < wallsize) & (rndpos[1]-i > 0))
        {
          effacer(fenetre, rndpos[0], rndpos[1]-i);
          i++;
        }
        while ((k < wallsize) & (rndpos[1]-k > 0))
        {
          mvwaddch(fenetre, rndpos[0], rndpos[1]-k,'X');
          k++;
        }
        break;
      }

      case 3: // DOWN VERTICAL
      {
        while ((i < wallsize) & (rndpos[0]+i < hauteur-1))
        {
          effacer(fenetre, rndpos[0]+i, rndpos[1]);
          i++;
        }
        while ((k < wallsize) & (rndpos[0]+k < hauteur-1))
        {
          mvwaddch(fenetre, rndpos[0]+k, rndpos[1],'X');
          k++;
        }
        break;
      }

      case 4: // UP VERTICAL
      {
        while ((i < wallsize) & (rndpos[0]-i > 0))
        {
          effacer(fenetre, rndpos[0]-i, rndpos[1]);
          i++;
        }
        while ((k < wallsize) & (rndpos[0]-k > 0))
        {
          mvwaddch(fenetre, rndpos[0]-k, rndpos[1],'X');
          k++;
        }
        break;
      }

      case 5: // DIAGONAL DOWN-RIGHT
      {
        while ((i < wallsize) & (rndpos[0]+i < hauteur-1) & (rndpos[1]+i < largeur-1))
        {
          effacer(fenetre, rndpos[0]+i  , rndpos[1]+i);
          i++;
        }
        while ((k < wallsize) & (rndpos[0]+k < hauteur-1) & (rndpos[1]+k < largeur-1))
        {
          mvwaddch(fenetre, rndpos[0]+k, rndpos[1]+k,'X');
          k++;
        }
        break;
      }

      case 6: // DIAGONAL UP-RIGHT
      {
        while ((i < wallsize) & (rndpos[0]-i > 0) & (rndpos[1]+i < largeur-1))
        {
          effacer(fenetre, rndpos[0]-i, rndpos[1]+i);
          i++;
        }
        while ((k < wallsize) & (rndpos[0]-k > 0) & (rndpos[1]+k < largeur-1))
        {
          mvwaddch(fenetre, rndpos[0]-k, rndpos[1]+k,'X');
          k++;
        }
        break;
      }

      case 7: // DIAGONAL UP-LEFT
      {
        while ((i < wallsize) & (rndpos[0]-i > 0) & (rndpos[1]-i > 0))
        {
          effacer(fenetre, rndpos[0]-i, rndpos[1]-i);
          i++;
        }
        while ((k < wallsize) & (rndpos[0]-k > 0) & (rndpos[1]-k > 0))
        {
          mvwaddch(fenetre, rndpos[0]-k, rndpos[1]-k,'X');
          k++;
        }
        break;
      }

      case 8: // DIAGONAL DOWN-LEFT
      {
        while ((i < wallsize) & (rndpos[0]+i < hauteur-1) & (rndpos[1]-i > 0))
        {
          effacer(fenetre, rndpos[0]+i  , rndpos[1]-i);
          i++;
        }
        while ((k < wallsize) & (rndpos[0]+k < hauteur-1) & (rndpos[1]-k > 0))
        {
          mvwaddch(fenetre, rndpos[0]+k, rndpos[1]-k,'X');
          k++;
        }
        break;
      }
    }
  }
}

void Board::borderGen(WINDOW* fenetre, int hauteur, int largeur)
{
  for (int i = 0; i < hauteur; i++)
    for (int j = 0; j < largeur; j++)
      if ((i == 0) || (i == hauteur-1) || (j == 0) || (j == largeur-1))
        mvwaddch(fenetre, i, j, 'X');
}

void Board::doorGen(WINDOW* fenetre, int hauteur, int largeur, int nombreDePortes)
{
  for(int i = 0; i < nombreDePortes; i++)
  {
    int choixFrontiere{random_data(1,1,6)[0]};

    switch(choixFrontiere)
    {
      case 1: // LEFT BORDER
      {
        int rndPosDoor{random_data(1, 1, hauteur-2)[0]};
        while (mvwinch(fenetre, rndPosDoor, 1)!= ' ')
          rndPosDoor = random_data(1, 1, hauteur-2)[0];
        mvwaddch(fenetre, rndPosDoor, 0, '-');
      };
      break;
      case 2: // RIGHT BORDER
      {
        int rndPosDoor{random_data(1, 1, hauteur-2)[0]};
        while (mvwinch(fenetre, rndPosDoor, largeur-2)!= ' ')
          rndPosDoor = random_data(1, 1, hauteur-2)[0];
        mvwaddch(fenetre, rndPosDoor, largeur-1, '-');
      };
      break;
      case 3: // UPPER BORDER
      {
        int rndPosDoor{random_data(1, 1, largeur-2)[0]};
        while (mvwinch(fenetre, 1, rndPosDoor)!= ' ')
          rndPosDoor = random_data(1, 1, hauteur-2)[0];
        mvwaddch(fenetre, 0, rndPosDoor, '-');
      };
      break;
      case 4: // UPPER BORDER TOO, same code as case 3.
      {
        int rndPosDoor{random_data(1, 1, largeur-2)[0]};
        while (mvwinch(fenetre, 1, rndPosDoor)!= ' ')
          rndPosDoor = random_data(1, 1, hauteur-2)[0];
        mvwaddch(fenetre, 0, rndPosDoor, '-');
      };
      break;
      case 5: // BOTTOM BORDER
      {
        int rndPosDoor{random_data(1, 1, largeur-2)[0]};
        while (mvwinch(fenetre, hauteur-2, rndPosDoor)!= ' ')
          rndPosDoor = random_data(1, 1, hauteur-2)[0];
        mvwaddch(fenetre, hauteur-1, rndPosDoor, '-');
      };
      break;
      case 6: // BOTTOM BORDER TOO, same code as case 5.
      {
        int rndPosDoor{random_data(1, 1, largeur-2)[0]};
        while (mvwinch(fenetre, hauteur-2, rndPosDoor)!= ' ')
          rndPosDoor = random_data(1, 1, hauteur-2)[0];
        mvwaddch(fenetre, hauteur-1, rndPosDoor, '-');
      };
      break;
    }
  }
}

void Board::chargGen(WINDOW* fenetre, int hauteur, int largeur, int nombreDeChargeurs)
{
  for (int i = 0; i < nombreDeChargeurs; i++)
  {
    std::vector<int> rndposdiams{random_data(1, 1, hauteur-2)[0]};
    rndposdiams.push_back(random_data(1, 1, largeur-2)[0]);
    while(mvwinch(fenetre, rndposdiams[0], rndposdiams[1])!= ' ')
    {
      rndposdiams[0] = random_data(1, 1, hauteur-2)[0];
      rndposdiams[1] = random_data(1, 1, largeur-2)[0];
    }
    mvwaddch(fenetre, rndposdiams[0], rndposdiams[1], '*');
  }
}

void Board::diamGen(WINDOW* fenetre, int hauteur, int largeur, int nombreDeDiamants)
{
  for(int j = 0; j < nombreDeDiamants; j++)
  {
    std::vector<int> rndposdiams{random_data(1, 1, hauteur-2)[0]};
    rndposdiams.push_back(random_data(1, 1, largeur-2)[0]);
    while(mvwinch(fenetre, rndposdiams[0], rndposdiams[1])!= ' ')
    {
      rndposdiams[0] = random_data(1, 1, hauteur-2)[0];
      rndposdiams[1] = random_data(1, 1, largeur-2)[0];
    }
    mvwaddch(fenetre, rndposdiams[0], rndposdiams[1], '$');
  }
}
