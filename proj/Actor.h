// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307
/** This file is the actor class which contains any object thet present
in grid. All the objects inherit the actor class*/


#ifndef ACTOR_H
#define ACTOR_H

class World;

/**
* Any object that presents in the grid
*/
class Actor
{
protected:
	/** Board where the agent is located. */
	World *world;

public:
	Actor() {}
	virtual ~Actor() {}
	World *get_world() { return world; }                    // Function that returns the world
	void set_world(World *world) { this->world = world; }   // Function that sets the world
	virtual char get_display_symbol() = 0;                  // Virtual function which is used in all the contents in the grid
};

#endif // ACTOR_H
