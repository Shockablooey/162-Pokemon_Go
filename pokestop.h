/********************************************************************* 
 ** POKESTOP. H
 *********************************************************************/
#ifndef POKESTOP_H
#define POKESTOP_H
#include "event.h"

class Pokestop : public Event{
	private:
		string type;
	public:
		void interact(Trainer&);
		void nearby();
		string get_type();
		
		Pokestop();

};
#endif 
