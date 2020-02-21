#ifndef MOBILE_H
#define MOBILE_H

#include "Element.hpp"

class Mobile : public Element {
public:
    // Voir la description du constructeur d'Élément.
    Mobile(WINDOW *, char s = 'S');
    
    // Destructeur virtuel par défaut
    virtual ~Mobile() = default;
    
    // Méthode permettant de déplacer le contenu d'une case dans la direction
    // indiquée par char : z = Nord, d = Est, q = Ouest, s = Sud.
    void move(WINDOW *, char);
};

#endif /* MOBILE_H */
