// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307
/** This file is the Exit class which contains any exit that present
    in grid.*/

#ifndef EXIT_H
#define EXIT_H

#include "Actor.h"


// Display symbols for EXIT
const char EXIT_SYMBOL = 'E';

// Exit that is present in the grid which inherits actor
class Exit : public Actor
{

public:
    Exit() {}
    virtual ~Exit() {}
	virtual char get_display_symbol() { return EXIT_SYMBOL; }
};

#endif // EXIT_H
