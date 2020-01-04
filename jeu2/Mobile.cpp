#include "Mobile.hpp"
#include "Element.hpp"


Mobile::Mobile(WINDOW* win): Element(win){}

void Mobile::move(char input, Window* win)
{

switch(c)
        {
            case 'z':
                if(mvwinch(win,pos[0]-1,pos[1])!='X')
                {
                    mvwaddch(win,pos[0],pos[1], ' ');
                    pos[0]--;
                    mvwaddch(win,pos[0],pos[1], sym);
                }
                break;
            case 'd':
                if(mvwinch(win,pos[0],pos[1]+1)!='X')
                {
                    mvwaddch(win,pos[0],pos[1], ' ');
                    pos[1]++;
                    mvwaddch(win,pos[0],pos[1], sym);
                }
                break;
            case 'q':
                if(mvwinch(win,pos[0],pos[1]-1)!='X')
                {
                    mvwaddch(win,pos[0],pos[1], ' ');
                    pos[1]--;
                    mvwaddch(win,pos[0],pos[1], sym);
                }
                break;
            case 's':
                if(mvwinch(win,pos[0]+1,pos[1])!='X')
                {
                    mvwaddch(win,pos[0],pos[1], ' ');
                    pos[0]++;
                    mvwaddch(win,pos[0],pos[1], sym);
                }
                break;
        }
wrefresh(win);
}

}

