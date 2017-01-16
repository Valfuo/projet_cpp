#include "Picture.hh"
#include <gtkmm.h>

using namespace Gtk;

// ==========================================================================
//								CONSTRUCTEURS								|
// ==========================================================================


Picture::Picture(string name, string user, string path, list<Object*>& obj): 
	Object(name, user, obj){
		this->path = path;
}								

Picture::Picture(string name, string user, string path, string date, list<Object*>& obj): 
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


void Picture::getInfos()const{
		
		cout << "\e[1;37m" ;
		cout << "[<=================================>]" << endl;
		cout << "\nName\t\t: \e[33m" + name + "\e[1;37m"<< endl;
		cout << "Type\t\t: Picture" << endl;
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
// 			Affichage de l'image dans une fenêtre Gtk						|
//																			|
// ==========================================================================

								
void Picture:: open()const{
		Window fenetre;
		fenetre.set_title(name);
		fenetre.set_icon_from_file("./src/Icon/image_icon.png");
		fenetre.set_keep_above(true);
		fenetre.set_position(WIN_POS_CENTER);
		Image image((char*)path.c_str());
		fenetre.add(image);
		image.show();
		Main::run(fenetre);
}

// ==========================================================================
// ==========================================================================

