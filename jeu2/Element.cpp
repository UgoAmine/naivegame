#include "Element.hpp"


ElementW::Element(WINDOW* win, char s): sym{s}, pos{random_data(1,2,48)[0],random_data(1,2,98)[0]} 
{
    while mvwinch(win,po[0],pos[1])!=' '
    pos = {random_data(1,2,48)[0],random_data(1,2,98)[0]} 

    //PRINTS PLAYER ON ITS INITIAL RANDOM POSITION
    mvwaddch(win,pos[0],pos[1], sym);
    wrefresh(win);
    
}

Element::~Element(){} 
