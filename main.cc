#include "main.hh"


int main(int argc, char * argv[]) {
	
	intro();

	// intialisation GTK:
	Main app(true);
	
	// CONSTRUCTION DE L'ARBORESCENCE
	
// ==========================================================================
//									RACINE									|
// ==========================================================================

	Folder Bureau(Folder("Desktop"));
	Folder Images("Pictures", &Bureau);
	Folder Documents("Documents", &Bureau);
	Folder Telechargement("Downloads", &Bureau);
	Mailbox mail("MailBox.exe", "Tronald", 800, 550, "AUG 21 2010", Bureau.obj);
	Picture Poutine("Wallpaper.png", "V'la du mir Pudding", 
					"./src/Tronald/Poutine.png", "JAN 15 2014", Bureau.obj);
	
// ==========================================================================
//									DOWNLOADS								|
// ==========================================================================
	
	Password generator("PasswordGenerator.exe", "Tronald", 450, 450, "JUL 17 2013", Telechargement.obj);

// ==========================================================================
//									VACANCES								|
// ==========================================================================
	
	Folder Vacances("Holidays", &Images);
	Picture Angleterre("BigBen.png", "Tronald", "./src/Destinations/Angleterre.png", "JAN 15 2014", Vacances.obj);
	Picture Argentine("Patagonia.png", "Tronald", "./src/Destinations/Argentine.png", "APR 21 2014", Vacances.obj);
	Picture Australie("Opera.png", "Tronald", "./src/Destinations/Australie.png", Vacances.obj);
	Picture Bresil("Corcovado.png", "Tronald", "./src/Destinations/Bresil.png", "JAN 01 2016", Vacances.obj);
	Picture Chine("GreatWall.png", "Tronald", "./src/Destinations/Chine.png","FEB 18 2013", Vacances.obj);
	Picture Ecosse("Kilt.png", "Tronald", "./src/Destinations/Ecosse.png",Vacances.obj);
	Picture Egypte("Louxor.png", "Tronald", "./src/Destinations/Egypte.png", "SEP 01 2015",  Vacances.obj);
	Picture France("Invalides.png", "Tronald", "./src/Destinations/France.png", Vacances.obj);
	Picture Inde("TajMahal.png", "Tronald", "./src/Destinations/Inde.png", "MAR 02 2015", Vacances.obj);
	Picture Grece("Méditerranée.png", "Tronald", "./src/Destinations/Grece.png",Vacances.obj);
	Picture PaysBas("Amsterdam.png", "Tronald", "./src/Destinations/Pays-Bas.png", Vacances.obj);
	Picture Perou("MachuPicchu.png", "Tronald", "./src/Destinations/Perou.png", "NOV 28 2014",Vacances.obj);
	(Images.suiv).push_back(Vacances);
	
// ==========================================================================
//									TRONALD									|
// ==========================================================================

	Folder Tronald("Tronald", &Images);
	Picture Barack("Barack.png", "Tronald", "./src/Tronald/Barack.png", "NOV 10 2016", Tronald.obj);
	Picture Disney("Disney.png", "Tronald", "./src/Tronald/Disney.png", "DEC 10 2016", Tronald.obj);
	Picture Spooky("Spooky.png", "Tronald", "./src/Tronald/Dog.png", Tronald.obj);
	Picture NBA("NBA.png", "Tronald", "./src/Tronald/NBA.png", Tronald.obj);
	Picture Hangover("Hangover.png", "Tronald", "./src/Tronald/Hangover.png", "OCT 18 2012", Tronald.obj);
	Picture Investiture("Investiture.png", "Tronald", "./src/Tronald/Investiture.png", "NOV 17 2016", Images.obj);
	(Images.suiv).push_back(Tronald);
	protectedPicture Private("Private.png", "Tronald", "./src/WAV/screamer.png", 
								"GreAUTronaldia_Gce221950", Images.obj);


// ==========================================================================
//									WIFE									|
// ==========================================================================

	Folder Wife("Babe", &Documents);
	Picture Famille("Family01.png", "Unknown", "./src/Wife/Famille.png", "NOV 10 2016", Wife.obj);
	Picture Famille2("Family02.png", "Unknown", "./src/Wife/Famille2.png", Wife.obj);
	Picture Campaign("Campaign.png", "Unknown", "./src/Wife/Affiche.png", Wife.obj);
	Picture Interview("Interview.png", "Unknown", "./src/Wife/Interview.png", Wife.obj);
	Folder Mariage("Wedding", &Wife);
	Picture Wedding1("Wedding01.png", "Unknown", "./src/Wife/Mariage.png", Mariage.obj);
	Picture Wedding2("Wedding02.png", "Tronaldia", "./src/Wife/Mariage2.png", Mariage.obj);
	(Wife.suiv).push_back(Mariage);
	(Documents.suiv).push_back(Wife);
	
// ==========================================================================
//									ZOO										|
// ==========================================================================

	Folder Zoo("Zoo", &Images);
	Picture Flamingo("Flamingo.png", "Tronald", "./src/zoo/Flamingo.png", "AUG 25 2015", Zoo.obj);
	Picture Lemur("Lemur.png", "Tronald", "./src/zoo/Lemur.png", "AUG 25 2015", Zoo.obj);
	Picture Elephant("Elephant.png", "Tronald", "./src/zoo/Elephant.png", "AUG 25 2015", Zoo.obj);
	Picture Giraffe("Giraffe.png", "Tronald", "./src/zoo/Girafe.png", "AUG 25 2015", Zoo.obj);
	Picture Turtle("Turtle.png", "Tronald", "./src/zoo/Tortue.png", "AUG 25 2015", Zoo.obj);
	Picture Monkey("Monkey.png", "Tronald", "./src/zoo/Monkey.png", "AUG 25 2015", Zoo.obj);
	(Images.suiv).push_back(Zoo);

// ==========================================================================
//								DOCUMENTS									|
// ==========================================================================

	Text Joke("Joke.txt", "Tronald", "./src/Textes/joke.txt", Documents.obj);
	Text Draft("Draft.txt", "Tronald", "./src/Textes/brouillon.txt", "JAN 15 2017", Documents.obj);
	Text Mesures("Mesures.txt", "Tronald", "./src/Textes/mesures.txt", Documents.obj);
	Text Victory("Victory.txt", "Tronald", "./src/Textes/victoire.txt", "NOV 17 2016", Documents.obj);

// ==========================================================================
//							IMPLÉMENTATION DES DOSSIERS 					|
//								FINIS A LA RACINE							|
// ==========================================================================
	
	(Bureau.suiv).push_back(Documents);
	(Bureau.suiv).push_back(Images);
	(Bureau.suiv).push_back(Telechargement);	
	
// ==========================================================================	
// ==========================================================================	

	// Construction du répertoire courant
	Folder currentFolder("current");
	currentFolder = Bureau;

	// Construction d'un objet Terminal
	Terminal T("\e[1;32m[TERMINAL]:~\e[0m",currentFolder.name);
	string commande;

	while(1){
			
			// Affichage invite de commande
			cout << T.printInvite();
			T.publicPath();
			getline(cin, commande); 
			
			// Traitement des éventuels espaces non désirés
			while (commande.find(" ") == 0)  commande.erase(commande.find(" "), 1);
			
			// Sortie de boucle si commande = exit
			if(commande == "exit" || 
				commande.substr(0, commande.find(" ")) == "exit") 
				break;
		
			// Traitement de la commande sinon
			T.getCommand(currentFolder, commande);
	}
	
	return 0;
}

// ==========================================================================	
// ==========================================================================	
