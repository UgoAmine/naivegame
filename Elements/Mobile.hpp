#ifndef MOBILE_H
#define MOBILE_H

#include "Element.hpp"


class Mobile : public Element
{
    public:
        virtual ~Mobile();

    protected:
        Mobile();

    private:
        int x,y;  // COORDONNEES DANS TABLEAU
};

#endif // MOBILE_H
