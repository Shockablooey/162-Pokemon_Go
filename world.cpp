/********************************************************************* 
 ** WORLD. C P P 
 *********************************************************************/
#include "world.h"

/********************************************************************* 
 ** Function: game_loop
 ** Description: lets player move, seeing nearby messages and interacting
 ** with events in the square they are on, displaying the grid, legend,
 ** and a few other pretty things
 ** Parameters: none
 ** Pre-Conditions: game has been setup properly
 ** Post-Conditions: game over
 *********************************************************************/
void World::game_loop(){
	char userinput;
	
	system("clear");	
	professor_willow();
	
	// while player does not have all pokemon and he is not on the spawnpoint
	while(t.get_done() == false || grid[t.get_row()][t.get_col()].get_e()->get_type() != "Spawnpoint"){
		display_grid(debug);
		legend_and_joystick();
		grid[t.get_row()][t.get_col()].get_e()->interact(t);

		check_for_replace();
	
		// ADJACENT
		cout << "-------------------------------" << endl;
		if(t.get_row()-1 >= 0)
			grid[t.get_row()-1][t.get_col()].get_e()->nearby();
		if(t.get_row()+1 < gridSize)
			grid[t.get_row()+1][t.get_col()].get_e()->nearby();
		if(t.get_col()-1 >= 0)
			grid[t.get_row()][t.get_col()-1].get_e()->nearby();
		if(t.get_col()+1 < gridSize)
			grid[t.get_row()][t.get_col()+1].get_e()->nearby();
		cout << "-------------------------------" << endl;
	
		// PLAYER MOVEMENT
		cin >> userinput;
		if     (userinput == 'w')
			t.move_up();
		else if(userinput == 'a')
			t.move_left();
		else if(userinput == 's')
			t.move_down(gridSize);
		else if(userinput == 'd')
			t.move_right(gridSize);
	}
	game_over();	
}

/********************************************************************* 
 ** Function: game_over 
 ** Description: just text
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::game_over(){
	cout << "*************************************************************************************" << endl;
	cout << "*                                                                                   *" << endl;
	cout << "*         CONGRATUATIONS, TRAINER!                                                  *" << endl;
	cout << "*                                                                                   *" << endl;
	cout << "*         You've caught all the pokemon!                                            *" << endl;
	cout << "*         Your contribution to my research is very appreciated.                     *" << endl;
	cout << "*         The road doesn't end here! Go train some more Pokemon!                    *" << endl;
	cout << "*                                                                                   *" << endl;
	cout << "*************************************************************************************" << endl;
}
/********************************************************************* 
 ** Function: professor_willow 
 ** Description: just text
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
void World::professor_willow(){
	cout << "*************************************************************************************" << endl;
	cout << "Hello there!" << endl;
	cout << "I am Professor Willow." << endl;
	cout << "Press ENTER to continue" << endl;
	cin.ignore();
	cout << "Did you know that this world is inhabited by creatures known as Pokemon?" << endl;
	cin.ignore();
	cout << "Pokemon can be found in every corner of the earth." << endl;
	cin.ignore();
	cout << "Some run across the plains, others fly through the skies, some live in the mountains," << endl;
	cout << "or in the forests, or near water..." << endl;
	cin.ignore();
	cout << "I have spent my whole life studying them and their regional distribution." << endl;
	cin.ignore();
	cout << "Will you help me with my research?" << endl;
	cin.ignore();
	cout << "Great! Go into the world and catch and evolve Pokemon! Then come back to me." << endl;
	cin.ignore();
	cout << "Good luck trainer!" << endl;
	cout << "*************************************************************************************" << endl;
}
/********************************************************************* 
 ** Function: check_for_replace
 ** Description: checks the type of the current location.  if it is
 ** a pokemon, calls the replace event function
 ** Parameters: none
 ** Pre-Conditions: player just interacted with an event
 ** Post-Conditions: event is moved
 *********************************************************************/
void World::check_for_replace(){
	string type = grid[t.get_row()][t.get_col()].get_e()->get_type();
	
		if(type == "Geodude" || type == "Larvitar" || type == "Pidgey" || type == "Dratini" || type == "Abra" || type == "Slowpoke")
			replace_event();
}
/********************************************************************* 
 ** Function: replace_event
 ** Description: sets current location to empty and finds a new place 
 ** for the event, given the new place is empty
 ** Parameters: none
 ** Pre-Conditions: event is where the player stands
 ** Post-Conditions: location is empty.  event is somewhere else
 *********************************************************************/
void World::replace_event(){
	string type = grid[t.get_row()][t.get_col()].get_e()->get_type();
	bool good;
	int rand1;
	int rand2;

	do{
		good = true; // reset bool
		rand1 = rand()%gridSize; // random row
		rand2 = rand()%gridSize; // random col

		if(grid[rand1][rand2].get_e()->get_type() == "Empty"){ // if location free
			swap( grid[rand1][rand2], grid[t.get_row()][t.get_col()]); // swap the pointers 
		}
		else
			good = false; // set good to false and do another random check
	}while(good == false);
}
/********************************************************************* 
 ** Function: display_grid 
 ** Description: shows the grid for debug/grading purposes when bool 
 ** debug is true.  Will also display the simple grid with just the
 ** players location if debug is off
 ** Parameters: bool debug
 ** Pre-Conditions: none
 ** Post-Conditions: displays grid
 *********************************************************************/
void World::display_grid(bool debug){

	system("clear");
	cout << "+"; // TOP
	for(int a=0; a < gridSize; a++)
		cout << "===+";
	cout << endl;	

	for(int i=0; i < gridSize; i++){ // FOR EACH MIDDLE ROW

		for(int p=0; p < gridSize; p++) // ROW OF SPACES, PIPES, AND SYMBOLS
			cout << "| " << print_symbol(i,p) << " ";
		cout << "|" << endl;

		if(i < (gridSize-1)){
			cout << "+"; // DIVIDING ROW
			for(int j=0; j < gridSize; j++)
				cout << "---+"; 
			cout << endl;
		}
	}

	cout << "+"; // BOTTOM
	for(int z=0; z < gridSize; z++)
		cout << "===+";
	cout << endl;	
}
/********************************************************************* 
 ** Function: legend_and_joystick 
 ** Description: legend for a few symbols and a visual HUD
 ** Parameters: none
 ** Pre-Conditions: should be called after the display_grid() function
 ** at all times
 ** Post-Conditions: display is cout'ed
 *********************************************************************/
void World::legend_and_joystick(){

	cout <<	"      _____        " << endl;
	cout << "     |     |       " << endl;
	cout << "  ___|  W  |___    " << endl;
	cout << " |             |   " << endl;
	cout << " | A         D |   " << endl;
	cout << " |___       ___|   Spawnpoint: H" << endl;
	cout << "     |  S  |       Cave: C" << endl;
	cout << "     |_____|       Pokestop: @" << endl << endl;
}
/********************************************************************* 
 ** Function: print_symbol 
 ** Description: takes in two indicis for the grid and prints out the
 ** proper symbol
 ** Parameters: two integers from the for loops
 ** Pre-Conditions: two ints are given
 ** Post-Conditions: a symbol is printed
 *********************************************************************/
char World::print_symbol(int row, int col){
	char wow;

	if(row == t.get_row() && col == t.get_col()) 
		wow = 'X'; // IF THE PLAYER IS HERE		

	else if(grid[row][col].get_e()->get_type() == "Pokestop" && debug == true)
		wow = '@';
	else if(grid[row][col].get_e()->get_type() == "Cave" && debug == true)
		wow = 'C';
	else if(grid[row][col].get_e()->get_type() == "Spawnpoint" && debug == true)
		wow = 'H';
	else if(grid[row][col].get_e()->get_type() == "Geodude" && debug == true)
		wow = 'G';
	else if(grid[row][col].get_e()->get_type() == "Larvitar" && debug == true)
		wow = 'L';
	else if(grid[row][col].get_e()->get_type() == "Pidgey" && debug == true)
		wow = 'P';
	else if(grid[row][col].get_e()->get_type() == "Dratini" && debug == true)
		wow = 'D';
	else if(grid[row][col].get_e()->get_type() == "Abra" && debug == true)
		wow = 'A';
	else if(grid[row][col].get_e()->get_type() == "Slowpoke" && debug == true)
		wow = 'S';
	else 
		wow = ' ';

	return wow;	
}	
/********************************************************************* 
 ** Function: get_gridSize
 ** Description: returns the int for size of grid
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: int returned
 *********************************************************************/
int World::get_gridSize(){
	return gridSize;
}
/********************************************************************* 
 ** Function: get_debug
 ** Description: returns the bool for debug mode 
 ** Parameters: none 
 ** Pre-Conditions: none
 ** Post-Conditions: bool returned
 *********************************************************************/
bool World::get_debug(){
	return debug;
}
/********************************************************************* 
 ** Function: get_grid
 ** Description: returns the 2D location grid 
 ** Parameters: none 
 ** Pre-Conditions: none
 ** Post-Conditions: array returned 
 *********************************************************************/
Location** World::get_grid(){
	return grid;
}
/********************************************************************* 
 ** Function: get_spawnRow
 ** Description: returns int for spawnpoint coordinates
 ** Parameters: none 
 ** Pre-Conditions: none
 ** Post-Conditions: int returned
 *********************************************************************/
int World::get_spawnRow(){
	return spawnRow;
}
/********************************************************************* 
 ** Function: get_spawnCol
 ** Description: returns int for spawnpoint coordinates
 ** Parameters: none 
 ** Pre-Conditions: none
 ** Post-Conditions: int returned
 *********************************************************************/
int World::get_spawnCol(){
	return spawnCol;
}
/********************************************************************* 
 ** Function: OPERATOR OVERLOAD 
 ** Description: deletes object and copy constructs 
 ** Parameters: old world object address
 ** Pre-Conditions: world object is something
 ** Post-Conditions: world object is something else
 *********************************************************************/
void World::operator=(World& input){
	for(int j=0; j < gridSize; j++) // deletes pointers
		for (int k=0; k < gridSize; k++)
			delete grid[j][k].get_e();
	for(int i=0; i < gridSize; i++) // delete 2nd Dim.
		delete [] grid[i];
	delete [] grid; // delete 1st Dim.

	gridSize = input.get_gridSize();
	debug = input.get_debug();
	spawnRow = input.get_spawnRow();
	spawnCol = input.get_spawnCol();
	
	t.set_debug(debug);

	grid = new Location* [gridSize]; // 1st Dim.
	
	for(int i=0; i < gridSize; i++) // 2nd Dim.
		grid[i] = new Location [gridSize];

	for(int j=0; j < gridSize; j++) // set all indicis to empty class
		for (int k=0; k < gridSize; k++)
			grid[j][k].set_e(NULL); 

	for(int a=0; a < gridSize; a++)
		for(int b=0; b < gridSize; b++){
			string type = input.get_grid()[a][b].get_e()->get_type(); // get type from old object
			make_object(type, a, b);		
		}
	find_spawn(); // use spawnRow and spawnCol to set player location
	
}
/********************************************************************* 
 ** Function: COPY CONSTRUCTOR
 ** Description: copy constructor 
 ** Parameters: old world object address
 ** Pre-Conditions: no world object exists
 ** Post-Conditions: world object exists
 *********************************************************************/
World::World(World& input){
	gridSize = input.get_gridSize();
	debug = input.get_debug();

	spawnRow = input.get_spawnRow();
	spawnCol = input.get_spawnCol();
	
	t.set_debug(debug);

	grid = new Location* [gridSize]; // 1st Dim.
	
	for(int i=0; i < gridSize; i++) // 2nd Dim.
		grid[i] = new Location [gridSize];

	for(int j=0; j < gridSize; j++) // set all indicis to empty class
		for (int k=0; k < gridSize; k++)
			grid[j][k].set_e(NULL); 

	for(int a=0; a < gridSize; a++)
		for(int b=0; b < gridSize; b++){
			string type = input.get_grid()[a][b].get_e()->get_type(); // get type from old object
			make_object(type, a, b);		
		}
	find_spawn(); // use spawnRow and spawnCol to set player location
}
/********************************************************************* 
 ** Function: make_object
 ** Description: takes in a string and chooses between different object
 ** creations
 ** Parameters: string for which type and the for loop ints
 ** Pre-Conditions: type is received from old array
 ** Post-Conditions: new object made
 *********************************************************************/
void World::make_object(string input, int x, int y){
	if(input == "Geodude")
		grid[x][y].set_e(new Geodude);
	else if(input == "Larvitar")
		grid[x][y].set_e(new Larvitar);
	else if(input == "Pidgey")
		grid[x][y].set_e(new Pidgey);
	else if(input == "Dratini")
		grid[x][y].set_e(new Dratini);
	else if(input == "Abra")
		grid[x][y].set_e(new Abra);
	else if(input == "Slowpoke")
		grid[x][y].set_e(new Slowpoke);

	else if(input == "Pokestop")
		grid[x][y].set_e(new Pokestop);
	else if(input == "Cave")
		grid[x][y].set_e(new Cave);
	else if(input == "Empty")
		grid[x][y].set_e(new Empty);
	else if(input == "Spawnpoint")
		grid[x][y].set_e(new Spawnpoint);
		
}
/********************************************************************* 
 ** Function: CONSTRUCTOR
 ** Description: default constructor
 ** Parameters: none
 ** Pre-Conditions: no world object exists
 ** Post-Conditions: world object exists
 *********************************************************************/
World::World(int size, bool input){
	gridSize = size;
	this->debug = input;

	t.set_debug(debug);

	grid = new Location* [gridSize]; // 1st Dim.

	for(int i=0; i < gridSize; i++) // 2nd Dim.
		grid[i] = new Location [gridSize];

	for(int j=0; j < gridSize; j++) // set all indicis to empty class
		for (int k=0; k < gridSize; k++)
			grid[j][k].set_e(NULL); 	
}
/********************************************************************* 
 ** Function: DESTRUCTOR
 ** Description: frees memory from the 2D polymorphic array
 ** Parameters: none
 ** Pre-Conditions: location array exists 
 ** Post-Conditions: location array does not exist
 *********************************************************************/
World::~World(){
	for(int j=0; j < gridSize; j++) // deletes pointers
		for (int k=0; k < gridSize; k++)
			delete grid[j][k].get_e();

	for(int i=0; i < gridSize; i++) // delete 2nd Dim.
		delete [] grid[i];

	delete [] grid; // delete 1st Dim.

}
/********************************************************************* 
 ** Function: find_spawn 
 ** Description: looks through the grid for the spawn and sets the 
 ** values so that the trainer's location can start there
 ** Parameters: none 
 ** Pre-Conditions: location of spawn has been set
 ** Post-Conditions: players location is now at spawn
 *********************************************************************/
void World::find_spawn(){
	for(int i=0; i < gridSize; i++)
		for(int j=0; j < gridSize; j++)
			if(grid[i][j].get_e()->get_type() == "Spawnpoint"){
				spawnRow = i;
				spawnCol = j;
				t.set_location(i,j);		
			}
}
/********************************************************************* 
 ** Function: startup_event_placement
 ** Description: calls place_event multiple times for all the necessary
 ** event locations, and then fills the rest with empty spaces or pokestops
 ** Parameters: none
 ** Pre-Conditions: location array event pointers are all NULL
 ** Post-Conditions: the pointers now point to addresses of events
 *********************************************************************/
void World::startup_event_placement(){
	place_event(new Spawnpoint);
	place_event(new Pokestop);
	place_event(new Pokestop);
	place_event(new Cave);
	place_event(new Cave);

	place_event(new Geodude);
	place_event(new Larvitar);
	place_event(new Pidgey);
	place_event(new Dratini);
	place_event(new Abra);
	place_event(new Slowpoke);


	for(int j=0; j < gridSize; j++) // set all remaining to either an Empty or Pokestop
		for(int k=0; k < gridSize; k++){
			if(rand()%100 < 5 && grid[j][k].get_e() == NULL){ // 20% chance of Pokestop
				grid[j][k].set_e(new Pokestop);
			}
			if(rand()%100 < 3 && grid[j][k].get_e() == NULL){ // 10% chance of Cave
				grid[j][k].set_e(new Cave);
			}
			else if(grid[j][k].get_e() == NULL){
				grid[j][k].set_e(new Empty);
			}

		}	
	find_spawn();
}
/********************************************************************* 
 ** Function: place_event 
 ** Description: assigns the address of a passed object to an event 
 ** pointer that is in location IF the pointer is NULL, otherwise
 ** it rerolls for new indicis.
 ** Parameters: the address of the passed object
 ** Pre-Conditions: the array index is NULL
 ** Post-Conditions: the array index's event pointer now holds the
 ** address of an object
 *********************************************************************/
void World::place_event(Event* input){
	bool good;
	int rand1;
	int rand2;

	do{
		good = true; // reset bool
		rand1 = rand()%gridSize;
		rand2 = rand()%gridSize;

		if(grid[rand1][rand2].get_e() == NULL){
			// set event pointer to address of an inherited object
			grid[rand1][rand2].set_e(input); 
		}
		else
			good = false; // set good to false and do another random check
	}while(good == false);
}
