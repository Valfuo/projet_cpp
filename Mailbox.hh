#ifndef __MAILBOX_HH__
#define __MAILBOX_HH__
#include "Object.hh"
#include "Application.hh"
#include <gtkmm.h>	
#include <list>
#include <string>

using namespace std;


// ==========================================================================
//							CLASSE MAILBOX									|
//						 hérite de Application								|
// ==========================================================================


class Mailbox : public Application{

	public :
		Mailbox(string name, string user, int length, int width, string date, list<Object*>& obj): 
				Application(name, user, length, width, date, obj){};
		
		void open() const;
};
// ==========================================================================
// ==========================================================================

#endif // __MAILBOX_HH__
