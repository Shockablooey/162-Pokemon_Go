/********************************************************************* 
 ** DRATINI. C P P 
 *********************************************************************/
#include "dratini.h"


/********************************************************************* 
 ** Function: get_type
 ** Description: returns the type of the class as a string
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns the string
 *********************************************************************/
string Dratini::get_type(){
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
void Dratini::interact(Trainer& lol){
	cout << "A wild Dratini appeared!" << endl;
	if(lol.get_pok() > 0){
		lol.down_pok(); // decrease number of pokeballs and chance of flee
		if (rand()%100 < flyingChance){
			cout << "Dratini was caught!" << endl;
			lol.up_dra();
			if(lol.get_dra() == 25 || lol.nope()){
				cout << "***********************************************" << endl;
				lol.what();
				usleep(1000000);
				cout << "Your Dratini is evolving!" << endl;
				usleep(1000000);
				cout << "Your Dratini evolved into Dragonair!" << endl << endl;
				cout << "Candies needed for Dragonite: 50" << endl;
				cout << "***********************************************" << endl;
			}
		}
		else{
			cout << "Oh no! The wild Dratini ran away!" << endl;
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
void Dratini::nearby(){
	cout << "a Dratini is nearby..." << endl;
}
/********************************************************************* 
 ** Function: DEFAULT CONSTRUCTOR
 ** Description: initializes class with proper values 
 ** Parameters: none
 ** Pre-Conditions: object does not exist
 ** Post-Conditions: object exists
 *********************************************************************/
Dratini::Dratini(){
	type = "Dratini";
}
