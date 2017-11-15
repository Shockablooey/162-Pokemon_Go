/********************************************************************* 
 ** FLYING. H
 *********************************************************************/
#ifndef FLYING_H
#define FLYING_H
#include "pokemon.h"

class Flying : public Pokemon{

	protected:
		int flyingChance;
	public:
		Flying(){
			flyingChance = 85;
		}
		virtual ~Flying(){}

};
#endif
