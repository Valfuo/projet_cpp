#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#include "Object.hh"

using namespace std;

class Application: public Object{
	
	protected :
		Application(string name, bool readEnable, string user): Object(name, readEnable, user){};
			
	
};

#endif // __APPLICATION_H__
