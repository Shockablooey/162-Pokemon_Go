/********************************************************************* 
 ** LARVITAR. H
 *********************************************************************/
#ifndef LARVITAR_H
#define LARVITAR_H
#include "rock.h"

class Larvitar : public Rock{
	private:
		string type;
	public:
		void interact(Trainer&);
		void nearby();
		string get_type();
		
		Larvitar();

};
#endif 
