#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
    public:
        virtual ~Element();
        void affiche();

    protected:
        char symbole;
        Element();

    private:

};

#endif // ELEMENT_H
