#ifndef MOBILE_H
#define MOBILE_H

#include "Element.hpp"

class Mobile : public Element
{
public:
    Mobile(WINDOW*, char s = 'S');

    void move(WINDOW*, char);

    virtual ~Mobile();
};

#endif /* MOBILE_H */
