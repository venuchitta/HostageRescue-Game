// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307
/** This file is the implementation Player class which contains player thet is present
    in grid.It has all the functionalities like moving,setting bombs etc which are the player actions*/

#include "Grid.h"
#include "Player.h"
#include "Hostage.h"
#include "Wall.h"
#include "box.h"
#include "Bomb.h"
#include "Exit.h"

// Constructor for the player Class which sets the location of the player on the board.
Player::Player(World *world)
{
	set_world(world);
	location=get_world()->get_location(world->get_playerx(),world->get_playery());
	location->set_player(this);
}

// The function when the player is moving on the grid
bool Player :: set_location(int new_row, int new_col)
{
	Grid *new_cell = get_world()->get_location(new_row, new_col);    // Getting the grid element with that row and column no
	if (new_cell == NULL){
		return false;}
	location->set_player(NULL);                                       // Previous location is set Nll
	location = new_cell;                                              // Location is net to new row and column
	new_cell->set_player(this);                                       // Set the player at this location and set true
	return true;
}

// The player moving in 4 directions
bool Player:: player_move(string hit)
{
	int new_x=location->get_row();
	int new_y=location->get_column();
	if (hit == "u")
		new_x--;
	else if (hit == "d")
		new_x++;
	else if (hit == "l")
		new_y-- ;
	else if (hit == "r")
		new_y++;
	Grid *grid_cell =get_world()->get_location(new_x , new_y);    // Getting the gridcell with the player to be moved.
	if (grid_cell)
	{

		if (grid_cell->isEmpty())                                     // Checking of the gridcell is empty
		{
			set_location(new_x,new_y);                             // Set the player at new location
			get_world()->set_moves();
			print_direction(hit);
			return true;
		}
		else if (grid_cell->get_display_symbol()=='o')                 // Cheking if the grid cell is having bomb
		{
			int bomb=get_world()->get_bombno();
			grid_cell->set_bomb(NULL);                                 // Set that position to NULL
			set_location(new_x,new_y);                                 // Player movimg to that new position.
			get_world()->set_moves();
			if (bomb <3)
			{
				bomb++;
				get_world()->set_bomb(bomb);                      // Increment number of bombs collected
			}
			cout << "\n You collected a bomb"<<endl;
			return true;
		}
		else if (grid_cell->get_display_symbol()=='H')                // Check if that position has a hostage
		{
			grid_cell->set_hostage(NULL);                                 // Set that position to NULL
			get_world()->set_hostage();
			set_location(new_x,new_y);                                 // Player movimg to that new position.
			get_world()->set_moves();
			cout<<"\n A hostage is rescued!! :)"<<endl;
			return true;
		}
		else if (grid_cell->get_display_symbol()=='B')                 // Cheking if the grid cell is having box
			push_box(hit,new_x,new_y);
		else if (grid_cell->get_display_symbol()=='E')                  // Cheking if the grid cell is having Exit
		{
			if (get_world()->get_rescuedhostages() == get_world()->get_hostageno())      // If so the collected hostages must be total hostages
				get_world()->set_stopGame();                            // Then we can stop game else dont make any change in position
			get_world()->set_moves();
		}

		else if (isdigit(grid_cell->get_display_symbol()))                                 // Check if it is a warp
		{
			int num=grid_cell->get_display_symbol()-'0';                                         // Get the number in the warp
			if (get_world()->warp_info[num][1]==new_x && get_world()->warp_info[num][2]==new_y)  // Checking the map location in the grid
				set_location(get_world()->warp_info[num][3],get_world()->warp_info[num][4]);    
			else if (get_world()->warp_info[num][3]==new_x && get_world()->warp_info[num][4]==new_y)
				set_location(get_world()->warp_info[num][1],get_world()->warp_info[num][2]);
			cout<<"\n The player moved into a warp"<<endl;
		}

		else cout<<"\n Make a valid move!!!!"<<endl;
	}
}


// The player pushes the box
bool Player::push_box(string direction,int row,int column)
{
	int new_row=row;
	int new_column=column;
	if (direction == "u")
		new_row--;
	else if (direction == "d")
		new_row++;
	else if (direction == "l")
		new_column--;
	else if (direction == "r")
		new_column++;
	Grid *box_cell =get_world()->get_location(new_row , new_column);       // The gridcell where the box is about to move
	Grid *player_cell =get_world()->get_location(row ,column);             // The gridcell where the player ia about to move
	if (box_cell)
	{
		if (box_cell->isEmpty())                                               // Checking if the cell that box is about to move is empty
		{
			get_world()->set_moves();
			box_cell->set_box(player_cell->get_box());                         // Move box to new location
			player_cell->set_box(NULL);                                        // Set the previous position to NULL
			set_location(row,column);                                          // Player cell is intitialized with player
			pushbox_status(direction);
			return true;
		}
	}
	else cout<<"Box cant be moved furthur!!!"<<endl;
}

// The player triggers a bomb
bool Player::place_bomb(string hit)
{
	int new_x=location->get_row();
	int new_y=location->get_column();
	if(get_world()->get_bombno())
	{
		if( hit == "b[u]")
			new_x--;
		else if (hit == "b[d]")
			new_x++;
		else if (hit == "b[l]")
			new_y--;
		else if (hit == "b[r]")
			new_y++;
		Grid *bomb_cell = get_world()->get_location(new_x , new_y);        // The location where bomb is to be kept
		if (bomb_cell->isEmpty())                                         // cheking if it is empty or not
		{
			get_world()->set_moves();
			Bomb *b=new Bomb();                                           // Creating new oject of bomb to activate it
			b->set_display_symbol('@');                                   // @ is symbol to show that it bob is activated
			bomb_cell->set_bomb(b);                                       // Bomb is made set at new position
			int bomb=get_world()->get_bombno();
			bomb--;
			get_world()->set_bomb(bomb);                                                      // Number of bombs are decremented
			placebomb_status(hit);  
			b->set_world(world);
			get_world()->init_bomb(new_x,new_y,0);
			return true;
		}
		else cout<<"\n You cant place a bomb at this place"<<endl;
	}
	else cout<<"\n You dont have any bombs to place!!!"<<endl;
}

// The player actions are displayed for the hit
bool Player :: key_hit(string hit)
{
	if(is_valid_move(hit))
	{
		if (hit == "u")                   // Player moving up
			player_move(hit);
		else if (hit == "d")              // Player moving down
			player_move(hit);
		else if (hit == "l")              // Player moving left
			player_move(hit);
		else if (hit == "r")              // Player moving right
			player_move(hit);
		else if( hit == "b[u]")           // Player placing bomb at up position
			place_bomb(hit);
		else if( hit == "b[d]")           // Player placing bomb at down position
			place_bomb(hit);
		else if( hit == "b[r]")           // Player placing bomb at right position
			place_bomb(hit);
		else if( hit == "b[l]")           // Player placing bomb at left position
			place_bomb(hit);
		if (get_world()->locate_bombs.size())   // Checking if there is any active bomb
			get_world()->destroy_grid();       // If so call that function
		if (hit == "w")
			return true;
		return true;
	}
	else
	{
		if (hit !="q!")
			cout<<"\n Invalid Move!!!"<<endl;
		return false;
	}

}

// Check if it is valid move or not
bool Player::is_valid_move(string hit)
{
	return ((hit=="u")||(hit=="d")||(hit=="l")||(hit=="r")||(hit=="b[u]")||(hit=="b[d]")||(hit=="b[l]")||(hit=="b[r]")||(hit == "w"));

}


// This function will print the status messages of player movements
void Player:: print_direction (string direction)
{
	if (!get_world()->get_stopGame())
	{
		if (direction == "d")
			cout << "\n The player moved down"<<endl;
		else if (direction == "u")
			cout << "\n The player moved up"<<endl;
		else if (direction == "l")
			cout << "\n The player moved left"<<endl;
		else if (direction == "r")
			cout << "\n The player moved right"<<endl;
	}

}

// This function will print the status messages of box movements
void Player::pushbox_status(string direction)
{
	if (!get_world()->get_stopGame())
	{
		if (direction == "d")
			cout << "\n The player moved down and pushed the box"<<endl;
		else if (direction == "u")
			cout << "\n The player moved up and pushed the box"<<endl;
		else if (direction == "l")
			cout << "\n The player moved left and pushed the box"<<endl;
		else if (direction == "r")
			cout << "\n The player moved right and pushed the box"<<endl;
	}
}

// This function will print the status messages of bomb status
void Player::  placebomb_status(string direction)
{
	if (!get_world()->get_stopGame())
	{
		if (direction == "b[d]")
			cout << "\n You placed a bomb down"<<endl;
		else if (direction == "b[u]")
			cout << "\n You placed a bomb up"<<endl;
		else if (direction == "b[l]")
			cout << "\n You placed a bomb left"<<endl;
		else if (direction == "b[r]")
			cout << "\n You placed a bomb right"<<endl;
	}
}