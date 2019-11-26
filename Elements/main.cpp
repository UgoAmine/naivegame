#include <iostream>
#include "Element.hpp"
#include "Mobile.hpp"
#include "Joueur.hpp"
#include "Monstre.hpp"
#include "Mur.hpp"
#include "Porte.hpp"
#include "Diamant.hpp"
#include "Chargeur.hpp"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Joueur a;       a.affiche();
    Monstre b;      b.affiche();
    Mur c;          c.affiche();
    Porte d;        d.affiche();    // SYMBOLE + DE BASE
    Porte e;
    e.ouverture();  e.affiche();    // SYMBOLE - APRES OUVERTURE
    Diamant f;      f.affiche();
    Chargeur g;     g.affiche();

    //Mobile h;     NE FONCTIONNERA PAS CAR CONSTRUCTEUR PROTECTED
    //Element i;    NE FONCTIONNERA PAS CAR CONSTRUCTEUR PROTECTED


    return 0;
}
