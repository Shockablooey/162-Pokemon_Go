/********************************************************************* 
 ** EVENT. H
 *********************************************************************/
#ifndef EVENT_H
#define EVENT_H
#include "trainer.h"

class Event{
	private:
	
	public: // A WHOLE LOT OF PURE VIRTUALS
		virtual void interact(Trainer&)=0;
		virtual void nearby()=0;
		virtual string get_type()=0;
		virtual ~Event(){}
};


#endif
