



#ifndef MOBILE_H
#define MOBILE_H

class Mobile : public Element
{
    
public:
    Mobile(WINDOW*);
    
    void move(char input, WINDOW* win);
    
    virtual ~Mobile();
};

#endif /* MOBILE_H */
