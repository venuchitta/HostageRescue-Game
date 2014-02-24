// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307
/** This file is the Wall class which contains walls that are present
    in grid.*/

#ifndef WALL_H
#define WALL_H

#include "Actor.h"


// Display symbols for WALL
const char WALL_SYMBOL = 'X';

// Walls that are present in the grid which inherits actor
class Wall : public Actor
{

public:
    Wall() {}
    virtual ~Wall() {}
	virtual char get_display_symbol() { return WALL_SYMBOL; }
};

#endif // Wall_H
