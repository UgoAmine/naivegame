#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <cstdlib>
#include <random>     // mt19937 (Mersene Twister) and uniform_int_distribution
#include <algorithm>  // generate (used for random data)
#include <vector>     // vector
#include <iterator>   // begin, end, and ostream_iterator
#include <functional> // bind (used for random data generator)

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

int main(void)
{
    initscr();              // Initialise la structure WINDOW et autres param
    cbreak();
    noecho();
    halfdelay(10);

    int ch = 's';
    int dimFenetre = 60;
    int nbMonstres = 20;

    //GENERATES BORDERS
    for(int i=0; i<dimFenetre;i++)
        for(int j=0; j<dimFenetre; j++)
            ((i==0)||(i==dimFenetre-1)||(j==0)||(j==dimFenetre-1)) ? mvaddch(i,j, 'X') : mvaddch(i,j, ' ');

    //CREATES A VECTOR OF RANDOM STARTING POS FOR MONSTERS
    //INITIALLY RANDOM, THEN UPDATED ACCORDING TO MONSTERS MOVEMENT
    //THERE MAY BE OVERLAPPING
    std::vector<std::vector<int>> posM;
    for(int i=0;i<nbMonstres;i++)
        posM.push_back(random_data(2,1,dimFenetre-2));

    //PRINTS MONSTERS ON THEIR INITIAL STARTING POSITIONS
    for(int i=0; i<nbMonstres; i++)
            mvaddch(posM[i][0], posM[i][1], 'S');

    //CREATES A VECTOR OF RANDOM STARTING POS FOR PLAYER
    //INITIALLY RANDOM, THEN UPDATED ACCORDING TO PLAYER MOVEMENT
    std::vector<int> posJ = random_data(2,1,dimFenetre-2);

    //PRINTS PLAYER ON ITS INITIAL RANDOM POSITION
    mvaddch(posJ[0],posJ[1], 'J');

    while(ch!='o')
    {
        ch=getch();

        //CREATES A RANDOM VECTOR TO DETERMINE HOW MONSTERS MOVE EACH STEP
        // 0 = UP, 1 = RIGHT, 2 = DOWN, 3 = LEFT
        std::vector<int> movM = random_data(nbMonstres,0,3);

        //UPDATES posM ACCORDING TO movM
        for(int i=0; i<nbMonstres;i++)
            switch(movM[i])
            {
                case 0:
                    mvaddch(posM[i][0],posM[i][1], ' ');
                    posM[i][0]--;
                    mvaddch(posM[i][0],posM[i][1], 's');
                    break;
                case 1:
                    mvaddch(posM[i][0],posM[i][1], ' ');
                    posM[i][1]++;
                    mvaddch(posM[i][0],posM[i][1], 's');
                    break;
                case 2:
                    mvaddch(posM[i][0],posM[i][1], ' ');
                    posM[i][0]++;
                    mvaddch(posM[i][0],posM[i][1], 's');
                    break;
                case 3:
                    mvaddch(posM[i][0],posM[i][1], ' ');
                    posM[i][1]--;
                    mvaddch(posM[i][0],posM[i][1], 's');
                    break;
            }

        //ALLOWS THE PLAYER TO MOVE BUT ERASES EVERYTHING IN ITS PATH
        switch(ch)
        {
            case 'z':
                mvaddch(posJ[0],posJ[1], ' ');
                posJ[0]--;
                mvaddch(posJ[0],posJ[1], 'J');
                break;
            case 'd':
                mvaddch(posJ[0],posJ[1], ' ');
                posJ[1]++;
                mvaddch(posJ[0],posJ[1], 'J');
                break;
            case 'q':
                mvaddch(posJ[0],posJ[1], ' ');
                posJ[1]--;
                mvaddch(posJ[0],posJ[1], 'J');
                break;
            case 's':
                mvaddch(posJ[0],posJ[1], ' ');
                posJ[0]++;
                mvaddch(posJ[0],posJ[1], 'J');
                break;
        }

        move(posJ[0],posJ[1]);
    }

    endwin();               // Restaure les paramètres par défaut du terminal

    return 0;
}
