#include "Text.hh"

// ==========================================================================
//								CONSTRUCTEURS								|
// ==========================================================================

Text::Text(string name, string user, string path, list<Object*>& obj): 
	Object(name, user, obj){
		this->path = path;
}								

Text::Text(string name, string user, string path, string date, list<Object*>& obj): 
	Object(name, user, date, obj){
		this->path = path;
}	

// ==========================================================================
//																			|
//								GET_INFOS									|
//																			|
// Entrées : rien															|
// Sortie : void  															|
// 			Liste les propriété de l'objet									|	
//																			|
// ==========================================================================


void Text::getInfos()const{
		
		cout << "\e[1;37m" ;
		cout << "[<=================================>]" << endl;
		cout << "\nName\t\t: \e[33m" + name + "\e[1;37m"<< endl;
		cout << "Type\t\t: Text" << endl;
		cout << "User\t\t: " + user << endl;
		cout << "Creation Date\t: \e[1;3";
		if(date == "not specified") cout << 1;
		else cout << 2;
		cout <<"m" + date + "\e[0m" << endl;
		cout << "\n[<=================================>]" << endl;
		cout << "\e[0m";	
}

// ==========================================================================
//																			|
//									OPEN									|
//																			|
// Entrées : rien															|
// Sortie : void  															|
// 			Affichage terminal du texte du fichier 							|
//																			|
// ==========================================================================

					

void Text:: open()const{
	
	cout << "[<====== " + name + " ======>]\n" << endl;
	system(("cat " + path).c_str());
	cout << endl;
	
}

// ==========================================================================
// ==========================================================================





