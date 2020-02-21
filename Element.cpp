#include "Element.hpp"

// random data generator function (number of data, lower bound, upperbound).
std::vector<int> random_data(int n, int a, int b) {
    std::random_device r;
    std::seed_seq      seed{ r(), r(), r(), r(), r(), r(), r(), r() };
    std::mt19937       eng(seed);    // MersenneTwister un generateur pseudo-aléatoire
                                     // fonction d'une SEED.

    std::uniform_int_distribution<int> dist(a, b);
    std::vector<int>                   v(n);

    generate(begin(v), end(v), bind(dist, eng));
    return v;
}

Element::Element(int y, int x) { pos = { y, x }; }

Element::Element(WINDOW *win, char s) {
    sym = s;
    do {
        pos = { random_data(1, 1, 48)[0], random_data(1, 1, 98)[0] };
    } while (mvwinch(win, pos[0], pos[1]) != ' ');

    mvwaddch(win, pos[0], pos[1], sym);
    wrefresh(win);
}

Element::~Element() {}
