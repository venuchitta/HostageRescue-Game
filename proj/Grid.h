// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307
/** This file is the Grid class which contains the grid cell 
    in a grid.Each gridcell contains any of the actors.*/

 #ifndef GRID_H
 #define GRID_H

#include <iostream>

#include "Wall.h"  
#include "Player.h"
#include "Hostage.h"
#include "Bomb.h"
#include "Box.h"
#include "Exit.h"
#include "Warp.h"
using namespace std;

class Exit;
class Wall;
class Player;
class Hostage;
class Bomb;
class Box;
class Warp;

// Symbols for empty locations
const int EMPTY_LOC_SYMBOL = '.';

/**
 * A cell of the grid.
 * Each cell can contain any actor.
 */

class Grid 
{

private:
    Player *player;   // Player 
    Hostage *hostage; // Hostage
	Wall *wall;       // Wall
	Box *box;         // Box
	Bomb *bomb;       // Bomb
	Exit *exit;       // Exit
	Warp *warp;       // Warp

	int row,column;   // Row and Column of a gridcell

public:
    Grid(int row,int column) :row(row),column(column), player(NULL), hostage(NULL), wall(NULL), box(NULL), bomb(NULL), exit(NULL),warp(NULL) {}
    virtual ~Grid() {};

	int get_row(){return row;}                                  
	int get_column(){return column;}

	// Get and Set functions for the player from/to grid
    Player *get_player() { return player; }
    void set_player(Player *player) { this->player = player; }

	// Get and Set functions for the Hostage from/to grid
    Hostage *get_hostage() { return hostage; }
    void set_hostage(Hostage *hostage) { this->hostage = hostage; }

	// Get and Set functions for the Wall from/to grid
    Wall *get_wall() { return wall; }
    void set_wall(Wall *wall) { this->wall = wall; }

	// Get and Set functions for the Box from/to grid
    Box *get_box() { return box; }
    void set_box(Box *box) { this->box = box; }

	// Get and Set functions for the Bomb from/to grid
    Bomb *get_bomb() { return bomb; }
    void set_bomb(Bomb *bomb) { this->bomb = bomb; }
	
	// Get and Set functions for the Exit from/to grid
    Exit *get_exit() { return exit; }
    void set_exit(Exit *exit) { this->exit = exit; }

	// Get and Set functions for the Warp
	Warp *get_warp(){ return warp;}
	void set_warp (Warp *warp){this ->warp =warp;}

	// When the gridcell is not any of the actor, it returns 1
	bool isEmpty() { return !player && !hostage && !wall && !bomb && !box && !exit && !warp ; }

    // Return the symbol used to represent this location on the grid
    char get_display_symbol(){
		if (isEmpty())
        return EMPTY_LOC_SYMBOL;
		else if (player)
			return player->get_display_symbol();
		else if (hostage)
			return hostage->get_display_symbol();
		else if (box)
			return box->get_display_symbol();
		else if (bomb)
			return bomb->get_display_symbol();
		else if (exit)
			return exit->get_display_symbol();
		else if (wall)
			return wall->get_display_symbol();
		else if (warp)
			return warp->get_display_symbol();
	}

};
#endif // GRID_H

