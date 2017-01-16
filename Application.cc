#include "Application.hh"


// ==========================================================================
//								CONSTRUCTEURS								|
// ==========================================================================


Application::Application(string name, string user, int length, int width, list<Object*>& obj): 
				Object(name, user, obj){
					this->width = width;
					this->length = length;	
}

Application::Application(string name, string user, int length, int width, string date, list<Object*>& obj): 
				Object(name, user, date, obj){
					this->width = width;
					this->length = length;	
		
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


void Application:: getInfos() const {
			cout << "\e[1;37m" ;
			cout << "[<=========================================>]" << endl;
			cout << "\nName\t\t: \e[33m" + name + "\e[1;37m"<< endl;
			cout << "Type\t\t: Executable" << endl;
			cout << "User\t\t: " + user << endl;
			cout << "Creation Date\t: \e[1;3";
			if(date == "not specified") cout << 1;
			else cout << 2;
			cout <<"m" + date + "\e[0m" << endl;
			cout << "\e[0m";	
}

// ==========================================================================
// ==========================================================================

