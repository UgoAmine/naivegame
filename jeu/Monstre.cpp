#include "Monstre.hpp"
#include <iostream>


Monstre::Monstre(WINDOW* win)
{
    //CREATES A VECTOR OF RANDOM STARTING POS FOR MONSTER
    setpos({random_data(1,2,48)[0],random_data(1,2,98)[0]});

    //PRINTS MONSTER ON ITS INITIAL RANDOM POSITION
    mvwaddch(win, posM[0],posM[1], 's');
}

void Monstre::move(WINDOW* win)
{
    switch(random_data(1,1,4)[0])
            {
                case 1:
                    if(mvwinch(win,posM[0]-1,posM[1])==' ')
                    {
                        mvwaddch(win,posM[0],posM[1], ' ');
                        posM[0]--;
                        mvwaddch(win,posM[0],posM[1], 'S');
                    }
                    break;
                case 2:
                    if(mvwinch(win,posM[0],posM[1]+1)!='X')
                    {
                        mvwaddch(win,posM[0],posM[1], ' ');
                        posM[1]++;
                        mvwaddch(win,posM[0],posM[1], 'S');
                    }
                    break;
                case 3:
                    if(mvwinch(win,posM[0]+1,posM[1])!='X')
                    {
                        mvwaddch(win,posM[0],posM[1], ' ');
                        posM[0]++;
                        mvwaddch(win,posM[0],posM[1], 'S');
                    }
                    break;
                case 4:
                    if(mvwinch(win,posM[0],posM[1]-1)!='X')
                    {
                        mvwaddch(win,posM[0],posM[1], ' ');
                        posM[1]--;
                        mvwaddch(win,posM[0],posM[1], 'S');
                    }
                    break;
            }
wrefresh(win);
}

void Monstre::setpos(std::vector<int> p) {
    posM=p;
}

Monstre::~Monstre(){}
