switch(c)
{
  case 'z': //  NORTH
    if (mvwinch(win, posJ[0]-1, posJ[1]) == '$')
    {
      this->doorOpening();
      mvwaddch(win,posJ[0],posJ[1], ' ');
      posJ[0]--;
      mvwaddch(win,posJ[0],posJ[1], 'J');
    }
    else if (mvwinch(win, posJ[0]-1, posJ[1]) == '*')
    {
      this->telepIncrem();
      mvwaddch(win,posJ[0],posJ[1], ' ');
      posJ[0]--;
      mvwaddch(win,posJ[0],posJ[1], 'J');
    }
    else if (mvwinch(win, posJ[0]-1, posJ[1]) == ' ')
    {
      mvwaddch(win,posJ[0],posJ[1], ' ');
      posJ[0]--;
      mvwaddch(win,posJ[0],posJ[1], 'J');
    }
    break;
  case 'd': //  EAST
    if (mvwinch(win, posJ[0], posJ[1]+1) == '$')
    {
      this->doorOpening();
      mvwaddch(win,posJ[0],posJ[1], ' ');
      posJ[1]++;
      mvwaddch(win,posJ[0],posJ[1], 'J');
    }
    else if (mvwinch(win, posJ[0], posJ[1]+1) == '*')
    {
      this->telepIncrem();
      mvwaddch(win,posJ[0],posJ[1], ' ');
      posJ[1]++;
      mvwaddch(win,posJ[0],posJ[1], 'J');
    }
    else if (mvwinch(win, posJ[0], posJ[1]+1) == ' ')
    {
      mvwaddch(win,posJ[0],posJ[1], ' ');
      posJ[1]++;
      mvwaddch(win,posJ[0],posJ[1], 'J');
    }
    break;
  case 'q': //  WEST
    if (mvwinch(win, posJ[0], posJ[1]-1) == '$')
    {
      this->doorOpening();
      mvwaddch(win,posJ[0],posJ[1], ' ');
      posJ[1]--;
      mvwaddch(win,posJ[0],posJ[1], 'J');
    }
    else if (mvwinch(win, posJ[0], posJ[1]-1) == '*')
    {
      this->telepIncrem();
      mvwaddch(win,posJ[0],posJ[1], ' ');
      posJ[1]--;
      mvwaddch(win,posJ[0],posJ[1], 'J');
    }
    else if (mvwinch(win, posJ[0], posJ[1]-1) == ' ')
    {
      mvwaddch(win,posJ[0],posJ[1], ' ');
      posJ[1]--;
      mvwaddch(win,posJ[0],posJ[1], 'J');
    }
    break;
  case 's': //  SOUTH
    if (mvwinch(win, posJ[0]+1, posJ[1]) == '$')
    {
      this->doorOpening();
      mvwaddch(win,posJ[0],posJ[1], ' ');
      posJ[0]++;
      mvwaddch(win,posJ[0],posJ[1], 'J');
    }
    else if (mvwinch(win, posJ[0]+1, posJ[1]) == '*')
    {
      this->telepIncrem();
      mvwaddch(win,posJ[0],posJ[1], ' ');
      posJ[0]++;
      mvwaddch(win,posJ[0],posJ[1], 'J');
    }
    else if (mvwinch(win, posJ[0]+1, posJ[1]) == ' ')
    {
      mvwaddch(win,posJ[0],posJ[1], ' ');
      posJ[0]++;
      mvwaddch(win,posJ[0],posJ[1], 'J');
    }
    break;
}
