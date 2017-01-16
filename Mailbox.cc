#include "Mailbox.hh"
#include <gtkmm.h>	

using namespace Gtk;

// ==========================================================================
//																			|
//									OPEN									|
//																			|
// Entrées : rien															|
// Sortie : void  															|
// 			Ouverture d'une fenêtre graphique faisant office de boîte		|
// 			mail															|
//																			|
// ==========================================================================

void Mailbox:: open()const{

// ==========================================================================
//						DÉCLARATION ET INITIALISATION						|
// ==========================================================================

	Window fenetre;
	fenetre.set_keep_above(true);
    fenetre.set_title("M@ilBox");
    fenetre.set_icon_from_file("./src/mails/icon.jpeg");
    fenetre.set_position(WIN_POS_CENTER);
	fenetre.resize(length, width);	
    
// ==========================================================================
//							DÉCLARATION DES WIDGETS							|
// ==========================================================================
	
	ListViewText mailRecus(2,false,SELECTION_SINGLE); 
	Image imageNext(Stock::GO_FORWARD, ICON_SIZE_BUTTON); 
	Image imagePrevious(Stock::GO_BACK, ICON_SIZE_BUTTON);

    HBox boiteH;
    Notebook barreOnglets;

    Image mail_1("./src/mails/icon.jpeg");
    
    Label texte3;
    ScrolledWindow barresDeDefilementMail;
    ScrolledWindow barresDeDefilementListe;
     
// ==========================================================================
//								ZONE GAUCHE									|
//								Liste mails									|
// ==========================================================================

   barresDeDefilementListe.set_policy(POLICY_AUTOMATIC, POLICY_AUTOMATIC);
    
// ==========================================================================
//								BARRE D'ONGLETS								|
// ==========================================================================

    barreOnglets.set_can_focus(true);
    texte3.set_text("Il n'y a aucun mail dans la corbeille.");

    // Contenu onglets
    mailRecus.set_activate_on_single_click(true);
	mailRecus.set_column_title(0,"Expéditeur");
    mailRecus.set_column_title(1,"Objet");
    
// ==========================================================================
//							INITIALISATION MAILS							|
// ==========================================================================

	mailRecus.append("1register@american-airlines");
	mailRecus.append("2Michael.pencenot@republican.us");
    mailRecus.append("3communication@sun700.org");
    mailRecus.append("5bank.software@it.development.us");
    mailRecus.append("4lesbontuto@leroy-merlin.fr");
    mailRecus.append("6mathieu.mcgregor@gmail.com");
    mailRecus.append("7mark.greig@photo-labo.us");
    mailRecus.append("8Thomas.butch@gmail.com");
    mailRecus.append("9register@american-airlines.com");

    // Mise a jour des Objet
    mailRecus.set_text(0,1,"Confirmation de reservation - Paris");
    mailRecus.set_text(1,1,"Re.Discours d'investiture");
    mailRecus.set_text(2,1,"Votre abonnement arrive à expiration");
    mailRecus.set_text(3,1, "[PROMO] Special Noel");
    mailRecus.set_text(4,1,"[TUTO] Construire un mur");
    mailRecus.set_text(5,1, "FWD. Newsletter - Scandale Hilary Clinton");
    mailRecus.set_text(6,1, "[Photo-labo] Album photo mariage");
    mailRecus.set_text(7,1, "Re.Invitation anniversaire de mariage");
	mailRecus.set_text(8,1, "Confirmation de reservation - Italie");
    
// ==========================================================================
//								AFFICHAGE MAILS								|
// ==========================================================================

    barresDeDefilementMail.set_policy(POLICY_AUTOMATIC, POLICY_AUTOMATIC);
    barresDeDefilementMail.set_size_request(900,400);
	//mail_1.set("./src/mails/icon.jpeg");
	

// ==========================================================================
//								FONCTION DE RAPPEL							|
//								Actualisation mail							|
// ==========================================================================


    mailRecus.signal_cursor_changed().connect([&fenetre, &mailRecus, &mail_1](){
		vector<int> selection = mailRecus.get_selected(); 
		string imagePath = "./src/mails/" + mailRecus.get_text(selection[0],1) + ".JPG" ; 
		mail_1.set(imagePath); 	
		mail_1.show();
	});
	
// ==========================================================================
//							ARCHITECTURE CONTENEURS							|
// ==========================================================================

	barresDeDefilementListe.add(mailRecus);
    barreOnglets.append_page(barresDeDefilementListe,"Boite de reception");
  	barreOnglets.append_page(texte3, "Corbeille");

	boiteH.pack_start(barreOnglets);
   
    barresDeDefilementMail.add(mail_1);		
    boiteH.pack_start(barresDeDefilementMail); 	
   
    fenetre.add(boiteH); 	

    fenetre.show_all();
	Main::run(fenetre);
}
// ==========================================================================
// ==========================================================================

