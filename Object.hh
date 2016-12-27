#ifndef __OBJECT_HH__
#define __OBJECT_HH__
#include <iostream>

using namespace std;


class Object{
	
	protected :
		string name;
		bool readEnable;
		string user;

		virtual void open() const = 0;
//		virtual void getInfos()const = 0;
		Object(string name, bool readEnable, string user): 	name(name), 
															readEnable(readEnable), 
															user(user){};
															
	public :
		string getName(){return name;};
		void publicOpen(){open();};
		~Object(){};
};

#endif // __OBJECT_HH__
