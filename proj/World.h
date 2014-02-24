// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307

/* This is the header file of world class which contains load maze to grid, Display messages etc. 
It contains all the variables like no of moves, hostages rescued etc. It contains all the get and set functions 
of the private members.

*/
#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAX_BOMBS=3;
const int WARP_NUMBER=10;
const int WARP_COLUMN=5;


class Grid;
class store_warp;
/* The game world */

class bomb_active;


class World 
 {
	//private:
 public:
	int rows, columns, time;					// stores the time ,number of rows and columns present in the grid
	Grid ***grid;								// 2-D array of the grid
	int player_x,player_y;
	bool stopGame;
	int moves,hostage_rescued;
	int hostage_no,bomb_no;


	public:
	World();
	virtual ~World();
	int get_rows() {return rows;};                    // this function will return rows of grid
	/*
	   Set and Get methods
	*/
	int get_columns() {return columns;};                  // This function will return the number of columns in grid
	int get_time(){return time;};					      // This function will return time remaining
	void set_time(int time);	                         //This function will set the number of columns in grid
	Grid *get_location(int row, int column);
	int get_playerx();
	void set_playerx(int row);	
	int get_playery();
	void set_playery(int column);
	int get_hostageno(){return hostage_no;};
	int get_rescuedhostages(){return hostage_rescued;};
	void set_hostage(){hostage_rescued++;};
	int get_bombno(){return bomb_no;};
	void set_bomb(int bomb_no){this->bomb_no=bomb_no;};
	int get_moves(){return moves;};
	void set_moves(){moves++;};
	void setGrid(string);
    void display(std::ostream & os);
	int get_stopGame(){return stopGame;};
	void set_stopGame(){stopGame=1;};
	void init_bomb(int,int,int);           // The function that initializes bomb
	bomb_active* bomb_obj;                 // The Bomb object that
	vector <bomb_active> locate_bombs;
	void destroy_grid();
	void intitialize_grid();
	bool is_digit(char);
	bool Warp_store(char,int,int);
	int ** warp_info;                    // Array that stores warp information
	void initialize_array();             // Intializing array that are used to store locations of the warp
};

class bomb_active
{
public:
	int x;
	int y;
	int moves;
	bomb_active(int x,int y,int moves)
	{
		this->x=x;
		this->y=y;
		this->moves=moves;
	}
};

#endif 
