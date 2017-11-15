/********************************************************************* 
 ** ROCK. H
 *********************************************************************/
#ifndef ROCK_H
#define ROCK_H
#include "pokemon.h"

class Rock : public Pokemon{

	protected:
		int rockChance;
	public:
		Rock(){
			rockChance = 75;
		}
		virtual ~Rock(){}

};
#endif
