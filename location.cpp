/********************************************************************* 
 ** LOCATION. C P P 
 *********************************************************************/
#include "location.h"


/********************************************************************* 
 ** Function: get_e
 ** Description: returns the event pointer
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: pointer is returned
 *********************************************************************/
Event* Location::get_e(){
	return e;
}
/********************************************************************* 
 ** Function: set_e 
 ** Description: sets the Event* pointer to some input 
 ** Parameters: the thing that the pointer will point to 
 ** Pre-Conditions: event points to nothing
 ** Post-Conditions: event now points to null or an object
 *********************************************************************/
void Location::set_e(Event* input){
	e = input;
}
