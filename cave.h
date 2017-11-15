/********************************************************************* 
 ** CAVE. H
 *********************************************************************/
#ifndef CAVE_H
#define CAVE_H
#include "event.h"

class Cave : public Event{
	private:
		string type;
		string caveType;
	public:
		void interact(Trainer&);
		void nearby();
		string get_type();
		void evolve(int,Trainer&); 
		
		Cave();

};
#endif 
