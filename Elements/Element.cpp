#include "Element.hpp"
#include <iostream>

Element::Element(){}

Element::~Element(){}

void Element::affiche()
{
    std::cout << this->symbole << std::endl;;
}
