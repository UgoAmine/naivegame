#include "Joueur.hpp"

Player::Player(WINDOW *win) : Mobile(win, 'J'), nbtelep{ 0 } {}

Player::~Player() {}

void Player::telepo(WINDOW *win) {
    mvwaddch(win, pos[0], pos[1], ' ');
    do {
        pos = { random_data(1, 1, 48)[0], random_data(1, 1, 98)[0] };
    } while (mvwinch(win, pos[0], pos[1]) != ' ');
    mvwaddch(win, pos[0], pos[1], 'J');
    nbtelep--;
}

bool Player::isOnBorder() {
    return ((pos[0] == 0) || (pos[0] == 49) || (pos[1] == 0) || (pos[1] == 99));
}

bool Player::perdu(std::vector<Mobile> mst) {
    bool b = false;
    for (int i = 0; i < int(mst.size()); i++) b = b || (pos == mst[i].getPos());
    return b;
}
