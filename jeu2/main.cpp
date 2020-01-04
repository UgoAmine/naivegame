
#include "Joueur.hpp"
#include "Monstre.hpp"




int main(int argc, char *argv[])
{
initscr();
noecho();
cbreak();
curs_set(0);
halfdelay(10);
WINDOW * win = newwin(50, 100 , 0 , 0);

Board brd(50,win);
Monstre mst(win);
Player jr(win);

char c;
while(jr.getpos()!=mst.getpos())
{
c=wgetch(win);

mst.move(win);
jr.move(c, win);

    
}

wgetch(win);
endwin();

 
    
    
    return 0;
}
