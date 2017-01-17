#ifndef __TEXT_HH__
#define __TEXT_HH__
#include "Object.hh"

using namespace std;

// ==========================================================================
//								CLASSE TEXT									|
//						   	  hérite de Object								|
// ==========================================================================

class Text : public Object{
	
	protected :
		string path;
		
	public :
		Text(string name, string user, string path, list<Object*>& obj);
		Text(string name, string user, string path, string date, list<Object*>& obj);
		void open() const;
		string printColorName() const { return ("\e[0;37m" + name);}
		void getInfos() const;	
		~Text(){};
};
// ==========================================================================
// ==========================================================================

#endif // __TEXT_HH__

