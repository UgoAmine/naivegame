#include "Element.h"
#include <iostream>


Element::Element(char sym) : symbole{sym}
{
    std::cout << "Construction reussie" << std::endl;
}

Element::~Element(){}

void Element::getChar()
{
    std::cout << this->symbole << std::endl;
}
