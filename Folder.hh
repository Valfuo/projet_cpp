#ifndef __FOLDER_HH__
#define __FOLDER_HH__
#include <iostream>
#include <list>
#include <algorithm> 
#include "Object.hh"


using namespace std;


// ==========================================================================
//								CLASSE FOLDER								|
// ==========================================================================

class Folder{

	public:
		string name; 
		Folder* prec;
		list<Folder> suiv;
		list<Object*> obj;
		
		Folder(const string name);
		Folder(const string name, Folder * prec);
		Folder(const Folder& rhs);
		
		void ls() const;
		Folder cd(string cible);
		void open(string cible) const;
		void info(string cible) const;
		~Folder(){};
		Folder& operator=(const Folder& F);
	private:
		void swap(Folder& first, Folder& second);
};

// ==========================================================================
// ==========================================================================

#endif //__FOLDER_HH__
