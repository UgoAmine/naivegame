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

Board::Board(int nbwall)
{// setting border walls and voids in the board
int height{50}, width{100}, maxwallsize{100};

initscr();
noecho();
cbreak();
WINDOW * win = newwin(height, width , 0 , 0);
refresh();
    
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
         (i==0) || (i==height-1) || (j==0) || (j== width - 1) ? mvwaddch(win,i,j,'X') : mvwaddch(win,i,j,' ');

// wall generator
        
for (int j=0; j< nbwall; j++){ ; 
int wallsize{random_data(1,2,maxwallsize)[0]}; //setting random wall size

std::vector<int> rndpos = random_data(1,2,height-3);//setting random starting point of the wall
rndpos.push_back(random_data(1,2,width-1)[0]); 

int i=0;
switch (random_data(1,1,4)[0]) //choose a random type of wall
    {
    case 1: // to the right horizontal
        while ( (i < wallsize) & (i+rndpos[1] < width - 1))
        {
            mvwaddch(win, rndpos[0]  , rndpos[1]+i, 'X'); 
            mvwaddch(win, rndpos[0]+1, rndpos[1]+i, ' '); 
            mvwaddch(win, rndpos[0]-1, rndpos[1]+i, ' '); 
            i++;
        };
        break;
    case 2: // down vertical
        while ((i<wallsize) & (i+rndpos[0] < height - 1) )
        {
            mvwaddch(win, rndpos[0]+i, rndpos[1]  , 'X'); 
            mvwaddch(win, rndpos[0]+i, rndpos[1]+1, ' '); 
            mvwaddch(win, rndpos[0]+i, rndpos[1]-1, ' '); 
            i++;
        };
        break;
    case 3: // diagonal down-right
        while ( (rndpos[0]+i< height-2) & (rndpos[1]+i< width-2) & (i< wallsize) )
        {
            mvwaddch(win, rndpos[0]+i  , rndpos[1]+i  , 'X'); 
            mvwaddch(win, rndpos[0]+i  , rndpos[1]+i-1, ' '); 
            mvwaddch(win, rndpos[0]+i-1, rndpos[1]+i  , ' '); 
            mvwaddch(win, rndpos[0]+i+1, rndpos[1]+i-1, ' '); 
            mvwaddch(win, rndpos[0]+i-1, rndpos[1]+i+1, ' '); 
            i++;
        };
        break;
    case 4: //diagonal up-right
            while ( (i<wallsize) & (rndpos[0]-i-1>0) & (rndpos[1]+i+1< width -1) )
            {
            mvwaddch(win, rndpos[0]-i  , rndpos[1]+i  , 'X'); 
            mvwaddch(win, rndpos[0]-i-1, rndpos[1]+i  , ' '); 
            mvwaddch(win, rndpos[0]-i  , rndpos[1]+i+1, ' '); 
            mvwaddch(win, rndpos[0]-i-1, rndpos[1]+i-1, ' '); 
            mvwaddch(win, rndpos[0]-i+1, rndpos[1]+i+1, ' '); 
            i++;
            };
        break;
    }
}
wrefresh(win);
wgetch(win);
endwin();

}

Board::Board()
{
    Board(50);
}


Board::~Board(){} 
