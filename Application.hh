#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#include "Object.hh"

using namespace std;

// ==========================================================================
//							CLASSE APPLICATION								|
//							 hérite de Object								|
// ==========================================================================

class Application: public Object{
	
	public :
		~Application(){};
		
	protected :
		int length;
		int width;
		string printColorName() const { return ("\e[1;31m" + name);}
	
		Application(string name, string user, int length, int width,list<Object*>& obj);
		Application(string name, string user, int length, int width, string date, list<Object*>& obj);
		void getInfos() const;
	
};
// ==========================================================================
// ==========================================================================


#endif // __APPLICATION_H__
