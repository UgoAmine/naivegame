#include "Porte.hpp"
#include <iostream>

Porte::Porte()
{
    this->symbole = '+';
}

Porte::~Porte(){}

void Porte::ouverture()
{
    symbole = '-';
}
