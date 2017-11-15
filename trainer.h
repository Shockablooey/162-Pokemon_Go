/********************************************************************* 
 ** TRAINER. H
 *********************************************************************/
#ifndef TRAINER_H
#define TRAINER_H
#include "error.h"

class Trainer{
	private:
		// OVERRIDE
		bool debugON;
	
		// MOVEMENT
		int row;
		int col;

		// STOCK
		int numGeodudeCandy;
		int numLarvitarCandy;
		int numPidgeyCandy;
		int numDratiniCandy;
		int numAbraCandy;
		int numSlowpokeCandy;
		int numPokeballs;
	
		// POKEMON
		bool foundGeo; // found third stage of Geo
		bool foundLar;
		bool foundPid;
		bool foundDra;
		bool foundAbr;
		bool foundSlo;
		bool done; // for ending the game
	public:
		// INCREASE STOCK
		void up_geo();
		void up_lar();
		void up_pid();
		void up_dra();
		void up_abr();
		void up_slo();

		void up_pok(int); // receives input based on random roll
		void down_pok();

		// RETURN STOCK VALUES
		int get_geo();
		int get_lar();
		int get_pid();
		int get_dra();
		int get_abr();
		int get_slo();
		int get_pok(); // returns number of pokeballs

		// FOUND STAGE THREE
		void set_found(int); // changes bools
		bool found_geo();
		bool found_lar();
		bool found_pid();
		bool found_dra();
		bool found_abr();
		bool found_slo();

		// MOVEMENT
		void move_left(); // edits p
		void move_right(int);
		void move_up();
		void move_down(int);
		int get_row();
		int get_col();
		void set_location(int,int);
	
		// ELSE
		void what();	
		bool nope(); // used for debug overrides
		void set_debug(bool);
		bool get_done();

		// CONSTRUCTOR
		Trainer(); // give player coordinates for spawn	
	
		
		
		
};


#endif
