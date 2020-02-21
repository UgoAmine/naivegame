#include "Board.hpp"

#include <fstream>
#include <string>

Board::Board(WINDOW *win) {
    char wall[3];
    char door[3];
    char charg[3];

    do {
        werase(win);

        // On demande à l'utilisateur les paramètres avec lesquels il veut
        // jouer.
        mvwaddstr(win, 0, 0, " Nombre de murs ? ");
        wgetnstr(win, wall, 3);

        mvwaddstr(win, 3, 0, " Nombre de porte ? ");
        wgetnstr(win, door, 3);

        mvwaddstr(win, 6, 0, " Nombre de chargeurs ? ");
        wgetnstr(win, charg, 3);

        // Array-to-Integer
        int nb_wall  = atoi(wall);
        int nb_door  = atoi(door);
        int nb_charg = atoi(charg);

        werase(win);

        // Affiche sur la WINDOW* les paramètres du plateau.
        mvwaddstr(win, 0, 103, " Nombre de murs : ");
        mvwaddstr(win, 3, 103, " Nombre de portes : ");
        mvwaddstr(win, 6, 103, " Nombre de chargeurs : ");
        mvwaddstr(win, 1, 103, wall);
        mvwaddstr(win, 4, 103, door);
        mvwaddstr(win, 7, 103, charg);

        // Appels aux méthodes de génération. wattron/wattroff permettent de
        // colorer les caractères affichés.
        wallGen(win, nb_wall);
        borderGen(win);

        wattron(win, COLOR_PAIR(2));
        doorGen(win, nb_door);
        wattroff(win, COLOR_PAIR(2));

        wattron(win, COLOR_PAIR(4));
        chargGen(win, nb_charg);
        wattroff(win, COLOR_PAIR(4));

        wattron(win, COLOR_PAIR(5));
        diamGen(win, nb_door);
        wattroff(win, COLOR_PAIR(5));

        // Si l'utilisateur n'appuie pas sur 'y', il peut générer un nouveau
        // plateau avec de nouveaux paramètres.
        mvwaddstr(win, 52, 0,
                  "Appuyer sur 'y' pour enregistrer le plateau et commencer le "
                  "jeu ou "
                  "sur n'importe quelle autre touche pour changer de plateau");

    } while (wgetch(win) != 'y');

    // DELETE THE EFFECT OF mvwaddstr qui affiche la phrase "appuyer sur y pour enregistrer la board...."
    wmove(win, 52, 0);
    wclrtoeol(win);

    // Enregistrement du fichier jeu.board suite à l'appui sur la touche 'y'.
    // Il pourra être réutilisé plus tard.
    std::ofstream brd("jeu.board");
    char ln[140];
    for (int i = 0; i < 50; i++) {
        mvwinnstr(win, i, 0, ln, 140);
        std::string ligne(ln);
        brd << ligne;
        brd << "\n";
    }
}

Board::Board(WINDOW *win, std::string str) {
    std::ifstream file(str);
    int           i = 0;
    std::string   line;
    while (std::getline(file, line)) {
        for (int j = 0; j < 140; j++) switch (line.at(j)) {
            case '-': {
                wattron(win, COLOR_PAIR(2));
                mvwaddch(win, i, j, line.at(j));
                wattroff(win, COLOR_PAIR(2));
                Element door(i, j);
                doorList.push_back(door);
            } break;

            case '*':
                wattron(win, COLOR_PAIR(5));
                mvwaddch(win, i, j, line.at(j));
                wattroff(win, COLOR_PAIR(5));
                break;

            case '$':
                wattron(win, COLOR_PAIR(4));
                mvwaddch(win, i, j, line.at(j));
                wattroff(win, COLOR_PAIR(4));
                break;

            default:
                mvwaddch(win, i, j, line.at(j));
                mvwaddch(win, i, j, line.at(j));
            };
        i++;
    }

    // Il est plus facile de créer la liste des portes dans un ordre non
    // aléatoire. On fait donc appel à une méthode shuffle.
    std::random_shuffle(doorList.begin(), doorList.end());
}

void Board::effacer(WINDOW *win, int y, int x) {
    mvwaddch(win, y - 1, x - 1, ' ');
    mvwaddch(win, y - 1, x, ' ');
    mvwaddch(win, y - 1, x + 1, ' ');
    mvwaddch(win, y, x - 1, ' ');
    mvwaddch(win, y, x, ' ');
    mvwaddch(win, y, x + 1, ' ');
    mvwaddch(win, y + 1, x - 1, ' ');
    mvwaddch(win, y + 1, x, ' ');
    mvwaddch(win, y + 1, x + 1, ' ');
}

void Board::doorOpening(WINDOW *win) {
    wattron(win, COLOR_PAIR(3));
    mvwaddch(win, doorList.back().getPos()[0], doorList.back().getPos()[1], '+');
    wattroff(win, COLOR_PAIR(3));
    doorList.pop_back();
}

void Board::wallGen(WINDOW *win, int numberOfWalls) {
    for (int j = 0; j < numberOfWalls; j++) {
        // On tire aléatoirement une taille de mur.
        int wallsize{ random_data(1, 5, 30)[0] };

        // On tire aléatoirement une position de départ pour la construction du
        // mur.
        std::vector<int> rndpos = random_data(1, 2, 47);
        rndpos.push_back(random_data(1, 2, 97)[0]);

        int i = 0;
        int k = 0;
        // On choisit parmi 8 types de murs.
        switch (random_data(1, 1, 8)[0]) {
        case 1:    // HORIZONTAL RIGHT
        {
            while ((i < wallsize) & (rndpos[1] + i < 99)) {
                effacer(win, rndpos[0], rndpos[1] + i);
                i++;
            }
            while ((k < wallsize) & (rndpos[1] + k < 99)) {
                mvwaddch(win, rndpos[0], rndpos[1] + k, 'X');
                k++;
            }
            break;
        }

        case 2:    // HORIZONTAL LEFT
        {
            while ((i < wallsize) & (rndpos[1] - i > 0)) {
                effacer(win, rndpos[0], rndpos[1] - i);
                i++;
            }
            while ((k < wallsize) & (rndpos[1] - k > 0)) {
                mvwaddch(win, rndpos[0], rndpos[1] - k, 'X');
                k++;
            }
            break;
        }

        case 3:    // DOWN VERTICAL
        {
            while ((i < wallsize) & (rndpos[0] + i < 49)) {
                effacer(win, rndpos[0] + i, rndpos[1]);
                i++;
            }
            while ((k < wallsize) & (rndpos[0] + k < 49)) {
                mvwaddch(win, rndpos[0] + k, rndpos[1], 'X');
                k++;
            }
            break;
        }

        case 4:    // UP VERTICAL
        {
            while ((i < wallsize) & (rndpos[0] - i > 0)) {
                effacer(win, rndpos[0] - i, rndpos[1]);
                i++;
            }
            while ((k < wallsize) & (rndpos[0] - k > 0)) {
                mvwaddch(win, rndpos[0] - k, rndpos[1], 'X');
                k++;
            }
            break;
        }

        case 5:    // DIAGONAL DOWN-RIGHT
        {
            while ((i < wallsize) & (rndpos[0] + i < 49) & (rndpos[1] + i < 99)) {
                effacer(win, rndpos[0] + i, rndpos[1] + i);
                i++;
            }
            while ((k < wallsize) & (rndpos[0] + k < 49) & (rndpos[1] + k < 99)) {
                mvwaddch(win, rndpos[0] + k, rndpos[1] + k, 'X');
                k++;
            }
            break;
        }

        case 6:    // DIAGONAL UP-RIGHT
        {
            while ((i < wallsize) & (rndpos[0] - i > 0) & (rndpos[1] + i < 99)) {
                effacer(win, rndpos[0] - i, rndpos[1] + i);
                i++;
            }
            while ((k < wallsize) & (rndpos[0] - k > 0) & (rndpos[1] + k < 99)) {
                mvwaddch(win, rndpos[0] - k, rndpos[1] + k, 'X');
                k++;
            }
            break;
        }

        case 7:    // DIAGONAL UP-LEFT
        {
            while ((i < wallsize) & (rndpos[0] - i > 0) & (rndpos[1] - i > 0)) {
                effacer(win, rndpos[0] - i, rndpos[1] - i);
                i++;
            }
            while ((k < wallsize) & (rndpos[0] - k > 0) & (rndpos[1] - k > 0)) {
                mvwaddch(win, rndpos[0] - k, rndpos[1] - k, 'X');
                k++;
            }
            break;
        }

        case 8:    // DIAGONAL DOWN-LEFT
        {
            while ((i < wallsize) & (rndpos[0] + i < 49) & (rndpos[1] - i > 0)) {
                effacer(win, rndpos[0] + i, rndpos[1] - i);
                i++;
            }
            while ((k < wallsize) & (rndpos[0] + k < 49) & (rndpos[1] - k > 0)) {
                mvwaddch(win, rndpos[0] + k, rndpos[1] - k, 'X');
                k++;
            }
            break;
        }
        }
    }
}

void Board::borderGen(WINDOW *win) {
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 100; j++)
            if ((i == 0) || (i == 49) || (j == 0) || (j == 99)) mvwaddch(win, i, j, 'X');
}

void Board::doorGen(WINDOW *win, int numberOfDiamDoor) {
    for (int i = 0; i < numberOfDiamDoor; i++) {
        // On choisit sur quelle frontière placer une porte.
        // On vérifie de ne pas choisir des coordonnées auxquelles il y a déjà
        // une porte. On crée la liste de porte en même temps.

        std::vector<int> pos;

        switch (random_data(1, 1, 4)[0]) {
        case 1:    // LEFT BORDER
            do {
                pos = { random_data(1, 1, 48)[0], 0 };
            } while ((char)mvwinch(win, pos[0], pos[1]) == '-' ||
                     mvwinch(win, pos[0], pos[1] + 1) == 'X');
            break;
        case 2:    // RIGHT BORDER
            do {
                pos = { random_data(1, 1, 48)[0], 99 };
            } while ((char)mvwinch(win, pos[0], pos[1]) == '-' ||
                     mvwinch(win, pos[0], pos[1] - 1) == 'X');
            break;
        case 3:    // UPPER BORDER
            do {
                pos = { 0, random_data(1, 1, 98)[0] };
            } while ((char)mvwinch(win, pos[0], pos[1]) == '-' ||
                     mvwinch(win, pos[0] + 1, pos[1]) == 'X');
            break;
        case 4:    // BOTTOM BORDER
            do {
                pos = { 49, random_data(1, 1, 98)[0] };
            } while ((char)mvwinch(win, pos[0], pos[1]) == '-' ||
                     mvwinch(win, pos[0] - 1, pos[1]) == 'X');
            break;
        }
        mvwaddch(win, pos[0], pos[1], '-');
        Element door(pos[0], pos[1]);
        doorList.push_back(door);
    }
}

void Board::chargGen(WINDOW *win, int numberOfCharg) {
    for (int i = 0; i < numberOfCharg; i++) Element c(win, '$');
}

void Board::diamGen(WINDOW *win, int numberOfDiamDoor) {
    for (int i = 0; i < numberOfDiamDoor; i++) Element d(win, '*');
}

void Board::PlayerAction(WINDOW *win, Player &jr, char c) {
    switch (c) {
    case 'z': {
        char goal = (char)mvwinch(win, jr.getPos()[0] - 1, jr.getPos()[1]);
        if (goal == '$'){
            jr.setNbTelep(jr.getNbTelep() + 1);
            mvwaddstr(win, 13, 103, std::to_string(jr.getNbTelep()).c_str() );
        }
        else if (goal == '*')
            doorOpening(win);
    } break;
    case 'q': {
        char goal = (char)mvwinch(win, jr.getPos()[0], jr.getPos()[1] - 1);
        if (goal == '$'){
            jr.setNbTelep(jr.getNbTelep() + 1);
            mvwaddstr(win, 13, 103, std::to_string(jr.getNbTelep()).c_str() );
        }
        else if (goal == '*')
            doorOpening(win);
    } break;
    case 's': {
        char goal = (char)mvwinch(win, jr.getPos()[0] + 1, jr.getPos()[1]);
        if (goal == '$'){
            jr.setNbTelep(jr.getNbTelep() + 1);
            mvwaddstr(win, 13, 103, std::to_string(jr.getNbTelep()).c_str() );
        }
        else if (goal == '*')
            doorOpening(win);
    } break;
    case 'd': {
        char goal = (char)mvwinch(win, jr.getPos()[0], jr.getPos()[1] + 1);
        if (goal == '$'){
            jr.setNbTelep(jr.getNbTelep() + 1);
            mvwaddstr(win, 13, 103, std::to_string(jr.getNbTelep()).c_str() );
        }
        else if (goal == '*')
            doorOpening(win);
    } break;
    }
}
