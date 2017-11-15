/********************************************************************* 
 ** ABRA. C P P 
 *********************************************************************/
#include "abra.h"


/********************************************************************* 
 ** Function: get_type
 ** Description: returns the type of the class as a string
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns the string
 *********************************************************************/
string Abra::get_type(){
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
void Abra::interact(Trainer& lol){
	cout << "A wild Abra appeared!" << endl;
	if(lol.get_pok() > 0){
		lol.down_pok(); // decrease number of pokeballs and chance of flee
		if (rand()%100 < psychicChance){
			cout << "Abra was caught!" << endl;
			lol.up_abr();
			if(lol.get_abr() == 15 || lol.nope()){
				cout << "***********************************************" << endl;
				lol.what();
				usleep(1000000);
				cout << "Your Abra is evolving!" << endl;
				usleep(1000000);
				cout << "Your Abra evolved into Kadabra!" << endl << endl;
				cout << "Candies needed for Alakazam: 30" << endl;
				cout << "***********************************************" << endl;
			}
		}
		else{
			cout << "Oh no! The wild Abra ran away!" << endl;
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
void Abra::nearby(){
	cout << "an Abra is nearby..." << endl;
}
/********************************************************************* 
 ** Function: DEFAULT CONSTRUCTOR
 ** Description: initializes class with proper values 
 ** Parameters: none
 ** Pre-Conditions: object does not exist
 ** Post-Conditions: object exists
 *********************************************************************/
Abra::Abra(){
	type = "Abra";
}
