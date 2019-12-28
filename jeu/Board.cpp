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

Board::Board(int nbwall, WINDOW* win) : nbTelep(0), nbCharg(0)
{
  int height{50}, width{100}, maxwallsize{33}, nbdoor{10}, nbdiams{10}, nbchargeur{10};

  /* Ici, nous faisons le choix de créer d'abord les murs, puis les frontières.
     En effet, leur implémentation effacerait des frontières si celles-ci étaient
     déjà présentes.
     Il semble redondant de coder HORIZONTAL LEFT et HORIZONTAL RIGHT, mais en
     codant seulement 4 types de murs (pour les 4 orientations), nous n'obtenions
     pas un répartition symétrique des murs. La répartition n'est cependant pas
     uniforme. */

  // WALLS GENERATION
  for (int j = 0; j < nbwall; j++)
  {
    //  SETTING RANDOM WALL SIZE
    int wallsize{random_data(1,5,maxwallsize)[0]};

    //  SETTING RANDOM STARTING POSITION FOR THE WALL
    std::vector<int> rndpos = random_data(1,2,height-3);
    rndpos.push_back(random_data(1,2,width-3)[0]);

    int i=0;
    //  CHOOSING A RANDOM TYPE OF WALL
    switch (random_data(1,1,8)[0])
    {
      case 1: //HORIZONTAL RIGHT
      {
        mvwaddch(win, rndpos[0]-1, rndpos[1]-1, ' ');
        mvwaddch(win, rndpos[0],   rndpos[1]-1, ' ');
        mvwaddch(win, rndpos[0]+1, rndpos[1]-1, ' ');
        while ((i < wallsize) & (rndpos[1]+i < width - 1))
        {
          mvwaddch(win, rndpos[0]  , rndpos[1]+i, 'X');
          mvwaddch(win, rndpos[0]+1, rndpos[1]+i, ' ');
          mvwaddch(win, rndpos[0]-1, rndpos[1]+i, ' ');
          i++;
        }
        mvwaddch(win, rndpos[0]-1, rndpos[1]+i+1, ' ');
        mvwaddch(win, rndpos[0],   rndpos[1]+i+1, ' ');
        mvwaddch(win, rndpos[0]+1, rndpos[1]+i+1, ' ');
        break;
      }

      case 2: //HORIZONTAL LEFT
      {
        mvwaddch(win, rndpos[0]-1, rndpos[1]+1, ' ');
        mvwaddch(win, rndpos[0],   rndpos[1]+1, ' ');
        mvwaddch(win, rndpos[0]+1, rndpos[1]+1, ' ');
        while ((i < wallsize) & (rndpos[1]-i > 0))
        {
          mvwaddch(win, rndpos[0]  , rndpos[1]-i, 'X');
          mvwaddch(win, rndpos[0]+1, rndpos[1]-i, ' ');
          mvwaddch(win, rndpos[0]-1, rndpos[1]-i, ' ');
          i++;
        }
        mvwaddch(win, rndpos[0]-1, rndpos[1]-i-1, ' ');
        mvwaddch(win, rndpos[0],   rndpos[1]-i-1, ' ');
        mvwaddch(win, rndpos[0]+1, rndpos[1]-i-1, ' ');
        break;
      }

      case 3: // DOWN VERTICAL
      {
        mvwaddch(win, rndpos[0]-1, rndpos[1]-1, ' ');
        mvwaddch(win, rndpos[0]-1,   rndpos[1], ' ');
        mvwaddch(win, rndpos[0]-1, rndpos[1]+1, ' ');
        while ((i < wallsize) & (rndpos[0]+i < height-1))
        {
          mvwaddch(win, rndpos[0]+i, rndpos[1]  , 'X');
          mvwaddch(win, rndpos[0]+i, rndpos[1]+1, ' ');
          mvwaddch(win, rndpos[0]+i, rndpos[1]-1, ' ');
          i++;
        }
        mvwaddch(win, rndpos[0]+i+1, rndpos[1]-1, ' ');
        mvwaddch(win, rndpos[0]+i+1,   rndpos[1], ' ');
        mvwaddch(win, rndpos[0]+i+1, rndpos[1]+1, ' ');
        break;
      }

      case 4: // UP VERTICAL
      {
        mvwaddch(win, rndpos[0]+1, rndpos[1]-1, ' ');
        mvwaddch(win, rndpos[0]+1,   rndpos[1], ' ');
        mvwaddch(win, rndpos[0]+1, rndpos[1]+1, ' ');
        while ((i < wallsize) & (rndpos[0]-i > 0))
        {
          mvwaddch(win, rndpos[0]-i, rndpos[1]  , 'X');
          mvwaddch(win, rndpos[0]-i, rndpos[1]+1, ' ');
          mvwaddch(win, rndpos[0]-i, rndpos[1]-1, ' ');
          i++;
        }
        mvwaddch(win, rndpos[0]-i-1, rndpos[1]-1, ' ');
        mvwaddch(win, rndpos[0]-i-1,   rndpos[1], ' ');
        mvwaddch(win, rndpos[0]-i-1, rndpos[1]+1, ' ');
        break;
      }

      case 5: // DIAGONAL DOWN-RIGHT
      {
        mvwaddch(win, rndpos[0]-1, rndpos[1]-1, ' ');
        while ((i < wallsize) & (rndpos[0]+i < height-1) & (rndpos[1]+i < width-1))
        {
          mvwaddch(win, rndpos[0]+i  , rndpos[1]+i  , 'X');
          mvwaddch(win, rndpos[0]+i  , rndpos[1]+i-1, ' ');
          mvwaddch(win, rndpos[0]+i-1, rndpos[1]+i  , ' ');
          mvwaddch(win, rndpos[0]+i+1, rndpos[1]+i-1, ' ');
          mvwaddch(win, rndpos[0]+i-1, rndpos[1]+i+1, ' ');
          i++;
        }
        mvwaddch(win, rndpos[0]+i+1, rndpos[1]+i+1, ' ');
        break;
      }

      case 6: // DIAGONAL UP-RIGHT
      {
        mvwaddch(win, rndpos[0]+1, rndpos[1]-1, ' ');
        while ((i < wallsize) & (rndpos[0]-i > 0) & (rndpos[1]+i < width-1))
        {
          mvwaddch(win, rndpos[0]-i  , rndpos[1]+i  , 'X');
          mvwaddch(win, rndpos[0]-i-1, rndpos[1]+i  , ' ');
          mvwaddch(win, rndpos[0]-i  , rndpos[1]+i+1, ' ');
          mvwaddch(win, rndpos[0]-i-1, rndpos[1]+i-1, ' ');
          mvwaddch(win, rndpos[0]-i+1, rndpos[1]+i+1, ' ');
          i++;
        }
        mvwaddch(win, rndpos[0]-i-1, rndpos[1]+i+1, ' ');
        break;
      }

      case 7: // DIAGONAL UP-LEFT
      {
        mvwaddch(win, rndpos[0]+1, rndpos[1]+1, ' ');
        while ((i < wallsize) & (rndpos[0]-i > 0) & (rndpos[1]-i > 0))
        {
          mvwaddch(win, rndpos[0]-i  , rndpos[1]+i  , 'X');
          mvwaddch(win, rndpos[0]-i-1, rndpos[1]+i  , ' ');
          mvwaddch(win, rndpos[0]-i  , rndpos[1]+i+1, ' ');
          mvwaddch(win, rndpos[0]-i-1, rndpos[1]+i-1, ' ');
          mvwaddch(win, rndpos[0]-i+1, rndpos[1]+i+1, ' ');
          i++;
        }
        mvwaddch(win, rndpos[0]-i-1, rndpos[1]-i-1, ' ');
        break;
      }

      case 8: // DIAGONAL DOWN-LEFT
      {
        mvwaddch(win, rndpos[0]-1, rndpos[1]+1, ' ');
        while ((i < wallsize) & (rndpos[0]+i < height-1) & (rndpos[1]-i > 0))
        {
          mvwaddch(win, rndpos[0]-i  , rndpos[1]+i  , 'X');
          mvwaddch(win, rndpos[0]-i-1, rndpos[1]+i  , ' ');
          mvwaddch(win, rndpos[0]-i  , rndpos[1]+i+1, ' ');
          mvwaddch(win, rndpos[0]-i-1, rndpos[1]+i-1, ' ');
          mvwaddch(win, rndpos[0]-i+1, rndpos[1]+i+1, ' ');
          i++;
        }
        mvwaddch(win, rndpos[0]+i+1, rndpos[1]-i-1, ' ');
        break;
      }
    }
  }

  // SETTING BORDER WALLS
  for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
      if ((i==0) || (i==height-1) || (j==0) || (j== width - 1))
        mvwaddch(win,i,j,'X');

  /* Nous voulons d'abord choisir aléatoirement sur quel bord créer des portes.
     Nous prenons en compte le fait que les frontières horizontales sont deux
     fois plus longues que les verticales.
     Une fois le bord choisis, nous tirons aléatoirement un mur qui sera
     transformé en porte fermée (tant que cette porte n'est pas bloquée par un
     mur classique)
  */

  // DOORS GENERATION
  for(int i = 0; i < nbdoor; i++)
  {
    int choixFrontiere{random_data(1,1,6)[0]};

    switch(choixFrontiere)
    {
      case 1: // LEFT BORDER
      {
        int rndPosDoor{random_data(1, 1, 48)[0]};
        while (mvwinch(win, rndPosDoor, 1)!= ' ')
          rndPosDoor = random_data(1, 1, 48)[0];
        mvwaddch(win, rndPosDoor, 0, '-');
      };
      break;
      case 2: // RIGHT BORDER
      {
        int rndPosDoor{random_data(1, 1, 48)[0]};
        while (mvwinch(win, rndPosDoor, 98)!= ' ')
          rndPosDoor = random_data(1, 1, 48)[0];
        mvwaddch(win, rndPosDoor, 99, '-');
      };
      break;
      case 3: // UPPER BORDER
      {
        int rndPosDoor{random_data(1, 1, 98)[0]};
        while (mvwinch(win, 1, rndPosDoor)!= ' ')
          rndPosDoor = random_data(1, 1, 48)[0];
        mvwaddch(win, 0, rndPosDoor, '-');
      };
      break;
      case 4: // UPPER BORDER TOO, same code
      {
        int rndPosDoor{random_data(1, 1, 98)[0]};
        while (mvwinch(win, 1, rndPosDoor)!= ' ')
          rndPosDoor = random_data(1, 1, 48)[0];
        mvwaddch(win, 0, rndPosDoor, '-');
      };
      break;
      case 5: // BOTTOM BORDER
      {
        int rndPosDoor{random_data(1, 1, 98)[0]};
        while (mvwinch(win, 48, rndPosDoor)!= ' ')
          rndPosDoor = random_data(1, 1, 48)[0];
        mvwaddch(win, 49, rndPosDoor, '-');
      };
      break;
      case 6: // BOTTOM BORDER TOO, same code
      {
        int rndPosDoor{random_data(1, 1, 98)[0]};
        while (mvwinch(win, 48, rndPosDoor)!= ' ')
          rndPosDoor = random_data(1, 1, 48)[0];
        mvwaddch(win, 49, rndPosDoor, '-');
      };
      break;
    }
  }

  // DIAMS GENERATION
  for(int j = 0; j < nbdiams; j++)
  {
    std::vector<int> rndposdiams{random_data(1, 1, 48)[0]};
    rndposdiams.push_back(random_data(1, 1, 98)[0]);
    while(mvwinch(win, rndposdiams[0], rndposdiams[1])!= ' ')
    {
      rndposdiams[0] = random_data(1, 1, 48)[0];
      rndposdiams[1] = random_data(1, 1, 98)[0];
    }
    mvwaddch(win, rndposdiams[0], rndposdiams[1], '$');
  }

  // CHARG GENERATION
  for (int k = 0; k < nbchargeur; k++)
  {
    std::vector<int> rndposdiams{random_data(1, 1, 48)[0]};
    rndposdiams.push_back(random_data(1, 1, 98)[0]);
    while(mvwinch(win, rndposdiams[0], rndposdiams[1])!= ' ')
    {
      rndposdiams[0] = random_data(1, 1, 48)[0];
      rndposdiams[1] = random_data(1, 1, 98)[0];
    }
    mvwaddch(win, rndposdiams[0], rndposdiams[1], '*');
  }

  wrefresh(win);

  mvwaddch(win, 10, 10, '+'); //POUR TESTER SORTIE DE BOUCLE DU MAIN

}

Board::~Board(){}
