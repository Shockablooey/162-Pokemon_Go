/********************************************************************* 
 ** POKESTOP. C P P 
 *********************************************************************/
#include "pokestop.h"


/********************************************************************* 
 ** Function: get_type
 ** Description: returns the type of the class as a string
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns the string
 *********************************************************************/
string Pokestop::get_type(){
	return type;
}
/********************************************************************* 
 ** Function: interact
 ** Description: function called when the players location index = an
 ** index of the location 2D array that has an event pointer pointing to
 ** an object of this class type
 ** Parameters: none
 ** Pre-Conditions: player is on an index that has an event of this type
 ** Post-Conditions: messages are outputted to the screen and the 
 ** trainer's stock is edited
 *********************************************************************/
void Pokestop::interact(Trainer& lol){
	int roll;

	cout << "Spinning pokestop..." << endl;
	usleep(1000000);

	roll = rand()%8 + 3; // 3 to 10 items
	lol.up_pok(roll);
}
/********************************************************************* 
 ** Function: nearby
 ** Description: outputs a simple cout statement whenever a player is adjacent
 ** Parameters: none
 ** Pre-Conditions: player is adjacent to an event of this class type
 ** Post-Conditions: message is outputted
 *********************************************************************/
void Pokestop::nearby(){
	cout << "A Pokestop is nearby..." << endl;
}
/********************************************************************* 
 ** Function: DEFAULT CONSTRUCTOR
 ** Description: initializes class with proper values 
 ** Parameters: none
 ** Pre-Conditions: object does not exist
 ** Post-Conditions: object exists
 *********************************************************************/
Pokestop::Pokestop(){
	type = "Pokestop";
}
