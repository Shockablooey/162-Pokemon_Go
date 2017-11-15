#include "world.h"

int main(int argc, char** argv){
	bool debug = false;
	char* temp;
	temp = new char[256];
	int commandline;	
	srand(time(NULL)); // seed the random number generator

	#ifdef DEBUG
		cout << "Debug Mode Activated" << endl;
		debug = true;
	#endif		

	if(argc == 2){
		strcpy(temp, argv[1]);
		commandline = atoi(temp); // take command line input for grid size
		if(commandline > 3 && commandline < 21){
			World w(commandline, debug); // make a world 
			w.startup_event_placement(); // place events in the world

			World w2(w); // COPY CONSTRUCTOR 
			w2.game_loop(); // run game with copy
		}
		else
			cout << "between 4x4 and 20x20" << endl;
	}
	else
		cout << "Too many or too few arguments." << endl;
	delete [] temp;
}
