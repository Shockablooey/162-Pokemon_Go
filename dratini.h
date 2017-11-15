/********************************************************************* 
 ** DRATINI. H
 *********************************************************************/
#ifndef DRATINI_H
#define DRATINI_H
#include "flying.h"

class Dratini : public Flying{
	private:
		string type;
	public:
		void interact(Trainer&);
		void nearby();
		string get_type();
		
		Dratini();

};
#endif 
