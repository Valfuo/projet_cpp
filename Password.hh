#ifndef __PASSWORD_HH__
#define __PASSWORD_HH__
#include "Application.hh"

using namespace std;

// ==========================================================================
//							CLASSE PASSWORD									|
//						 hérite de Application								|
// ==========================================================================


class Password : public Application{

	public :
		Password(string name, string user, int length, int width, string date, list<Object*>& obj): 
				Application(name, user, length, width, date, obj){};
		void open() const;	
		~Password(){};
		
};
// ==========================================================================
// ==========================================================================

#endif // __PASSWORD_HH__
