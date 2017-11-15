/********************************************************************* 
 ** PSYCHIC. H
 *********************************************************************/
#ifndef PSYCHIC_H
#define PSYCHIC_H
#include "pokemon.h"

class Psychic : public Pokemon{

	protected:
		int psychicChance;
	public:
		Psychic(){
			psychicChance = 65;
		}
		virtual ~Psychic(){}

};
#endif
