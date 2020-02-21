#include "Jeu.hpp"
#include <cstdlib>

namespace fs = std::filesystem;

Jeu::Jeu(int argc, char* argv[]) {
    initscr();
    cbreak();
    curs_set(0);

    win = newwin(70, 140, 0, 0);
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);

    // Le joueur peut choisir le nombre de monstres.
    
    char nbmst[3];
    int numberOfMonsters; 
    
    // Fonction pour le choix du nombre de monstres
    auto choixMonstres = [&]() {
        mvwaddstr(win, 0, 0, "Choisissez le nombre de monstres : \n");
        wgetnstr(win, nbmst, 3);
        numberOfMonsters= atoi(nbmst);
    };
    // Détermine quel constructeur de Board appeler, selon la présence
    // d'arguments.
    if (1 < argc) {
        fs::path f(argv[1]);
        if (fs::exists(f) && f.extension().string() == ".board") {
            choixMonstres();
            brd = new Board(win, argv[1]);
        } else {
            endwin();
            std::cerr << "Le fichier est invalide ou inexistant.\n";
            std::exit(1);
        }
    } else {
        choixMonstres();    
        brd = new Board(win);
    }

    mvwaddstr(win, 9, 103, "nombre de monstres : ");
    mvwaddstr(win, 10, 103, nbmst);
    
    
    
    noecho();
    halfdelay(10);

    // Création de la liste de monstres en tant que Mobiles.
    std::vector<Mobile> monstList;

    for (int i = 0; i < numberOfMonsters; i++) {
        wattron(win, COLOR_PAIR(3));
        Mobile m(win);
        wattroff(win, COLOR_PAIR(3));
        monstList.push_back(m);
    }

    // Création du Joueur.
    wattron(win, COLOR_PAIR(2));
    Player jr(win);
    wattroff(win, COLOR_PAIR(2));
    
    mvwaddstr(win, 12, 103, "nombre de téléportations : ");
    mvwaddstr(win, 13, 103, std::to_string(jr.getNbTelep()).c_str() );

    // Boucle principale. Sortie quand le Joueur est mort ou a gagné.
    char c;
    while (!jr.perdu(monstList) && !jr.isOnBorder()) {
        c = wgetch(win);

        //  DEPLACEMENT MONSTRES
        wattron(win, COLOR_PAIR(3));
        for (int i = 0; i < numberOfMonsters; i++) {
            switch (random_data(1, 1, 4)[0]) {
            case 1: {
                char goal =
                    (char)mvwinch(win, monstList[i].getPos()[0] - 1, monstList[i].getPos()[1]);
                if (goal == ' ' || goal == 'J') monstList[i].move(win, 'z');
            } break;
            case 2: {
                char goal =
                    (char)mvwinch(win, monstList[i].getPos()[0] + 1, monstList[i].getPos()[1]);
                if (goal == ' ' || goal == 'J') monstList[i].move(win, 's');
            } break;
            case 3: {
                char goal =
                    (char)mvwinch(win, monstList[i].getPos()[0], monstList[i].getPos()[1] - 1);
                if (goal == ' ' || goal == 'J') monstList[i].move(win, 'q');
            } break;
            case 4: {
                char goal =
                    (char)mvwinch(win, monstList[i].getPos()[0], monstList[i].getPos()[1] + 1);
                if (goal == ' ' || goal == 'J') monstList[i].move(win, 'd');
            } break;
            }
        }
        wattroff(win, COLOR_PAIR(3));

        //  DEPLACEMENT JOUEUR
        wattron(win, COLOR_PAIR(2));
        brd->PlayerAction(win, jr, c);
        jr.move(win, c);

        if (c == 't' && jr.getNbTelep() > 0) {
            jr.telepo(win);
            mvwaddstr(win, 13, 103, std::to_string(jr.getNbTelep()).c_str() );
        }
        wattroff(win, COLOR_PAIR(2));
    }

    werase(win);
    nocbreak();
    jr.isOnBorder() ? mvwaddstr(win, 0, 0, " Vous avez gagne !!! \n")
                    : mvwaddstr(win, 0, 0, " Vous avez perdu !!! \n");
}

Jeu::~Jeu() {
    wgetch(win);
    endwin();
    delete brd;
}
