#include "protectedPicture.hh"
#include <gtkmm.h>	
#include <unistd.h>

using namespace Gtk;

// ==========================================================================
//								CONSTRUCTEUR								|
// ==========================================================================


protectedPicture::protectedPicture(string name, string user, string path, string password, list<Object*>& obj): 
	Picture(name, user, path, obj){
		this->password = password;
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

void protectedPicture::getInfos()const{
		
		cout << "\e[1;37m" ;
		cout << "[<=================================>]" << endl;
		cout << "\nName\t\t: \e[33m" + name + "\e[1;37m"<< endl;
		cout << "Type\t\t: Picture" << endl;
		cout << "User\t\t: " + user << endl;
		cout << "Creation Date\t: \e[1;3";
		if(date == "not specified") cout << 1;
		else cout << 2;
		cout <<"m" + date + "\e[0m" << endl;
		cout << "\n\e[0m" + name + " is a protected file,\na password is required to open it" << endl;
		cout << "\e[1;37m\n[<=================================>]" << endl;
		cout << "\e[0m";	
}

// ==========================================================================
//																			|
//									OPEN									|
//																			|
// Entrées : rien															|
// Sortie : void  															|
// 			Demande la saisie d'un mot de passe avant d'ouvrir l'image		|
//			dans une fenêtre Gtk											|
//																			|
// ==========================================================================



void protectedPicture:: open()const{
	

// ==========================================================================
//						DÉCLARATION ET INITIALISATION						|
// ==========================================================================
		
	bool end = false;
	int cpt = 0;
	string tmp = password;
	string path_tmp = path;
	Window fenetre;
//	fenetre.set_keep_above(true);

	fenetre.set_title(name);
	fenetre.resize(450, 150);
	fenetre.set_icon_from_file("./src/Icon/security_icon.png");	
	fenetre.set_position(WIN_POS_CENTER);
	VBox VBox(true);
	
// ==========================================================================
//									CHAMP N°1								|
// ==========================================================================
	
	Label label1;
	label1.set_markup("Saisir le mot de passe pour le fichier chiffré<b>\n" + name + "</b>");
	label1.set_justify(JUSTIFY_CENTER);
	VBox.pack_start(label1, PACK_SHRINK);
	
// ==========================================================================
//									CHAMP N°2								|
// ==========================================================================
		
	HBox HBox(false, 5);
	Entry zone;
	zone.set_width_chars(30);
	zone.set_max_length(30);
	zone.set_alignment(ALIGN_CENTER);
	zone.set_visibility(false);
	CheckButton caseCocher("Afficher\nle mot de passe");	
	caseCocher.set_can_focus(false);

	caseCocher.signal_toggled().connect([&fenetre, &caseCocher, &zone](){
		if(caseCocher.get_active()) zone.set_visibility(true);
		else zone.set_visibility(false);
	});

	HBox.pack_start(caseCocher, PACK_SHRINK);
	HBox.pack_start(zone, PACK_SHRINK);
	VBox.pack_start(HBox, PACK_SHRINK);	
	
// ==========================================================================
//									CHAMP N°3								|
// ==========================================================================
	
	Label label2;
	label2.set_text(to_string(3-cpt) + " essai(s) restant(s)");
	label2.set_justify(JUSTIFY_CENTER);
	VBox.pack_start(label2, PACK_SHRINK);



// ==========================================================================
//								FONCTION DE RAPPEL:							|
//				Test la validité du mot de passe saisi par le joueur		|
//							à l'appui sur la touche entrée					|
// ==========================================================================
	
	string name_tmp = name;
	zone.signal_activate().connect([&fenetre, &cpt, &tmp, &zone, &label2, &path_tmp, &name_tmp, &end](){
		
		// Message d'erreur si aucun mot de passe n'a été saisi
		if((zone.get_text()).length() <= 0){
			MessageDialog dialogue(fenetre, "<big><b>Veuillez saisir votre mot de passe</b></big>", 
										true, MESSAGE_WARNING);
			dialogue.run();
		} 
	
		else {
			// Message d'erreur si le mot de passe est erroné
			if(zone.get_text() != tmp){
				MessageDialog dialogue(fenetre, "<big><b>Mot de passe erroné</b></big>", 
										true, MESSAGE_WARNING);
				dialogue.run();
				
				// Blocage si les 3 essais sont faux
				if(++cpt >= 3){
					MessageDialog dialogue(fenetre, "<big>Vous avez essayé 3 fois\nVeuillez réessayer plus tard</big>", 
										true, MESSAGE_WARNING);
					dialogue.run();
					zone.set_editable(false);
				} else label2.set_text(to_string(3-cpt) + " essais restants");
			} else{
				
				// Ouverture de l'image associée si le mot de passe est correct
				end = true;
				usleep(900000);
				if(fork() == 0){
					system("canberra-gtk-play -f ./src/WAV/screamer.wav");
					exit(0);
				} else {
					Window fenetre;
					fenetre.set_title(name_tmp);
					fenetre.set_keep_above(true);
					fenetre.set_position(WIN_POS_CENTER);
					fenetre.set_icon_from_file("./src/Icon/image_icon.png");
					Image image((char*)path_tmp.c_str());
					fenetre.add(image);
					image.show();
					Main::run(fenetre);
					zone.set_editable(false);
				}
			}
		}
	});
	
	fenetre.add(VBox);
	fenetre.show_all();
	Main::run(fenetre);
	
// ==========================================================================
//								MESSAGE DE FIN								|
// ==========================================================================
	
	
	if(end == true){
		cout << "OMG! It looks like you've found Tronald Dump's little dirty secrets!" << endl;
		cout << "But it seems that you got trolled by Trony" << endl;
		cout << "LMAO Dump dumped you" << endl;
		usleep(900000);
		cout << "\nOh! by the way, the CIA found you..." << endl;
		usleep(900000);
		cout << "You will go to jail and probably die in there" << endl;
		usleep(900000);
		cout << "(but please enter 'exit' to quit the hack portal)" << endl;
	}
	
}
// ==========================================================================
// ==========================================================================



