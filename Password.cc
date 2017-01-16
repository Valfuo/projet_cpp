#include "Password.hh"
#include <gtkmm.h>	

using namespace Gtk;

// ==========================================================================
//																			|
//									OPEN									|
//																			|
// Entrées : rien															|
// Sortie : void  															|
// 			Ouverture d'une fenêtre graphique faisant office de générateur	|
// 			de mots de passe												|
//																			|
// ==========================================================================

void Password:: open()const{

// ==========================================================================
//						DÉCLARATION ET INITIALISATION						|
// ==========================================================================
	
	Window fenetre;
	fenetre.set_keep_above(true);
	fenetre.set_title("Password Generator v1.2.0");
	fenetre.resize(length, width);	
	fenetre.set_position(WIN_POS_CENTER);
	fenetre.set_icon_from_file("./src/Icon/password_icon.png");
	VBox VBox(false, 30);
	
	Image image("./src/Icon/password.png");
	VBox.pack_start(image);
	image.show();

// ==========================================================================
//									CHAMP N°1								|
// ==========================================================================
	
	
	Label txt1("\tLe nom de votre conjoint(e) : ");	
	Entry zone1;
	zone1.set_max_length(20);
	zone1.set_alignment(ALIGN_CENTER);
	HBox HBox1(true); 
	HBox1.pack_start(txt1);
	HBox1.pack_start(zone1, PACK_SHRINK);
	VBox.pack_start(HBox1, PACK_SHRINK);	
	
// ==========================================================================
//									CHAMP N°2								|
// ==========================================================================
	
	Label txt2("\tVotre date d'anniversaire de mariage : ");	
	ComboBoxText listeMois;
		listeMois.append("JAN");
		listeMois.append("FEB");
		listeMois.append("MAR");
		listeMois.append("APR");
		listeMois.append("MAY");
		listeMois.append("JUN");
		listeMois.append("JUL");
		listeMois.append("AUG");
		listeMois.append("SEP");
		listeMois.append("OCT");
		listeMois.append("NOV");
		listeMois.append("DEC");
		listeMois.set_active_text("JAN");
	ComboBoxText listeJours;
		for(int i = 1; i < 32; i++)
				listeJours.append(to_string(i));
		listeJours.set_active_text("1");
	

	HBox HBox2(false, 5);
	HBox2.pack_start(txt2, PACK_SHRINK);
	HBox2.pack_start(listeMois,PACK_SHRINK);
	HBox2.pack_start(listeJours,PACK_SHRINK);
	VBox.pack_start(HBox2, PACK_SHRINK);
	
// ==========================================================================
//									CHAMP N°3								|
// ==========================================================================
	
	Label txt3("\t\t\tVotre année de naissance : ");	
	Glib::RefPtr<Adjustment> ajustement = Adjustment::create(1980, 1900, 2015, 1);
	SpinButton boutonCompteur(ajustement);
	boutonCompteur.set_numeric();

	HBox HBox3(false, 15);
	HBox3.pack_start(txt3, PACK_SHRINK);
	HBox3.pack_start(boutonCompteur,PACK_SHRINK);
	VBox.pack_start(HBox3, PACK_SHRINK);
	
// ==========================================================================
//									CHAMP N°4								|
// ==========================================================================
	
	Label txt4("\tVotre dernière destination de vacances : "); 
	ComboBoxText listePays;
		listePays.append("Angleterre");
		listePays.append("Argentine");
		listePays.append("Australie");
		listePays.append("Bresil");
		listePays.append("Chine");
		listePays.append("Écosse");
		listePays.append("Égypte");
		listePays.append("France");
		listePays.append("Grece");
		listePays.append("Inde");
		listePays.append("Pays-Bas");
		listePays.append("Perou");
		listePays.set_active_text("Angleterre");

	
	HBox HBox4(false, 5);
	HBox4.pack_start(txt4, PACK_SHRINK);
	HBox4.pack_start(listePays,PACK_SHRINK);
	VBox.pack_start(HBox4, PACK_SHRINK);

// ==========================================================================
//									CHAMP N°5								|
// ==========================================================================
	
	HButtonBox boiteBoutonsH;
	boiteBoutonsH.set_layout(BUTTONBOX_CENTER);
	Button bouton("Generate Password");	

// ==========================================================================
//								FONCTION DE RAPPEL:							|
//				Genère un mot de passe lors d'un appui sur le bouton		|
// ==========================================================================
	

	bouton.signal_clicked().connect([&fenetre, &zone1, 
									&listeMois, &listeJours, 
									&boutonCompteur, &listePays](){
		
		if((zone1.get_text()).length() <= 0){
			MessageDialog dialogue(fenetre, "<big><b>ERREUR:\n</b>Veuillez renseigner le nom de votre conjoint(e)</big>", 
										true, MESSAGE_WARNING);
			dialogue.run();
		} else {
			string mois = listeMois.get_active_text();
			string jour = listeJours.get_active_text();
			int annee = boutonCompteur.get_value_as_int();
			string pays = listePays.get_active_text();
			string password = 	pays.substr(0, 3) + mois.substr(0, 2) + zone1.get_text() 
								+ "_" + mois.substr(2, mois.length() - 1)
								+ pays.substr(3, pays.length() - 1) + jour
								+ to_string(annee);
			MessageDialog dialogue(fenetre, "Votre mot de passe est :\n<big><b>" + password + "</b></big>", true);
			dialogue.run();
		}			
	});
		
// ==========================================================================
//						IMPLÉMENTATION DE LA FENÊTRE						|
// ==========================================================================

	boiteBoutonsH.pack_start(bouton);	
	VBox.pack_start(boiteBoutonsH);
	fenetre.add(VBox);
	fenetre.show_all();
	Main::run(fenetre);

}
// ==========================================================================
// ==========================================================================



