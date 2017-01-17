#ifndef __OBJECT_HH__
#define __OBJECT_HH__
#include <iostream>
#include <list>

using namespace std;


// ==========================================================================
//								CLASSE OBJECT								|
// ==========================================================================

class Object{
	
	protected :
		string name;
		string user;
		string date;
		Object(string name, string user, list<Object*>& obj);
		Object(string name, string user, string date, list<Object*>& obj);													
	
	public :
		virtual void getInfos()const = 0;
		virtual string printColorName() const = 0;
		virtual void open() const = 0;
		string getName(){return name;};
		
	
		
};

// ==========================================================================
// ==========================================================================

#endif // __OBJECT_HH__
