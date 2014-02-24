// Name: Subrahmanya Venu Madhav Chitta
// A.No: A01964307

/* This is the main file which displays menu on the console. This also contains wrapper function gameplay() which links to the world.
The user is provided with instructions and about gives the information about author.
*/

# include <iostream>
# include "world.h"
# include "Player.h"
# include <fstream> 
# include<string>
#include<iterator>
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <dirent.h>
#include <sys/stat.h>
using namespace std;

vector <string> directories;   // Vector that store directories.

// Instructions that appear in console
void Instructions()
{
	cout << "----------------------------------------"<<endl;
	cout << "               Instructions             "<<endl;
	cout << "----------------------------------------"<<endl;
	cout<<"\nWhen the game starts the player is inside a maze where several hostages have  been trapped, and the objective";
	cout<<" is to free all the hostages and escape from the maze before the time runs out and the maze is destroyed.";
	cout<<" The player can use bombs to destroy the walls. He can push the box when needs. He can use warps and transport to other cells with same numbers.";
	cout << "\n The player can move up(u), down(d), left(l), right(r) and can skip the turn(w)" ;
	cout << " The player can plant the bombs up,down,left,right.";
}

// The conditions that stops the game
bool stop_game(string hit, World& world_obj)
{
	return hit != "q!"&& world_obj.get_stopGame() ==0 && world_obj.get_time()!=world_obj.get_moves();
}

// The user will play the game using this function
void game_play(World &world_obj)
{
	string hit;                                                    // Key that user hits in the console during game
	Player player(&world_obj);
	world_obj.display(cout);
	do{
		cout << "\n Press up(u) or down(d) or left(l) or right(r) or wait(w) :";
		cin>>hit;
		player.key_hit(hit);                                   // This will find the hit 
		world_obj.display(cout);
	}while (stop_game(hit,world_obj));                       // Conditions that make to quit the game
	if (!stop_game(hit,world_obj))
		cout<<"\n FAILURE!!"<<endl;
	else cout<<"\n SUCCESS!!"<<endl;
}

// This function allows to select maze from the displayed list of text files in ./maps folder
void select_maze()
{
	string directory_name =  "./maps";
	ifstream myfile;
	bool fileFound;
	DIR *dir;
	struct dirent *ent;
	int choice;
	struct stat filestat;
	if ((dir = opendir (directory_name.c_str())) != NULL)
	{
		while ((ent = readdir (dir)) != NULL) {
			// Skip the file if it is invalid or it is a directory
			string filepath = directory_name + "/" + ent->d_name;
			if (stat( filepath.c_str(), &filestat ))
				continue;
			if (S_ISDIR( filestat.st_mode ))
				continue;
			directories.push_back(ent->d_name);
		}
		closedir (dir);
	}
	else 
		cerr << strerror(errno) << endl;
	for(int i=0;i<directories.size();i++)
		cout << i+1<< "." << directories[i] << endl;
	cout << "Please enter a number" << endl << endl;
	cin >> choice;
	if(choice <= directories.size())
	{
		string filename = directories[choice-1];	
		World  world_obj;
		world_obj.setGrid(("maps/"+filename).c_str());
		game_play(world_obj);
	}
	else 
		cout << "\n Enter correct number" << endl;
	directories.clear();
}

void About()
{
	cout <<"\n\n\t Author : Subrahmanya Venu Madhav Chitta"<<endl;
	cout << " \t A.No   : A01964307"<<endl;
}

int main()
{
	int num;
	do
	{
		cout << "\n ----------------------------------------"<<endl;
		cout << "    Welcome to Hostage Rescue Game      "<<endl;
		cout << "----------------------------------------"<<endl;
		cout << " \tMain Menu"<<endl;
		cout << "\n\t  1. Select Maze and load it "<<endl;
		cout << "\t  2. Read instructons "<<endl;
		cout << "\t  3. About "<<endl;
		cout << "\t  4. quit "<<endl;
		cout << "\t Select an option(1-4): ";
		cin >> num;
		switch (num)
		{
		case 1:
			select_maze();
			break;
		case 2:
			Instructions();
			break;
		case 3: 
			About();
			break;
		case 4:
			exit(0);
		}
	}while (num != 4);
	return 0;
}
