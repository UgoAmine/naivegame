#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <random>     // mt19937 (Mersene Twister) and uniform_int_distribution
#include <algorithm>  // generate (used for random data)
#include <vector>     // vector
#include <iterator>   // begin, end, and ostream_iterator
#include <functional> // bind (used for random data generator)
#include <ncurses.h>

std::vector<int> random_data(int n , int a, int b); //random data generator function(number of data, lower bound, upperbound )

class Board
{
private:
  int height, width, maxWallSize;
  int numberOfWalls, numberOfDoors, numberOfCharg, numberOfDiam;

public:
  Board(WINDOW*);
  ~Board();

  void wallGen(WINDOW*, int, int, int, int);
  void borderGen(WINDOW*, int, int);
  void doorGen(WINDOW*, int, int, int);
  void chargGen(WINDOW*, int, int, int);
  void diamGen(WINDOW*, int, int, int);

  void effacer(WINDOW*, int, int);

  inline int getHeight() const {return height;}
  inline int getWidth() const {return height;}
  inline int getMaxWallSize() const {return height;}
  inline int getNumberOfWalls() const {return numberOfWalls;}
  inline int getNumberOfDoors() const {return numberOfDoors;}
  inline int getNumberOfCharg() const {return numberOfCharg;}
  inline int getNumberOfDiam() const {return numberOfDiam;}

  inline void setHeight(const int a) {height = a;}
  inline void setWidtth(const int a) {width = a;}
  inline void setmaxWallSize(const int a) {maxWallSize = a;}
  inline void setNumberOfWalls(const int a) {numberOfWalls = a;}
  inline void setNumberOfDoors(const int a) {numberOfDoors = a;}
  inline void setNumberOfCharg(const int a) {numberOfCharg = a;}
  inline void setNumberOfDiam(const int a) {numberOfDiam = a;}

};

#endif // Board
