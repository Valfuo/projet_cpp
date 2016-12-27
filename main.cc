#include <iostream>
#include <ctime>
#include <fstream>
#include <list>
#include "Folder.hh"
#include "Architecture.hh"
#include "Terminal.hh"
#include "Object.hh"
#include "Application.hh"
#include "Password.hh"
#include <gtkmm.h>	


using namespace Gtk;
using namespace std;


int main(int argc, char * argv[]) {
	

	Main app(true);
	Window fenetre;
	fenetre.set_title("Password Generator v1.2.0");
	fenetre.resize(450, 450);	
	fenetre.set_position(Gtk::WIN_POS_CENTER);
	VBox VBox(false, 30);
	
	Label titre("\nPASSWORD GENERATOR\n\n");
	VBox.pack_start(titre, PACK_SHRINK);
	
		
	Label txt1("Le nom de votre conjoint(e) : ");	
	Entry zone1;
	zone1.set_max_length(20);
	zone1.set_alignment(ALIGN_CENTER);
	HBox HBox(true); 
	HBox.pack_start(txt1);
	HBox.pack_start(zone1);
	VBox.pack_start(HBox, PACK_SHRINK);	
	
	
	Label txt2("Votre date d'anniversaire de mariage : ");	
	Button bouton("Generate Password");	
	VBox.pack_start(txt2, PACK_SHRINK);



	
	
	fenetre.add(VBox);
    fenetre.show_all();
	Main::run(fenetre);
	
	
	

// ***********************************************************************************

	string commande;

	Folder Bureau(Folder("Desktop"));
	Folder Images("Pictures", &Bureau);
	Folder Documents("Documents", &Bureau);
	Folder Images2("Wedding", &Images);
	Folder Telechargement("Downloads", &Bureau);
	
//	Password generator("Password", true, "Tronald");
//	(Telechargement.obj).push_back(&generator);	

	
	(Images.suiv).push_back(Images2);
	(Bureau.suiv).push_back(Documents);
	(Bureau.suiv).push_back(Images);
	(Bureau.suiv).push_back(Telechargement);
	
	Folder currentFolder("current");
	currentFolder = Bureau;

	Terminal T("\e[1;32m[TERMINAL]:~\e[0m");
	(T.path).push_back(currentFolder.name);

	
	while(1){
	
			cout << T.printInvite();
			T.publicPath();
			getline(cin, commande); 
			if(commande == "exit") break;
		
			T.getCommand(currentFolder, commande);
	}
	
	return 0;
}
