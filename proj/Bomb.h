// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307
/** This file is the Bomb class which contains any bomb thet present
    in grid. The active bomb symbol is @ as below. It contains some
	functions which explodes the after it is made active*/

#ifndef BOMB_H
#define BOMB_H
#include "Actor.h"


// Display symbols for hostages
const char BOMB_SYMBOL = 'o';
class Grid;

// Bombs that are present in the grid which inherits actor
class Bomb : public Actor
{
public:
	char bomb_symbol;
	Bomb() { bomb_symbol = BOMB_SYMBOL; }                      // Constructor by default has symbol 'o'
    virtual ~Bomb() {}
	virtual char get_display_symbol() { return bomb_symbol; }
	void set_display_symbol(char symbol) { bomb_symbol = symbol;} // When this function is made set the symbol becomes '@'
	void explode_bomb(int,int) ;
	void print_status(char);


};

#endif // BOMB_H
