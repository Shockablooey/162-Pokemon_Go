/********************************************************************* 
 ** ABRA. H
 *********************************************************************/
#ifndef ABRA_H
#define ABRA_H
#include "psychic.h"

class Abra : public Psychic{
	private:
		string type;
	public:
		void interact(Trainer&);
		void nearby();
		string get_type();
		
		Abra();

};
#endif 
