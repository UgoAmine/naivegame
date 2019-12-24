#include "Joueur.hpp"
#include <iostream>




Player::Player(WINDOW* win)
{
    //CREATES A VECTOR OF RANDOM STARTING POS FOR PLAYER
    setpos({random_data(1,2,48)[0],random_data(1,2,98)[0]});

    //PRINTS PLAYER ON ITS INITIAL RANDOM POSITION
    mvwaddch(win,posJ[0],posJ[1], 'J');
    wrefresh(win);
    
}

void Player::move(char c, WINDOW* win){

switch(c)
        {
            case 'z':
                if(mvwinch(win,posJ[0]-1,posJ[1])!='X')
                {
                    mvwaddch(win,posJ[0],posJ[1], ' ');
                    posJ[0]--;
                    mvwaddch(win,posJ[0],posJ[1], 'J');
                }
                break;
            case 'd':
                if(mvwinch(win,posJ[0],posJ[1]+1)!='X')
                {
                    mvwaddch(win,posJ[0],posJ[1], ' ');
                    posJ[1]++;
                    mvwaddch(win,posJ[0],posJ[1], 'J');
                }
                break;
            case 'q':
                if(mvwinch(win,posJ[0],posJ[1]-1)!='X')
                {
                    mvwaddch(win,posJ[0],posJ[1], ' ');
                    posJ[1]--;
                    mvwaddch(win,posJ[0],posJ[1], 'J');
                }
                break;
            case 's':
                if(mvwinch(win,posJ[0]+1,posJ[1])!='X')
                {
                    mvwaddch(win,posJ[0],posJ[1], ' ');
                    posJ[0]++;
                    mvwaddch(win,posJ[0],posJ[1], 'J');
                }
                break;
        }
wrefresh(win);
}

void Player::setpos(std::vector<int> p ) {
    posJ=p;
    }
Player::~Player(){}

