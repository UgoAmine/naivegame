#include "Element.hpp"

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

Element::Element(){}

Element::Element(WINDOW* win, char s)
{
  sym = s;
  do {pos = {random_data(1,1,48)[0],random_data(1,1,98)[0]};}
  while (mvwinch(win,pos[0],pos[1]) != ' ');

  //PRINTS ELEMENT ON ITS INITIAL RANDOM POSITION
  mvwaddch(win,pos[0],pos[1], sym);
  wrefresh(win);
}

Element::~Element(){}

std::vector<int> Element::getPos() const {return pos;}
void Element::setPos(std::vector<int> position) {pos = position;}

char Element::getSym() const {return sym;}
void Element::setSym(const char c) {sym = c;}
