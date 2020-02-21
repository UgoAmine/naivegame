#ifndef JOUEUR_H
#define JOUEUR_H

#include "Mobile.hpp"

class Player : public Mobile {
public:
    // Voir la description du constructeur d'Élément.
    Player(WINDOW *);

    // Destructeur
    virtual ~Player();

    inline const int &getNbTelep() const { return nbtelep; }
    inline void       setNbTelep(const int &tel) { nbtelep = tel; }

    // Méthode qui permet de téléporter le joueur sur une case vide.
    void telepo(WINDOW *);

    // Méthode qui vérifie si le joueur se situe sur une frontière (et donc a
    // traversé une porte ouverte).
    bool isOnBorder();

    // Méthode qui vérifie si le joueur a les mêmes coordonnées qu'un monstre
    // (et donc a perdu.)
    bool perdu(std::vector<Mobile>);

private:
    // Nombre de téléportations dont le joueur dispose.
    int nbtelep;
};

#endif    // JOUEUR_H
