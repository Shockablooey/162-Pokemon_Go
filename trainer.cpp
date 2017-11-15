/********************************************************************* 
 ** TRAINER. C P P 
 *********************************************************************/
#include "trainer.h"

/********************************************************************* 
 ** Function: CONSTRUCTOR
 ** Description: default constructor
 ** Parameters: none
 ** Pre-Conditions: no trainer object exists
 ** Post-Conditions: trainer object exists
 *********************************************************************/
Trainer::Trainer(){
	done = false;

	numGeodudeCandy = 0;
	numLarvitarCandy = 0;
	numPidgeyCandy = 0;
	numDratiniCandy = 0;
	numAbraCandy = 0;
	numSlowpokeCandy = 0;
	numPokeballs = 0;

	foundGeo = false;
	foundLar = false;
	foundPid = false;
	foundDra = false;
	foundAbr = false;
	foundSlo = false;
}




/********************************************************************* 
 ** Function: set_debug
 ** Description: sets the bool for determining candy override
 ** Parameters: the bool in the world
 ** Pre-Conditions: bool set in world and sent to trainer
 ** Post-Conditions: bool set in trainer
 *********************************************************************/
void Trainer::set_debug(bool input){
	debugON = input; // for debug mode & candy overrides
}
/********************************************************************* 
 ** Function: nope 
 ** Description: returns bool nope for debug purposes
 ** Parameters: none
 ** Pre-Conditions: candies are being edited
 ** Post-Conditions: return bool
 *********************************************************************/
bool Trainer::nope(){
	return debugON;
}



/********************************************************************* 
 ** Function: what 
 ** Description: cout's a word
 ** Parameters: none
 ** Pre-Conditions: no word printed
 ** Post-Conditions: word printed
 *********************************************************************/
void Trainer::what(){
	ifstream input;
	input.open("what");
	string temp;

	while(!input.eof()){
		getline(input,temp);
		cout << temp << endl;
	}
		
}

/********************************************************************* 
 ** Function: set_found
 ** Description: sets the proper bool to true for a found pokemon
 ** Parameters: int for which pokemon has been evolved  
 ** Pre-Conditions: bool is false
 ** Post-Conditions: a bool is changed to true
 *********************************************************************/
void Trainer::set_found(int input){
	if(input == 0)
		foundGeo = true;
	else if(input == 1)
		foundLar = true;
	else if(input == 2)
		foundPid = true;
	else if(input == 3)
		foundDra = true;
	else if(input == 4)
		foundAbr = true;
	else if(input == 5)
		foundSlo = true;

	if(foundGeo && foundLar && foundPid && foundDra && foundAbr && foundSlo){
		done = true;
		cout << "You've found all the pokemon!  Return to Professor Willow!" << endl;
	}
	else{
		cout << "Stage 3 evolutions left: " << endl;
		if(!foundGeo)
			cout << "Golem" << endl;
		if(!foundLar)
			cout << "Tyranitar" << endl;
		if(!foundPid)
			cout << "Pidgeot" << endl;
		if(!foundDra)
			cout << "Dragonite" << endl;
		if(!foundAbr)
			cout << "Alakazam" << endl;
		if(!foundSlo)
			cout << "Slowking" << endl;
	}

}
/********************************************************************* 
 ** Function: get_done 
 ** Description: tells the world game loop if the player has won yet 
 ** Parameters: none
 ** Pre-Conditions: game is still going
 ** Post-Conditions: loop ends if location type == spawnpoint and the
 ** bool is returned true
 *********************************************************************/
bool Trainer::get_done(){
	return done;
}







/********************************************************************* 
 ** Function: Trainer::get_col
 ** Description: returns an index for the players location
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: index for players location returned
 *********************************************************************/
int Trainer::get_col(){
	return col;
}
/********************************************************************* 
 ** Function: Trainer::get_row
 ** Description: returns an index for the players location
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: index for players location returned
 *********************************************************************/
int Trainer::get_row(){
	return row;
}
/********************************************************************* 
 ** Function: set_location
 ** Description: sets the players location 
 ** Parameters: two ints for row and col in the grid
 ** Pre-Conditions: player is somewhere
 ** Post-Conditions: player is now somewhere else
 *********************************************************************/
void Trainer::set_location(int inputRow, int inputCol){
	row = inputRow;
	col = inputCol;
}












/********************************************************************* 
 ** Function: Trainer::get_pokeballs
 ** Description: returns the number of pokeballs
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: number of pokeballs is returned
 *********************************************************************/
int Trainer::get_pok(){
	return numPokeballs;
}
/********************************************************************* 
 ** Function: Trainer::get_numCandies
 ** Description: returns the number of candies for a particular pokemon
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: number of candies is returned
 *********************************************************************/
int Trainer::get_geo(){
	return numGeodudeCandy;
}
/********************************************************************* 
 ** Function: Trainer::get_numCandies
 ** Description: returns the number of candies for a particular pokemon
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: number of candies is returned
 *********************************************************************/
int Trainer::get_lar(){
	return numLarvitarCandy;
}
/********************************************************************* 
 ** Function: Trainer::get_numCandies
 ** Description: returns the number of candies for a particular pokemon
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: number of candies is returned
 *********************************************************************/
int Trainer::get_pid(){
	return numPidgeyCandy;
}
/********************************************************************* 
 ** Function: Trainer::get_numCandies
 ** Description: returns the number of candies for a particular pokemon
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: number of candies is returned
 *********************************************************************/
int Trainer::get_dra(){
	return numDratiniCandy;
}
/********************************************************************* 
 ** Function: Trainer::get_numCandies
 ** Description: returns the number of candies for a particular pokemon
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: number of candies is returned
 *********************************************************************/
int Trainer::get_abr(){
	return numAbraCandy;
}
/********************************************************************* 
 ** Function: Trainer::get_numCandies
 ** Description: returns the number of candies for a particular pokemon
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: number of candies is returned
 *********************************************************************/
int Trainer::get_slo(){
	return numSlowpokeCandy;
}








/********************************************************************* 
 ** Function: found_geo 
 ** Description: returns bool for whether third stage has been found 
 ** Parameters: none
 ** Pre-Conditions: more than 25 candies is had and player is at cave
 ** or game is trying to end
 ** Post-Conditions: bool is returned 
 *********************************************************************/
bool Trainer::found_geo(){
	return foundGeo;
}
/********************************************************************* 
 ** Function: found_lar 
 ** Description: returns bool for whether third stage has been found 
 ** Parameters: none
 ** Pre-Conditions: more than 25 candies is had and player is at cave
 ** or game is trying to end
 ** Post-Conditions: bool is returned 
 *********************************************************************/
bool Trainer::found_lar(){
	return foundLar;
}
/********************************************************************* 
 ** Function: found_pid 
 ** Description: returns bool for whether third stage has been found 
 ** Parameters: none
 ** Pre-Conditions: more than 25 candies is had and player is at cave
 ** or game is trying to end
 ** Post-Conditions: bool is returned 
 *********************************************************************/
bool Trainer::found_pid(){
	return foundPid;
}
/********************************************************************* 
 ** Function: found_dra 
 ** Description: returns bool for whether third stage has been found 
 ** Parameters: none
 ** Pre-Conditions: more than 25 candies is had and player is at cave
 ** or game is trying to end
 ** Post-Conditions: bool is returned 
 *********************************************************************/
bool Trainer::found_dra(){
	return foundDra;
}
/********************************************************************* 
 ** Function: found_abr 
 ** Description: returns bool for whether third stage has been found 
 ** Parameters: none
 ** Pre-Conditions: more than 25 candies is had and player is at cave
 ** or game is trying to end
 ** Post-Conditions: bool is returned 
 *********************************************************************/
bool Trainer::found_abr(){
	return foundAbr;
}
/********************************************************************* 
 ** Function: found_slo 
 ** Description: returns bool for whether third stage has been found 
 ** Parameters: none
 ** Pre-Conditions: more than 25 candies is had and player is at cave
 ** or game is trying to end
 ** Post-Conditions: bool is returned 
 *********************************************************************/
bool Trainer::found_slo(){
	return foundSlo;
}













/********************************************************************* 
 ** Function: move_left 
 ** Description: moves the player by editing row/col in struct pop
 ** Parameters: none
 ** Pre-Conditions: player is in a location
 ** Post-Conditions: player is now in a different location
 *********************************************************************/
void Trainer::move_left(){
	if(col > 0)
		col--; // decrement col
	else{
		cout << "There's no pokemon over there." << endl;
		usleep(100000);
	}
}
/********************************************************************* 
 ** Function: move_right 
 ** Description: moves the player by editing row/col in struct pop
 ** Parameters: none
 ** Pre-Conditions: player is in a location
 ** Post-Conditions: player is now in a different location
 *********************************************************************/
void Trainer::move_right(int max){
	if(col < (max-1) )
		col++; // decrement col
	else{
		cout << "There's no pokemon over there." << endl;
		usleep(100000);
	}
}
/********************************************************************* 
 ** Function: move_up 
 ** Description: moves the player by editing row/col in struct pop
 ** Parameters: none
 ** Pre-Conditions: player is in a location
 ** Post-Conditions: player is now in a different location
 *********************************************************************/
void Trainer::move_up(){
	if(row > 0)
		row--; // decrement col
	else{ 
		cout << "There's no pokemon over there." << endl;
		usleep(100000);
	}
}
/********************************************************************* 
 ** Function: move_down 
 ** Description: moves the player by editing row/col in struct pop
 ** Parameters: none
 ** Pre-Conditions: player is in a location
 ** Post-Conditions: player is now in a different location
 *********************************************************************/
void Trainer::move_down(int max){
	if(row < (max-1) )
		row++; // decrement col
	else{
		cout << "There's no pokemon over there." << endl;
		usleep(100000);
	}
}











/********************************************************************* 
 ** Function: up_pok
 ** Description: increases the number of pokeballs by amount of spin 
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: pokeballs increased by amount of spin
 *********************************************************************/
void Trainer::up_pok(int roll){
	if(numPokeballs < (50-roll) ){ 
		cout << "You got " << roll << " pokeballs!" << endl;
		numPokeballs += roll;
		cout << "Pokeballs: " << numPokeballs << endl;
	}
	else
		cout << "You can only hold 50 Pokeballs!" << endl;
}
/********************************************************************* 
 ** Function: down_pok
 ** Description: decreases the number of pokeballs by 1
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: candies increased by 5
 *********************************************************************/
void Trainer::down_pok(){

	cout << "Throwing pokeball!" << endl;
	numPokeballs--;
	cout << "Pokeballs: " << numPokeballs << endl << endl;

	if(rand()%100 < 33){ // 33% chance to break out
		cout << "The pokemon broke out!" << endl;
		cout << "Trying again..." << endl;
		numPokeballs--;
		cout << "Pokeballs: " << numPokeballs << endl << endl;

		if(rand()%100 < 33){ // 33% chance to break out a second time
			cout << "The pokemon broke out!" << endl;
			cout << "Trying again..." << endl;
			numPokeballs--;
			cout << "Pokeballs: " << numPokeballs << endl << endl;
		}
	}
}
/********************************************************************* 
 ** Function: upGeodudeCandy
 ** Description: increases the number of candies by 5
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: candies increased by 5
 *********************************************************************/
void Trainer::up_geo(){
	numGeodudeCandy+=5;
	cout << "Geodude candy: " << numGeodudeCandy << endl;
}
/********************************************************************* 
 ** Function: upLarvitarCandy
 ** Description: increases the number of candies by 5
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: candies increased by 5
 *********************************************************************/
void Trainer::up_lar(){
	numLarvitarCandy+=5;
	cout << "Larvitar candy: " << numLarvitarCandy << endl;
}
/********************************************************************* 
 ** Function: upPidgeyCandy
 ** Description: increases the number of candies by 5
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: candies increased by 5
 *********************************************************************/
void Trainer::up_pid(){
	numPidgeyCandy+=5;
	cout << "Pidgey candy: " << numPidgeyCandy << endl;
}
/********************************************************************* 
 ** Function: upDratiniCandy
 ** Description: increases the number of candies by 5
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: candies increased by 5
 *********************************************************************/
void Trainer::up_dra(){
	numDratiniCandy+=5;
	cout << "Dratini candy: " << numDratiniCandy << endl;
}
/********************************************************************* 
 ** Function: upAbraCandy
 ** Description: increases the number of candies by 5
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: candies increased by 5
 *********************************************************************/
void Trainer::up_abr(){
	numAbraCandy+=5;
	cout << "Abra candy: " << numAbraCandy << endl;
}
/********************************************************************* 
 ** Function: upSlowpokeCandy
 ** Description: increases the number of candies by 5
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: candies increased by 5
 *********************************************************************/
void Trainer::up_slo(){
	numSlowpokeCandy+=5;
	cout << "Slowpoke candy: " << numSlowpokeCandy << endl;
}
