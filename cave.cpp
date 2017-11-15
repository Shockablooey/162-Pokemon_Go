/********************************************************************* 
 ** CAVE. C P P 
 *********************************************************************/
#include "cave.h"


/********************************************************************* 
 ** Function: get_type
 ** Description: returns the type of the class as a string
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns the string
 *********************************************************************/
string Cave::get_type(){
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
void Cave::interact(Trainer& lol){
	int roll;
	roll = rand()%6;

	cout << "Searching in cave..." << endl;
	if(lol.nope() == false) // don't sleep in debug mode
		usleep(1000000);

	if(roll == 0){
		if(lol.get_geo() < 30 && lol.nope() == false) // if not enough candies && override is not on
			cout << "You found a mega stone for Golem, but you don't have a trained up Graveler..." << endl;
		else if(!lol.found_geo()) // else if we don't already have, do evolve sequence 
			evolve(roll,lol);
		else
			cout << "You didn't find anything special in the cave..." << endl;
	}
	else if(roll == 1){
		if(lol.get_lar() < 50 && lol.nope() == false) 
			cout << "You found a mega stone for Tyranitar, but you don't have a trained up Pupitar..." << endl; 
		else if(!lol.found_lar())
			evolve(roll, lol);
		else
			cout << "You didn't find anything special in the cave..." << endl;
	}
	else if(roll == 2){
		if(lol.get_pid() < 15 && lol.nope() == false) 
			cout << "You found a mega stone for Pidgeot, but you don't have a trained up Pidgeotto..." << endl; 
		else if(!lol.found_pid()) 
			evolve(roll, lol);
		else
			cout << "You didn't find anything special in the cave..." << endl;
	}
	else if(roll == 3){
		if(lol.get_dra() < 50 && lol.nope() == false) 
			cout << "You found a mega stone for Dragonite, but you don't have a trained up Dragonair..." << endl;
		else if(!lol.found_dra())
			evolve(roll, lol);
		else
			cout << "You didn't find anything special in the cave..." << endl;
	}
	else if(roll == 4){
		if(lol.get_abr() < 30 && lol.nope() == false) 
			cout << "You found a mega stone for Alakazam, but you don't have a trained up Kadabra..." << endl;
		else if(!lol.found_abr()) 
			evolve(roll, lol);
		else
			cout << "You didn't find anything special in the cave..." << endl;
	}
	else if(roll == 5){
		if(lol.get_slo() < 15 && lol.nope() == false) 
			cout << "You found a mega stone for Slowking, but you don't have a trained up Slowpoke..." << endl;
		else if(!lol.found_slo()) 
			evolve(roll, lol);
		else
			cout << "You didn't find anything special in the cave..." << endl;
	}
}
/********************************************************************* 
 ** Function: evolve 
 ** Description: changes a bool in the trainer class and does a few couts
 ** Parameters: and int so the function knows which pokemon to do
 ** Pre-Conditions: enough candies of a pokemon 
 ** Post-Conditions: bool is altered
 *********************************************************************/
void Cave::evolve(int type, Trainer &t){

	if(type == 0){
		cout << "***********************************************" << endl;
		t.what();
		if(!t.nope()) // don't sleep in debug mode
			usleep(1000000);
		cout << "Graveler is evolving!" << endl;
		if(!t.nope()) // don't sleep in debug mode
			usleep(1000000);
		cout << "Graveler evolved into Golem!" << endl;
		cout << "***********************************************" << endl;
		t.set_found(type); 
	}
	else if(type == 1){
		cout << "***********************************************" << endl;
		t.what();
		if(!t.nope()) // don't sleep in debug mode
			usleep(1000000);
		cout << "Pupitar is evolving!" << endl;
		if(!t.nope()) // don't sleep in debug mode
			usleep(1000000);
		cout << "Pupitar evolved into Tyranitar!" << endl;
		cout << "***********************************************" << endl;
		t.set_found(type); 
	}
	else if(type == 2){
		cout << "***********************************************" << endl;
		t.what();
		if(!t.nope()) // don't sleep in debug mode
			usleep(1000000);
		cout << "Pidgeotto is evolving!" << endl;
		if(!t.nope()) // don't sleep in debug mode
			usleep(1000000);
		cout << "Pidgeotto evolved into Pidgeot!" << endl;
		cout << "***********************************************" << endl;
		t.set_found(type); 
	}
	else if(type == 3){
		cout << "***********************************************" << endl;
		t.what();
		if(!t.nope()) // don't sleep in debug mode
			usleep(1000000);
		cout << "Dragonair is evolving!" << endl;
		if(!t.nope()) // don't sleep in debug mode
			usleep(1000000);
		cout << "Dragonair evolved into Dragonite!" << endl;
		cout << "***********************************************" << endl;
		t.set_found(type); 
	}
	else if(type == 4){
		cout << "***********************************************" << endl;
		t.what();
		if(!t.nope()) // don't sleep in debug mode
			usleep(1000000);
		cout << "Kadabra is evolving!" << endl;
			usleep(1000000);
		cout << "Kadabra evolved into Alakazam!" << endl;
		cout << "***********************************************" << endl;
		t.set_found(type); 
	}
	else if(type == 5){
		cout << "***********************************************" << endl;
		t.what();
		if(!t.nope()) // don't sleep in debug mode
			usleep(1000000);
		cout << "One of your Slowpokes is evolving!" << endl;
		if(!t.nope()) // don't sleep in debug mode
			usleep(1000000);
		cout << "Slowpoke evolved into Slowking!" << endl;
		cout << "***********************************************" << endl;
		t.set_found(type); 
	}
}
/********************************************************************* 
 ** Function: nearby
 ** Description: outputs a simple cout statement whenever a player is adjacent
 ** Parameters: none
 ** Pre-Conditions: player is adjacent to an event of this class type
 ** Post-Conditions: message is outputted
 *********************************************************************/
void Cave::nearby(){
	cout << "A Cave is nearby..." << endl;
}
/********************************************************************* 
 ** Function: DEFAULT CONSTRUCTOR
 ** Description: initializes class with proper values 
 ** Parameters: none
 ** Pre-Conditions: object does not exist
 ** Post-Conditions: object exists
 *********************************************************************/
Cave::Cave(){
	type = "Cave";
}
