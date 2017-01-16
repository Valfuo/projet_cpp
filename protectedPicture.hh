#ifndef __PROTECTEDPICTURE_HH__
#define __PROTECTEDPICTURE_HH__
#include <string>
#include "Picture.hh"

using namespace std;

// ==========================================================================
//						CLASSE PROTECTED_PICTURE							|
//						   hérite de Picture								|
// ==========================================================================


class protectedPicture : public Picture{
	
	private : 
		string password;
		
	public :
		protectedPicture(string name, string user, string path, string password, list<Object*>& obj);
		void open() const;
		void getInfos() const;	
		string printColorName() const { return ("\e[1;35m" + name + "\e[0m*" );}
	
};
// ==========================================================================
// ==========================================================================
#endif
