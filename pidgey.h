/********************************************************************* 
 ** PIDGEY. H
 *********************************************************************/
#ifndef PIDGEY_H
#define PIDGEY_H
#include "flying.h"

class Pidgey : public Flying{
	private:
		string type;
	public:
		void interact(Trainer&);
		void nearby();
		string get_type();
		
		Pidgey();

};
#endif 
