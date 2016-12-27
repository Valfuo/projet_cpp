#ifndef __FOLDER_HH__
#define __FOLDER_HH__
#include <iostream>
#include <list>
#include <algorithm> 
#include "Object.hh"


using namespace std;

class Folder{

public:
	string name; 
	Folder* prec;
	list<Folder> suiv;
	list<Object*> obj;
	
	Folder(const string name);
	Folder(const string name, Folder * prec);
	Folder(const Folder& rhs);
	void ls();
	Folder cd(string cible);
	void open(string cible);
	~Folder(){};
	Folder& operator=(const Folder& F);
	
	friend void swap(Folder& first, Folder& second){
        using std::swap;
        swap(first.name, second.name);
        swap(first.prec, second.prec);
        swap(first.suiv, second.suiv);
        swap(first.obj, second.obj);
   };
};



#endif //__FOLDER_HH__
