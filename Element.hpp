#ifndef ELEMENT
#define ELEMENT

#include <ncurses.h>
#include <algorithm>     // generate (used for random data)
#include <functional>    // bind (used for random data generator)
#include <iostream>
#include <iterator>    // begin, end, and ostream_iterator
#include <random>      // mt19937 (Mersene Twister) and uniform_int_distribution
#include <vector>
#include "ncurses.h"

std::vector<int> random_data(int n, int a, int b);
// random data generator function(number of data, lower bound, upperbound).

class Element {
public:
    // Ce constructeur tires aléatoirement des coordonnées jusqu'à en trouver
    // qui correspondent à une case vide de la WINDOW*. Elle initialise
    // l'attribut pos en conséquence et print le char sur la WINDOW*.
    Element(WINDOW *, char s);

    // Construit un Élément et initialise l'attribut pos par le vecteur {int,
    // int} donné en argument. Lorsqu'il est utilisé, il n'est pas utile de
    // vérifier que les coordonnées correspondent à une case vide.
    Element(int, int);

    // Destructeur
    virtual ~Element();

    // Getterdu vecteur de position.
    inline std::vector<int> getPos() const { return pos; }

protected:
    // Position à laquelle sera affiché l'élément (sur une WINDOW* donnée).
    std::vector<int> pos;

    // Symbole affiché (sur une WINDOW* donnée).
    char sym;
};

#endif
