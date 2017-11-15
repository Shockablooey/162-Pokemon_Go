/********************************************************************* 
 ** SLOWPOKE. H
 *********************************************************************/
#ifndef SLOWPOKE_H
#define SLOWPOKE_H
#include "psychic.h"

class Slowpoke : public Psychic{
	private:
		string type;
	public:
		void interact(Trainer&);
		void nearby();
		string get_type();
		
		Slowpoke();

};
#endif 
