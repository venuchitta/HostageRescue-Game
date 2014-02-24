// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307
/** This file is the Box class which contains any box thet present
    in grid.*/

#ifndef BOX_H
#define BOX_H

#include "Actor.h"

// Display symbols for BOX
const char BOX_SYMBOL = 'B';

// Boxes that are present in the grid which inherits actor
class Box : public Actor
{

public:
	Grid *grid;
	Box() {}
	virtual ~Box() {}
	virtual char get_display_symbol() { return BOX_SYMBOL; }
};

#endif // BOX_H
