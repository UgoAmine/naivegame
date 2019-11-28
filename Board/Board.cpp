#include "Board.hpp"

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

Board::Board()
{// setting border walls and voids in the board
    for (int i = 0; i < 30; i++) 
    {
        for (int j = 0; j < 30; j++) 
        {
            if ( (i==0) || (i==29) || (j == 0) || (j == 29) ) 
            {
                brd[i][j]='X';
            }
            else 
            {
            brd[i][j]=' ';
            }
        }
    }
}

void Board::wallgen()
{// wall generator method
int i=0;

int wallsize{random_data(1,2,30)[0]}; //setting random wall size

std::vector<int> rndpos = random_data(2,2,27); //settin random starting point of the wall

switch (random_data(1,1,4)[0]) //choose a random type of wall
    {
    case 1: // to the right horizontal
        while ( (i < wallsize) & (i+rndpos[1] < 29)) 
        {
            brd [rndpos[0]   ] [rndpos[1] +i] ='X';
            brd [rndpos[0] +1] [rndpos[1] +i] =' ';
            brd [rndpos[0] -1] [rndpos[1] +i] =' ';
            i++;
        };
        break;
    case 2: // down vertical
        while ((i<wallsize) & (i+rndpos[0] < 29) ) 
        {
            brd [rndpos[0] +i] [rndpos[1]   ] ='X';
            brd [rndpos[0] +i] [rndpos[1] +1] =' ';
            brd [rndpos[0] +i] [rndpos[1] -1] =' ';
            i++;
        };
        break;
    case 3: // diagonal down-right
        while ( (rndpos[0]+i+1<29) & (rndpos[1]+i+1<29) & (i< wallsize) ) 
        {
            brd [rndpos[0] +i  ] [rndpos[1]  +i  ] ='X';
            brd [rndpos[0] +i  ] [rndpos[1]  +i-1] =' ';
            brd [rndpos[0] +i-1] [rndpos[1]  +i  ] =' ';
            brd [rndpos[0] +i+1] [rndpos[1]  +i-1] =' ';
            brd [rndpos[0] +i-1] [rndpos[1]  +i+1] =' ';
            i++;
        };
        break;
    case 4: //diagonal up-right
            while ( (i<wallsize) & (rndpos[0]-i-1>0) & (rndpos[1]+i+1<29) )
            {
             
             brd [rndpos[0] -i  ] [rndpos[1] +i  ] ='X';
             brd [rndpos[0] -i-1] [rndpos[1] +i  ] =' ';
             brd [rndpos[0] -i  ] [rndpos[1] +i+1] =' ';
             brd [rndpos[0] -i-1] [rndpos[1] +i-1] =' ';
             brd [rndpos[0] -i+1] [rndpos[1] +i+1] =' ';
             i++;
            };
        break;
    }
}


void Board::prt() //print board
{
    for (int i =0  ; i < 30; i++) 
    {
        for (int j = 0; j < 30; j++) 
        {
            if (j==29) 
            {
            print(brd[i][j])<< std::endl;
            }
            else 
            {
            print(brd[i][j]);
            }   
        }
       
    }
}
   
Board::~Board(){};



