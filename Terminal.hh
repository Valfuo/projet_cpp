#ifndef __TERMINAL_HH__
#define __TERMINAL_HH__
#include <string>
#include <iostream>
#include "Folder.hh"
#include <list>
#include <string>
#include <ncurses.h>

using namespace std;

// ==========================================================================
//								CLASSE TERMINAL								|
// ==========================================================================


class Terminal{

	private :
		string invite;
		void displayPath() const;
		void updatePath(Folder& currentFolder, string cible, list<string>& path);
		void help() const;
		void testLS(Folder currentFolder, string cible) const;
		void emptyCommand(string commande, string commande_tmp) const;
		void eraseSpace(string& chaine);
	public :
		list<string> path;
		Terminal(string invite, string racine);
		void publicPath() const {displayPath();};
		void getCommand(Folder& currentFolder, string commande);
		string printInvite() const{return invite;};
		~Terminal(){};

};

// ==========================================================================
// ==========================================================================


#endif // __TERMINAL__HH__
