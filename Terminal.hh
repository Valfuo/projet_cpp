#ifndef __TERMINAL_HH__
#define __TERMINAL_HH__
#include <string>
#include <iostream>
#include "Folder.hh"
#include <list>
#include <string>

using namespace std;

class Terminal{

	private :
		string invite;
		void displayPath();
		void updatePath(Folder& currentFolder, string cible, list<string>& path);
		void tuto();
		void testLS(Folder currentFolder, string cible);
		void emptyCommand(string commande, string commande_tmp);
	public :
		list<string> path;
		Terminal(string invite);
		void publicPath(){displayPath();};
		void getCommand(Folder& currentFolder, string commande);
		string printInvite(){return invite;};
		~Terminal(){};

};



#endif // __TERMINAL__HH__
