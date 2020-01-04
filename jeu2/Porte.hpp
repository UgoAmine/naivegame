#ifndef PORTE_H
#define PORTE_H

class Porte
{
private:
    bool Etat;
public:
    Porte();
    inline void setEtat(bool e) const { Etat = e };
    virtual ~Porte();
};

#endif /* PORTE_H */
