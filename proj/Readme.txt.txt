Name: Subrahmanya Venu Madhav Chitta	
A.No: A01964307

Files:

(1) Hostage_rescue.cpp:  This file contains the instructions, about, the main function and file display function

(2) World.h  : This is the header file for the World class which contains all the variables uses the program, loading maze etc.

(3) World.cpp :  This is the implementation file which contains all the implementations of the functions used in world.h. It contains global information of the game.

(4) Grid.h : This is the header file for the Grid class in which the actor type is present. All the get and set methods of all the actors are displayed here.

(5) Actor.h : All the charecters which are present in the grid are of the type actors.So all the charecter types inherit actor types.

(6) Bomb.h : This is the header file which contains bomb class which sets bomb class to active bomb status when activated.

(7) Bomb.cpp : This file has the implementation of exploding active bomb definition.

(8) Box.h : The file is the header file for the Box class.

(9) Exit.h : The file is the header file for the Exit class.

(10) Hostage.h : The file is the header file for the Hostage class.

(11) Player.h : The file is header file which contains the player class and some of the function definitions of the player actions.

(12) Player.cpp : The function contains all the function implementations of the player like moving,pushing boxes et

(13) Wall.h : The file is the header file for the Wall class.

(14) Warp.h : The file is the header file for the extra feature Warp class.

Design: 

The main class contains Loading files, Displaying menu on the console and wrapper to World class

The world class contains Loading Grid to the world object,Initializing grid, Initialization of array for Warp class and destroying grid which track moves to explode 3x3 grid around bomb.It also contains call to the function in the grid which does explosion.The world is linked to the player and bomb.

The grid class has displaying the symbols and all the get and set methods of the actors.It is a gridcell has the object of type actor.

All the actors other than bomb and player are static and dont move.So they just have header files but no functions other than constructor,destructor and display symbol.The actor class contains functions like setworld which sets any actor to the world and that actor can access the world.

The Bomb class has both state i.e. active bomb('@') and normal bomb('o'). When the world calls explode bombs the active bomb destroys 3x3 cells.
 

The player contains all the actions of the player like activating a bomb,moving bombs, collecting bomb etc. The status messages are also displayed by this class.

"""""" I think i handled all the cases and status messages. """"""""


Extra feature:

The extra feature i implemented is Warp. The maze contains the numbers in pairs from 0-9 and can transport from one number to other same number.
I took and array in the world class and stores coordinates or the numbers of grid in the form of tables. I used a seperate class warp. The Bomb cant destroy warp.


********************************************************Thank you*************************************************************************8




