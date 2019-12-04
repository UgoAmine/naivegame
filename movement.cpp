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
    initscr();
    cbreak();
    noecho();
    halfdelay(10);

    int ch = 'I'; //RANDOM INIT TO ENTER THE LOOP
    int height = 60;
    int width = 120;
    int nbMonstres = 20;
    int nbMurs = 200;

    //GENERATES WALLS OF RANDOM SIZE AND TYPE
    for(int j=0; j<nbMurs; j++)
    {
        int i=0;
        //GENERATES A WALL SIZE BETWEEN 5 AND 15
        int wallSize = random_data(1,5,15)[0];
        //GENERATES RANDOM STARTING POS FOR WALLS
        std::vector<int> posW = {random_data(1, 2, height-3)[0], random_data(1, 2, width-3)[0]};


        switch(random_data(1,0,3)[0])
        {
        case 0: //RIGHT HORIZONTAL
            while ((i < wallSize)&(posW[1]+i < width-2))
            {
                mvaddch(posW[0]-1,posW[1]+i, ' ');
                mvaddch(posW[0]+1,posW[1]+i, ' ');
                mvaddch(posW[0],posW[1]+i, 'W');
                i++;
            }
            break;
        case 1: //DOWN VERTICAL
            while ((i < wallSize)&(posW[0]+i < height-2))
            {
                mvaddch(posW[0]+i,posW[1]+1, ' ');
                mvaddch(posW[0]+i,posW[1]-1, ' ');
                mvaddch(posW[0]+i,posW[1], 'W');
                i++;
            }
            break;
        case 2: //DOWN-RIGHT DIAGONAL
            while ((i < wallSize)&(posW[1]+i+1 < width-1)&(posW[0]+i+1 < height-2))
            {
                mvaddch(posW[0]+i, posW[1]+i, 'W');
                mvaddch(posW[0]+i-1, posW[1]+i, ' ');
                mvaddch(posW[0]+i, posW[1]+i+1, ' ');
                mvaddch(posW[0]+i, posW[1]+i-1, ' ');
                mvaddch(posW[0]+i+1, posW[1]+i, ' ');
                i++;
            }
            break;
        case 3: //UP-RIGHT DIAGONAL
            while ((i < wallSize)&(posW[0]-i-1 > 0)&(posW[1]+i+1 < width-2))
            {
                mvaddch(posW[0]-i, posW[1]+i, 'W');
                mvaddch(posW[0]+i-1, posW[1]+i, ' ');
                mvaddch(posW[0]+i, posW[1]+i+1, ' ');
                mvaddch(posW[0]+i, posW[1]+i-1, ' ');
                mvaddch(posW[0]+i+1, posW[1]+i, ' ');
                i++;
            }
            break;
        }
    }

    //GENERATES BORDERS
    for(int i=0; i<height;i++)
        for(int j=0; j<width; j++)
            if((i==0)||(i==height-1)||(j==0)||(j==width-1)) mvaddch(i,j, 'X');


    //GENERATES RANDOM STARTING COORDINATES FOR MONSTERS
    //INITIALLY RANDOM, THEN UPDATED ACCORDING TO MONSTERS MOVEMENT
    //THERE MAY BE OVERLAPPING
    std::vector<std::vector<int>> posM;
    for(int i=0; i<nbMonstres; i++)
        posM.push_back({random_data(1,1,height-2)[0],random_data(1,1,width-2)[0]});

    //PRINTS MONSTERS ON THEIR INITIAL STARTING POSITIONS
    for(int i=0; i<nbMonstres; i++)
            mvaddch(posM[i][0], posM[i][1], 's');

    //CREATES A VECTOR OF RANDOM STARTING POS FOR PLAYER
    //INITIALLY RANDOM, THEN UPDATED ACCORDING TO PLAYER MOVEMENT
    std::vector<int> posJ = {random_data(1,1,height-2)[0],random_data(1,1,width-2)[0]};

    //PRINTS PLAYER ON ITS INITIAL RANDOM POSITION
    mvaddch(posJ[0],posJ[1], 'J');

    while(ch!='o') //RANDOM CONDITION TO STAY IN THE LOOP
    {
        ch=getch();

        //CREATES A RANDOM VECTOR TO DETERMINE HOW MONSTERS MOVE EACH STEP
        // 0 = UP, 1 = RIGHT, 2 = DOWN, 3 = LEFT
        std::vector<int> stepM = random_data(nbMonstres,0,3);

        //MOVES PLAYER ACCORDING TO KEYBOARD INPUT, CHECKS CONFLICTS
        switch(ch)
        {
            case 'z':
                if(mvinch(posJ[0]-1,posJ[1])==' ')
                {
                    mvaddch(posJ[0],posJ[1], ' ');
                    posJ[0]--;
                    mvaddch(posJ[0],posJ[1], 'J');
                }
                break;
            case 'd':
                if(mvinch(posJ[0],posJ[1]+1)==' ')
                {
                    mvaddch(posJ[0],posJ[1], ' ');
                    posJ[1]++;
                    mvaddch(posJ[0],posJ[1], 'J');
                }
                break;
            case 'q':
                if(mvinch(posJ[0],posJ[1]-1)==' ')
                {
                    mvaddch(posJ[0],posJ[1], ' ');
                    posJ[1]--;
                    mvaddch(posJ[0],posJ[1], 'J');
                }
                break;
            case 's':
                if(mvinch(posJ[0]+1,posJ[1])==' ')
                {
                    mvaddch(posJ[0],posJ[1], ' ');
                    posJ[0]++;
                    mvaddch(posJ[0],posJ[1], 'J');
                }
                break;
        }

        //MOVES MONSTERS ACCORDING TO stepM
        for(int i=0; i<nbMonstres;i++)
            switch(stepM[i])
            {
                case 0:
                    if(mvinch(posM[i][0]-1,posM[i][1])==' ')
                    {
                        mvaddch(posM[i][0],posM[i][1], ' ');
                        posM[i][0]--;
                        mvaddch(posM[i][0],posM[i][1], 's');
                    }
                    break;
                case 1:
                    if(mvinch(posM[i][0],posM[i][1]+1)==' ')
                    {
                        mvaddch(posM[i][0],posM[i][1], ' ');
                        posM[i][1]++;
                        mvaddch(posM[i][0],posM[i][1], 's');
                    }
                    break;
                case 2:
                    if(mvinch(posM[i][0]+1,posM[i][1])==' ')
                    {
                        mvaddch(posM[i][0],posM[i][1], ' ');
                        posM[i][0]++;
                        mvaddch(posM[i][0],posM[i][1], 's');
                    }
                    break;
                case 3:
                    if(mvinch(posM[i][0],posM[i][1]-1)==' ')
                    {
                        mvaddch(posM[i][0],posM[i][1], ' ');
                        posM[i][1]--;
                        mvaddch(posM[i][0],posM[i][1], 's');
                    }
                    break;
            }

        move(posJ[0],posJ[1]);
    }

    endwin();               // Restaure les paramètres par défaut du terminal

    return 0;
}
