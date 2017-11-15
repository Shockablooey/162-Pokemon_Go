/********************************************************************* 
 ** LOCATION. H
 *********************************************************************/
#ifndef LOCATION_H
#define LOCATION_H
#include "event.h"

class Location{
	private:
		Event* e; // event pointer
	public:
		Event* get_e();		
		void set_e(Event*);
};

#endif
