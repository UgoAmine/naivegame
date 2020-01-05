#ifndef ELEMENT
#define ELEMENT

#include <vector>
#include "ncurses.h"
#include <iostream>
#include <random>     // mt19937 (Mersene Twister) and uniform_int_distribution
#include <algorithm>  // generate (used for random data)
#include <vector>     // vector
#include <iterator>   // begin, end, and ostream_iterator
#include <functional> // bind (used for random data generator)
#include <ncurses.h>

std::vector<int> random_data(int n, int a, int b); //random data generator function(number of data, lower bound, upperbound )

class Element
{
public:

  Element();
  Element(WINDOW*, char s);
  virtual ~Element();

  std::vector<int> getPos() const;
  void setPos(const std::vector<int>);

  char getSym() const;
  void setSym(const char);

protected:
  std::vector<int> pos;
  char sym;

};

#endif
