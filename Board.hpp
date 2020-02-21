#ifndef BOARD_H
#define BOARD_H

#include "Joueur.hpp"

class Board {
public:
    // Construit une Board sur laquelle jouer.
    // On demande à l'utilisateur différents paramètres pour créer la Board.
    // Il est possible d'enregistrer une Board.
    Board(WINDOW *);

    // Construit un Board qui correspond au plateau de jeu enregistré dans le
    // fichier.board. L'argument std::string est le nom de ce fichier.
    Board(WINDOW *, std::string);

    // Destructeur virtuel par défaut
    virtual ~Board() = default;
    
    // Les méthodes suivantes apparaissent dans l'ordre dans lequel elles sont
    // appelées dans le (1er) constructeur de Board. L'argument int correspond
    // aux nombres respectifs d'objets qui doivent être créés.
    void wallGen(WINDOW *, int);
    void borderGen(WINDOW *);
    void doorGen(WINDOW *, int);
    void chargGen(WINDOW *, int);
    void diamGen(WINDOW *, int);

    // Méthode qui détermine l'action a effectuer si le joueur prend un diamant
    // ou un chargeur.Cette méthode est appelée avant d'effectivement déplacer
    // le joueur. Le char correspond à la direction dans laquelle le joueur sera
    // déplacé après le test effectué.
    void PlayerAction(WINDOW *, Player &, char);

    // Méthode qui accède au dernier élément de doorList, change son symbole en
    // '+' (la porte s'ouvre), et la retire de la liste.
    void doorOpening(WINDOW *);

    // Méthode qui efface, dans la WINDOW*, les 9 cases centrées en la position
    // (int, int) donnée en argument. Cette méthode est appelée avant d'afficher
    // un mur.
    void effacer(WINDOW *, int, int);

private:
    // Vecteur d'Élément. Il contient des Éléments qui jouent le rôle des portes
    std::vector<Element> doorList;
};

#endif    // Board
