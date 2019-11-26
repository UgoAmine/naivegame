#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include<iostream>

class Element
{
private:
    char symbole;

protected:

public:
    Element(char sym);
    virtual ~Element();
    void getChar();

};

#endif // ELEMENT_H_INCLUDED
