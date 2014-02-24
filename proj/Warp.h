// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307
/** This file is the Grid class which contains warps 
    in a grid.*/

 #ifndef WARP_H
 #define WARP_H

#include <iostream>
#include "Actor.h"

class Warp : public Actor
{
public:
	char warp_symbol;
	Warp(char warp_symbol) {this-> warp_symbol = warp_symbol; }   
	virtual ~Warp(){};
	virtual char get_display_symbol() { return warp_symbol; }
	void set_display_symbol(char symbol) { warp_symbol = symbol;} 

};
#endif // GRID_H

