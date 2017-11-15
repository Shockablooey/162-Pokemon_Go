/********************************************************************* 
 ** GEODUDE. H
 *********************************************************************/
#ifndef GEODUDE_H
#define GEODUDE_H
#include "rock.h"

class Geodude : public Rock{
	private:
		string type;
	public:
		void interact(Trainer&);
		void nearby();
		string get_type();
		
		Geodude();

};
#endif 
