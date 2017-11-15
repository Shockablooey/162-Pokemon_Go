/********************************************************************* 
 ** SLOWPOKE. C P P 
 *********************************************************************/
#include "slowpoke.h"


/********************************************************************* 
 ** Function: get_type
 ** Description: returns the type of the class as a string
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns the string
 *********************************************************************/
string Slowpoke::get_type(){
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
void Slowpoke::interact(Trainer& lol){
	cout << "A wild Slowpoke appeared!" << endl;
	if(lol.get_pok() > 0){
		lol.down_pok(); // decrease number of pokeballs and chance of flee
		if (rand()%100 < psychicChance){
			cout << "Slowpoke was caught!" << endl;
			lol.up_slo();
			if(lol.get_slo() == 5 || lol.nope()){
				cout << "***********************************************" << endl;
				lol.what();
				usleep(1000000);
				cout << "Your Slowpoke is evolving!" << endl;
				usleep(1000000);
				cout << "Your Slowpoke evolved into Slowbro!" << endl << endl;
				cout << "Candies needed for Slowking: 15" << endl;
				cout << "***********************************************" << endl;
			}
		}
		else{
			cout << "Oh no! The wild Slowpoke ran away!" << endl;
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
void Slowpoke::nearby(){
	cout << "a Slowpoke is nearby..." << endl;
}
/********************************************************************* 
 ** Function: DEFAULT CONSTRUCTOR
 ** Description: initializes class with proper values 
 ** Parameters: none
 ** Pre-Conditions: object does not exist
 ** Post-Conditions: object exists
 *********************************************************************/
Slowpoke::Slowpoke(){
	type = "Slowpoke";
}
