// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307

/* This is the implementation of world class which contains load maze to grid, Display messages etc. 
This also contains initializing grid and array used for warps. The active bombs information is stored
in world

*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

#include "World.h"
#include "Grid.h"
#include "Actor.h"
#include "Player.h"
#include "Hostage.h"
#include "Warp.h"
#include "Wall.h"
#include "Box.h"
#include "Bomb.h"
#include "Exit.h"

// Constructor of the world
World :: World()
{
	time = 0;
	rows = 0;
	columns = 0;
	stopGame=0;
	bomb_no=0;
	hostage_no=0;
	hostage_rescued=0;
	moves=0;
	initialize_array();

}

// Deconstructor that releases memory of world object
World :: ~World()
{
	for (int row = 0; row < rows; row++)
		for (int col = 0; col < columns; col++)
			delete grid[row][col];
	for (int i = 0; i < rows; i++)
		delete[] grid[i];
	delete[] grid;	
}

void World::display(std::ostream & os) 
{
	cout << "\n ------------------------------------"<<endl;
	cout<<"\n Time:"<<setw(8)<<time-moves<<setw(10)<<"Moves:"<<setw(8)<<moves;
	cout<<"\n Hostages:"<<setw(4)<<hostage_no<<setw(12)<<"Rescued:"<<setw(6)<<hostage_rescued;
	cout<<"\n Bombs :"<<setw(6)<<bomb_no<<setw(15)<<"Max Bombs: "<<setw(3)<<MAX_BOMBS;
	cout << "\n ----------------------------------"<<endl;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < columns; col++)
			os << grid[row][col]-> get_display_symbol();
		os << endl;
	}
}

//This function will set the time
void World ::set_time(int max_time)
{
	time = max_time;
}

// The function will check if it is valid location and returns the gridcell
Grid* World :: get_location(int r, int c)
{
	if (r < 0 || r > rows-1 ||c < 0 || c > columns-1)
		return NULL;
	return grid[r][c];
}

// The function will set the players x location
void World ::set_playerx(int row_x)
{
	player_x=row_x;
}

// The function will set the players y location
void World ::set_playery(int column_x)
{
	player_y=column_x;
}

// The function will give the players x location
int World ::get_playery()
{
	return player_y;
}

// The function will give the players y location
int World ::get_playerx()
{
	return player_x;
}

// The function will initialize the grid
void World:: intitialize_grid()
{
	grid = new Grid**[rows];
	for (int i = 0; i < rows; i++)
		grid[i] = new Grid*[columns];
	for (int row = 0; row < rows; row++)
		for (int col = 0; col < columns; col++)
			grid[row][col] = new Grid(row, col);

}

// Adds all the actors to the grid 
void World::setGrid(string path)
{
	ifstream inputFile(path.c_str());             // inputfile which reads the data from file
	if (!inputFile)                                  // if input file doesn't exist it shows an error
		cout << "The file can't be opened";
	else
	{
		inputFile>>rows>>columns>>time;    // it reads rowno,columnno and timelimit from file
		intitialize_grid();

		char ch = inputFile.get();                  //Since after time we get new line and we dont want that

		for (int r = 0; r < rows; r++)            // Index that runs through rows
		{
			int c = 0;                             // Initially column index is 0 and increments in while loop
			char ch = inputFile.get();             // Getting the first charecter from the file
			while (ch != '\n'&&!inputFile.eof())   // If a newline or endline is found,the looping terminates
			{
				Hostage *hostage = NULL;
				Wall *wall=NULL;
				Box *box=NULL;
				Bomb *bomb=NULL;

				Exit *exit=NULL;
				Player *player=NULL;
				if (isdigit(ch))
					Warp_store(ch,r,c);
				switch(ch)
				{
				case ('.'):
					break;

				case('X'):
					wall = new Wall();
					grid[r][c]->set_wall(wall);
					break;

				case('H'):
					hostage = new Hostage();
					grid[r][c]->set_hostage(hostage);
					hostage_no++;
					break;

				case('B'):
					box = new Box() ;
					grid[r][c]->set_box(box);
					break;

				case('E'):
					exit = new Exit() ;
					grid[r][c]->set_exit(exit);
					break;

				case('P'):
					player_x=r;
					player_y=c;
					break;

				case('o'):
					bomb = new Bomb() ;
					grid[r][c]->set_bomb(bomb);
					break; 
				default:
					break;
				}
				c++;                               //column no increments
				ch = inputFile.get();              //getting input from file after incrementing
			}
		}
	}
}

// Will intitialize the array for the Warp
void World:: initialize_array()
{
	warp_info= new int* [WARP_NUMBER];           // creating 2-dim char array to store the walls and all
	for (int i=0;i<WARP_NUMBER;i++)
		warp_info[i]=new int[WARP_COLUMN];     
	for (int i=0;i<WARP_NUMBER;i++)
		for (int j=0;j<WARP_COLUMN;j++)
			warp_info[i][j]=0;
}

// All the numbers that are using for the warp are intitlized to the grid through this functions
bool World :: Warp_store(char num,int row,int column)
{
	Warp *warp=NULL;
	warp=new Warp(num);
	grid[row][column]->set_warp(warp);
	int number=num-'0';
	warp_info[number][0]++;
	if(warp_info[number][0]==1)
	{
		warp_info[number][1]=row;
		warp_info[number][2]=column;
	}
	else 
	{
		warp_info[number][3]=row;
		warp_info[number][4]=column;
	}
	return 1;
}

// This function will initialize the active bomb tracker
void World::init_bomb(int x,int y, int move)
{
	bomb_active bomb_obj(x,y,move);                 // Create bomb active object with xcoordinate,y and moves in it
	locate_bombs.push_back(bomb_obj);                       // Pushing back in vector locate_bombs
}

// This function will check if it have to destroy grid by tracking moves.
void World:: destroy_grid()
{
	for (int i=0;i<locate_bombs.size();i++)
	{
		locate_bombs[i].moves++;                                     // Incrementing moves
		if (locate_bombs[i].moves==4)                               // If tracked moves are true, then we need to explode bomb
		{
			int row=locate_bombs[i].x;
			int column=locate_bombs[i].y;
			grid[row][column]->get_bomb()->explode_bomb(row,column);     // This would direct to explode bombs function in BOMB class
			locate_bombs.erase (locate_bombs.begin(),locate_bombs.begin()+1);  // Pop out the bombs that are exploded

		}
	}

}