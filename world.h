/********************************************************************* 
 ** WORLD. H
 *********************************************************************/
#ifndef WORLD_H
#define WORLD_H
#include "location.h"
#include "empty.h"

#include "pokestop.h"
#include "cave.h"
#include "spawnpoint.h"

#include "geodude.h"
#include "larvitar.h"
#include "pidgey.h"
#include "dratini.h"
#include "abra.h"
#include "slowpoke.h"



class World{
	private:
		int gridSize;
		bool debug;
		int spawnRow;
		int spawnCol;
		Trainer t;
		Location** grid;
	public:
		// STARTUP
		void startup_event_placement();
		void find_spawn();
		
		// DISPLAY 
		void display_grid(bool);
		char print_symbol(int,int);
		void legend_and_joystick();
		
		// ELSE
		void place_event(Event*);
		void game_loop();
		void check_for_replace();
		void replace_event();
		void professor_willow(); // minor text fixes
		void game_over();
		
		// BIG THREE
		World(int, bool);
		~World();
		World(World &);
		void make_object(string, int, int);
		int get_gridSize();
		bool get_debug();
		int get_spawnRow();
		int get_spawnCol();
		Location** get_grid();
		void operator=(World &);	
};

#endif
