#ifndef ELEMENT
#define ELEMENT

#include <vector>

class Element
{
public:
  
  Element(WINDOW*, char s = 'S');
  virtual ~Element();

  inline std::vector<int> getPos() const {return pos;}
  inline void setPos(const std::vector<int> position) {pos = position;}

  inline int getPosY() const {return pos[0];}
  inline void setPosY(const int ligne) {pos[0] = ligne;}

  inline int getPosX() const {return pos[1];}
  inline void setPosX(const int colonne) {pos[1] = colonne;}


  inline char getSymbol() const {return symbol;}
  inline void setSymbol(const char symbole) {sym = symbol}


private:
  std::vector<int> pos;
  char sym;

};

#endif 
