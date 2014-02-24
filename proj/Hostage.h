// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307
/** This file is the Hostage class which contains any Hostage thet present
    in grid.*/

#ifndef HOSTAGE_H
#define HOSTAGE_H

#include "Actor.h"


// Display symbols for hostages
const char HOSTAGE_SYMBOL = 'H';

/// Hostages that are present in the grid which inherits actor
class Hostage : public Actor
{

public:
    Hostage() {}
    virtual ~Hostage() {}
	virtual char get_display_symbol() { return HOSTAGE_SYMBOL; }
};

#endif // HOSTAGE_H
