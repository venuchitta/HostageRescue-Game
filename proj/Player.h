// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307
/** This file is the Player class which contains player thet is present
    in grid.It has all the functionalities like moving,setting bombs etc.*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.h"
#include "World.h"
#include<string>

// Display symbol for player
const char PLAYER_SYMBOL = 'P';

class Bomb;



// Player that is present in the grid which inherits actor
class Player : public Actor
{
private:
 Grid *location;             // Player Location on the grid

public:
	Player(World *);          // Links the world object to the class
    virtual ~Player() {}  
	void print_direction(string);
	void pushbox_status(string);
	void placebomb_status(string);
    virtual char get_display_symbol() { return PLAYER_SYMBOL; }
	bool set_location(int,int);  // Set location of the player at particular row and column
	bool key_hit(string);        // Whenever the user gives an input in a console, this function is called
	bool player_move(string);    // Player movements are handled here
	bool push_box(string,int,int);  // Pushing a box is handled in this function
	bool place_bomb(string);      // Bombs are placed here
	bool is_valid_move(string);
	
	//void track_moves();         
};

#endif // ROBOT_H
