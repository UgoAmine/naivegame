#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:
        Board();
        virtual ~Board();
        void wallgen();
        void wallgen(int num = 1);
        void prt();

    protected:

    private:
        char brd[30][30];
        int size;
        int m_lvl;
};

#endif // BOARD_H
