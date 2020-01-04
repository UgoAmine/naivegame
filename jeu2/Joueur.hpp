#ifndef JOUEUR_H
#define JOUEUR_H



class Player : public Mobile
{
  public:
    Player(WINDOW* );
    virtual ~Player();
    void setpos(std::vector<int> );
  private:
    int nbtelep;
};

#endif // JOUEUR_H
