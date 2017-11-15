/********************************************************************* 
 ** ERROR. H
 *********************************************************************/
#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // use time for seeding
#include <unistd.h> // use for usleep()
#include <algorithm> // for swap()

using namespace std;

class Error{
	private:

	public:
		int userinput_int(const int&, const int&, string);
		// upper bound, lower bound, string prompt
};

#endif
