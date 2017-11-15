/********************************************************************* 
 ** SPAWNPOINT. H
 *********************************************************************/
#ifndef SPAWNPOINT_H
#define SPAWNPOINT_H
#include "event.h"

class Spawnpoint : public Event{
	private:
		string type;
	public:
		void interact(Trainer&);
		void nearby();
		string get_type();
		
		Spawnpoint();

};
#endif 
