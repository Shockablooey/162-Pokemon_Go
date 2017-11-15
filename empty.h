/********************************************************************* 
 ** EMPTY. H
 *********************************************************************/
#ifndef EMPTY_H
#define EMPTY_H
#include "event.h"

class Empty : public Event{
	private:
		string type;
	public:
		void interact(Trainer&);
		void nearby();
		string get_type();
		
		Empty();

};
#endif 
