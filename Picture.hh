#ifndef __PICTURE_HH__
#define __PICTURE_HH__
#include "Object.hh"
#include <string>

using namespace std;

// ==========================================================================
//							CLASSE PICTURE									|
//						   hérite de Object									|
// ==========================================================================

class Picture : public Object{
	
	protected :
		string path;
	
	public :
		Picture(string name, string user, string path, list<Object*>& obj);
		Picture(string name, string user, string path, string date, list<Object*>& obj);
		void open() const;
		string printColorName() const { return ("\e[1;35m" + name);}
		void getInfos() const;	
	
};
// ==========================================================================
// ==========================================================================

#endif // __PICTURE_HH__
