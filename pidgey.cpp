/********************************************************************* 
 ** PIDGEY. C P P 
 *********************************************************************/
#include "pidgey.h"


/********************************************************************* 
 ** Function: get_type
 ** Description: returns the type of the class as a string
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns the string
 *********************************************************************/
string Pidgey::get_type(){
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
void Pidgey::interact(Trainer& lol){
	cout << "A wild Pidgey appeared!" << endl;
	if(lol.get_pok() > 0){
		lol.down_pok(); // decrease number of pokeballs and chance of flee
		if (rand()%100 < flyingChance){
			cout << "Pidgey was caught!" << endl;
			lol.up_pid();
			if(lol.get_pid() == 5 || lol.nope()){
				cout << "***********************************************" << endl;
				lol.what();
				usleep(1000000);
				cout << "Your Pidgey is evolving!" << endl;
				usleep(1000000);
				cout << "Your Pidgey evolved into Pidgeotto!" << endl << endl;
				cout << "Candies needed for Pidgeot: 15" << endl;
				cout << "***********************************************" << endl;
			}
		}
		else{
			cout << "Oh no! The wild Pidgey ran away!" << endl;
		}
	}
	else{
		cout << "You have no Pokeballs! The wild pokemon ran away." << endl;
	}
}
/********************************************************************* 
 ** Function: nearby
 ** Description: outputs a simple cout statement whenever a player is adjacent
 ** Parameters: none
 ** Pre-Conditions: player is adjacent to an event of this class type
 ** Post-Conditions: message is outputted
 *********************************************************************/
void Pidgey::nearby(){
	cout << "a Pidgey is nearby..." << endl;
}
/********************************************************************* 
 ** Function: DEFAULT CONSTRUCTOR
 ** Description: initializes class with proper values 
 ** Parameters: none
 ** Pre-Conditions: object does not exist
 ** Post-Conditions: object exists
 *********************************************************************/
Pidgey::Pidgey(){
	type = "Pidgey";
}
