/********************************************************************* 
 ** GEODUDE. C P P 
 *********************************************************************/
#include "geodude.h"


/********************************************************************* 
 ** Function: get_type
 ** Description: returns the type of the class as a string
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns the string
 *********************************************************************/
string Geodude::get_type(){
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
void Geodude::interact(Trainer& lol){
	cout << "A wild Geodude appeared!" << endl;
	if(lol.get_pok() > 0){
		lol.down_pok(); // decrease number of pokeballs and chance of flee
		if (rand()%100 < rockChance){
			cout << "Geodude was caught!" << endl;
			lol.up_geo();
			if(lol.get_geo() == 15 || lol.nope()){
				cout << "***********************************************" << endl;
				lol.what();
				usleep(1000000);
				cout << "Your Geodude is evolving!" << endl;
				usleep(1000000);
				cout << "Your Geodude evolved into Graveler!" << endl << endl;
				cout << "Candies needed for Golem: 30" << endl;
				cout << "***********************************************" << endl;
			}

		}
		else{
			cout << "Oh no! The wild Geodude ran away!" << endl;
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
void Geodude::nearby(){
	cout << "a Geodude is nearby..." << endl;
}
/********************************************************************* 
 ** Function: DEFAULT CONSTRUCTOR
 ** Description: initializes class with proper values 
 ** Parameters: none
 ** Pre-Conditions: object does not exist
 ** Post-Conditions: object exists
 *********************************************************************/
Geodude::Geodude(){
	type = "Geodude";
}
