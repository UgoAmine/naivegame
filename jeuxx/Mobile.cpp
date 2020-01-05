#include "Mobile.hpp"

Mobile::Mobile(WINDOW* win, char s): Element(win, s){}

void Mobile::move(WINDOW* win, char input)
{
  switch(input)
    {
        case 'z':
            if(mvwinch(win,pos[0]-1,pos[1])!='X' && mvwinch(win,pos[0]-1,pos[1])!='-')
            {
                mvwaddch(win,pos[0],pos[1], ' ');
                pos[0]--;
                mvwaddch(win,pos[0],pos[1], sym);
            }
            break;
        case 'd':
            if(mvwinch(win,pos[0],pos[1]+1)!='X' && mvwinch(win,pos[0],pos[1]+1)!='-')
            {
                mvwaddch(win,pos[0],pos[1], ' ');
                pos[1]++;
                mvwaddch(win,pos[0],pos[1], sym);
            }
            break;
        case 'q':
            if(mvwinch(win,pos[0],pos[1]-1)!='X' && mvwinch(win,pos[0],pos[1]-1)!='-')
            {
                mvwaddch(win,pos[0],pos[1], ' ');
                pos[1]--;
                mvwaddch(win,pos[0],pos[1], sym);
            }
            break;
        case 's':
            if(mvwinch(win,pos[0]+1,pos[1])!='X' && mvwinch(win,pos[0]+1,pos[1])!='-')
            {
                mvwaddch(win,pos[0],pos[1], ' ');
                pos[0]++;
                mvwaddch(win,pos[0],pos[1], sym);
            }
            break;
    }
  wrefresh(win);
}

Mobile::~Mobile(){}
