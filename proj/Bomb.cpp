// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307
/** This file is the implementation of Bomb class which contains any bomb thet present
    in grid. The active bomb symbol is @ as below. It contains 
	functions which explodes 3x3 cells the after it is made active*/

# include"Bomb.h"
#include "Grid.h"

// The function contains explode bomb function which destroys 3x3 cells in the grid
void Bomb:: explode_bomb(int row,int col) 
{ 
	Grid *grid_cell =get_world()->get_location(row ,col);              // Get location of the active bomb cell
	grid_cell->set_bomb(NULL);
	for (int i=row-1;i<row+2;i++)
		if (i<get_world()->get_rows() && i>=0)
		{
			for (int j=col-1;j<col+2;j++)
				if (j<get_world()->get_columns() &&j>=0)
				{
					Grid *grid_cell =get_world()->get_location(i , j);    //Checks for the symbols in the 3x3 grid
					char symbol=grid_cell->get_display_symbol();
					print_status(symbol);
					if (symbol=='P')
						get_world()->set_stopGame();
					else if (symbol=='X')
						grid_cell->set_wall(NULL);
					else if (symbol=='B')
						grid_cell->set_box(NULL);
					else if (symbol=='H')
						get_world()->set_stopGame();
					else if ((symbol=='o')||(symbol=='@'))
						explode_bomb(i,j);
				}
		}
}


// Displays status messages if the player or the hostage dies.
void Bomb:: print_status (char symbol)
{
	if (symbol=='P')
		cout<<"\nThe player is destroyed!!!!" <<endl;
	else if (symbol=='H')
		cout<<"\n The hostage is dead!!"<<endl;
}

