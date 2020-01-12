#ifndef BOARD_H
#define BOARD_H

#include "Porte.hpp"

class Board
{
private:
  int height, width, maxWallSize;
  int numberOfWalls, numberOfDiamDoor, numberOfCharg;
  std::vector<Porte> doorList;
  std::vector<Element> diamList;
  std::vector<Element> chargList;

public:
  Board(WINDOW*);
  ~Board();

  void wallGen(WINDOW*, int, int);
  void borderGen(WINDOW*);
  void doorGen(WINDOW*, int);
  void chargGen(WINDOW*, int);
  void diamGen(WINDOW*, int);

  void doorOpening(WINDOW*);
  void effacer(WINDOW*, int, int);

  inline int                  getHeight()        const {return height;}
  inline int                  getWidth()         const {return height;}
  inline int                  getMaxWallSize()   const {return height;}
  inline int                  getNumberOfWalls() const {return numberOfWalls;}
  inline int                  getNumberOfDoors() const {return numberOfDiamDoor;}
  inline int                  getNumberOfCharg() const {return numberOfCharg;}
  inline int                  getNumberOfDiam()  const {return numberOfDiamDoor;}
  inline std::vector<Porte>   getDoorList()      const {return doorList;}
  inline std::vector<Element> getDiamList()      const {return diamList;}
  inline std::vector<Element> getChargList()     const {return chargList;}

  inline void setHeight       (const int a)                     {height = a;}
  inline void setWidtth       (const int a)                     {width = a;}
  inline void setmaxWallSize  (const int a)                     {maxWallSize = a;}
  inline void setNumberOfWalls(const int a)                     {numberOfWalls = a;}
  inline void setNumberOfDoors(const int a)                     {numberOfDiamDoor = a;}
  inline void setNumberOfCharg(const int a)                     {numberOfCharg = a;}
  inline void setNumberOfDiam (const int a)                     {numberOfDiamDoor = a;}
  inline void setDoorList     (const std::vector<Porte> vect)   {doorList = vect;}
  inline void setDiamList     (const std::vector<Element> vect) {diamList = vect;}
  inline void setChargList    (const std::vector<Element> vect) {chargList = vect;}

};

#endif // Board
