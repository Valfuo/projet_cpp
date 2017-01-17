#include "Terminal.hh"


// ==========================================================================
//								CONSTRUCTEUR								|
// ==========================================================================
Terminal ::Terminal(string invite, string racine):invite(invite){
		path.push_back(racine);
}


// ==========================================================================
//																			|
//								DISPLAY_PATH								|
//																			|
// Entrées : rien															|
// Sortie : void  															|
// 			Affichage de chemin vers le répertoire courant					|
//																			|
// ==========================================================================
void Terminal:: displayPath() const{
	
		cout << "\e[1;32m" ;
		for(auto it = path.begin(); it != path.end(); it ++){
				cout << "/" << (*it);
		}
		cout << "$\e[0m ";
}


// ==========================================================================
//																			|
//								UPDATE_PATH									|
//																			|
// Entrées: string cible													|
//			référence vers répertoire courant (Folder)						|
//			référence vers la liste 'path' qui contient le nom de tous les	|
//			dossiers permettant d'atteindre le répertoire courant			|
// Sortie : void															|
//			Mise à jour de la liste	à l'appel d'une commande cd				|
//																			|
// ==========================================================================
void Terminal::updatePath(Folder& currentFolder, string cible, list<string>& path){
	
	if(cible.length() == 0 || cible == "//")
			while(path.size() > 1) path.pop_back();
	else if(cible == ".."){
			if(path.size()>1)	path.pop_back();
	} else{				
		for(auto it = (currentFolder.suiv).begin(); it != (currentFolder.suiv).end(); it++)
			if(it->name == cible)  path.push_back(cible);
	}
}
// ==========================================================================
//																			|
//									HELP									|
//																			|
// Entrées : rien															|
// Sortie : Affichage d'une page (à la façon d'une page man) expliquant		|
//			le scénario et l'utilité des différentes commandes disponibles	|
//																			|
// ==========================================================================
void Terminal:: help() const{
			
		initscr();
		setlocale(LC_ALL, "");
		raw();		
		noecho();
		printw("HELP(1)\t\t\t\t\tUser Commands");
		
		attron(A_BOLD);	
		printw("\n\nUSER\n\t");
		attroff(A_BOLD);
		printw("Dark_ARmy0108\n\n");
	
		attron(A_BOLD);	
		printw("SYNOPSIS\n");
		attroff(A_BOLD);
		// Les accents ne sont pas pris en charge par la bibliothèque ncurses.h qui gère ce genre d'affichage
		// La fonction setlocale(LC_ALL, "") trouvée sur internet ne permet pas non plus de résoudre ce problème
		// Le texte affiché sera alors en anglais (donc sans accent ni caractère spéciaux)
	
		printw( "\tYou are currently connected to Tronald Dump's personnal laptop\n" );
		printw( "\tHe's known for keeping a secret file protected by a mysterious password\n" );
		printw( "\tYou are in charge of browsing in his computer in order to find out this password\n" );
		printw( "\tA few commands are available to navigate through is file system\n\n");
	
		attron(A_BOLD);	
		printw("COMMANDS\n\n");

// ================================= HELP ===================================

		printw( "\t -- help " );
		attroff(A_BOLD);
		printw("List the available commands\n\n");
		
// ================================== LS ====================================
		attron(A_BOLD);	
		printw( "\t -- ls " );
		attroff(A_BOLD);
		printw("List available FILES and DIRECTORIES (the current directory by default)\n\n");
 
// ================================== CD ====================================
		attron(A_BOLD);	
		printw( "\t -- cd " );
		attroff(A_BOLD);
		printw("Change the working directory by target Folder\n"); attron(A_BOLD);	
		printw( "\t\tcd " ); attroff(A_BOLD); printw( "or " ); attron(A_BOLD); printw( "cd // " );
		attroff(A_BOLD); printw("allow to go back to root (Desktop)\n");
		attron(A_BOLD);	
		printw( "\t\tcd .. " ); attroff(A_BOLD); 
		printw(" allow to go back to the previous directory\n");
		printw("\t\tIt is not possible to go through several directories all at once (even using '/')\n\n");
// ================================= OPEN ===================================
		attron(A_BOLD);	
		printw( "\t -- open " );
		attroff(A_BOLD);
		printw("Open the target file or application\n");
		printw("\t\tNote that you don't have to specify the format of the file when typing it\n\n");
// ================================= INFO ===================================
		printw( "\t -- info " );
		attroff(A_BOLD);
		printw("Print information about the target file or application\n");
		printw("\t\tNote that"); attron(A_BOLD); printw( " info * " ); attroff(A_BOLD);
		printw("will print information about all the available files and applications\n\n");
		
// ================================= EXIT ===================================
		attron(A_BOLD);	
		printw( "\t -- exit " );
		attroff(A_BOLD);
		printw("Close the programm and disconnect form Tronald's laptop\n");
// ==========================================================================
		printw( "\n\n\nPress q to quit..." );
		attroff(A_BOLD);
		while(getch()!='q');
		clear();
		refresh();
		endwin();	
}


// ==========================================================================
//																			|
//								TEST_LS										|
//																			|
// Entrées: répertoire courant												|
//			string cible													|
// Sortie : void															|
//			Test de la validité et l'existence de cible	et appelle la		|
//			méthode LS du répertoire courant								|
//																			|
// ==========================================================================
void Terminal::testLS(Folder currentFolder, string cible) const{
	if(cible.length() > 0)
				cout << "ls: cannot access " << cible << ": No such file or directory" << endl;
	else currentFolder.ls();
}

// ==========================================================================
//																			|
//								EMPTY_COMMAND								|
//																			|
// Entrées: string commande, commande_tmp									|
// Sortie : void															|
//			Affichage d'un message d'erreur									|
//																			|
// ==========================================================================
void Terminal::emptyCommand(string commande, string commande_tmp) const{
	if(commande_tmp.length() > 0) cout << commande_tmp << ": command not found" << endl;
	else  cout << commande << ": command not found" << endl;
}

// ==========================================================================
//																			|
//								GET_COMMAND									|
//																			|
// Entrées: référence vers répertoire courant								|
//			string commande													|
// Sortie : void															|
//			Test de la validité de la commande rentrée et traitement des 	|
//			opérations spécifiques à chaque commande définie				|
//																			|
// ==========================================================================
void Terminal:: getCommand(Folder& currentFolder, string commande){

	string commande_tmp, cible; 

	// Traitement des éventuels espaces entrées par l'utilisateur
	// et séparation de la commande et de la cible
	if(commande.find(" ") < commande.length() && 
			commande.find(" ") > 0){
		commande_tmp = commande.substr(0, commande.find(" "));
		cible  = commande.substr(commande.find(" ")+1);
	}
	eraseSpace(cible);
	eraseSpace(commande_tmp);

	// commande HELP : affichage des scénario et des commandes disponibles
	if(commande == "help" || commande_tmp == "help") 	help();

	// commande LS : liste les sous-dossiers et fichiers du répertoire courant
	else if (commande == "ls" || commande_tmp == "ls")	testLS(currentFolder, cible);

	// commande CD + CIBLE : mise à jour du répertoire courant et du chemin
	else if (commande == "cd" || commande_tmp == "cd"){
		updatePath(currentFolder, cible, path);			
		currentFolder = currentFolder.cd(cible);
	}
	
	// commande OPEN + CIBLE : ouverture de l'Object CIBLE
	else if (commande == "open" || commande_tmp == "open"){
		currentFolder.open(cible);
	}
	
	// commande INFO + CIBLE : liste les propriétés de CIBLE
	else if (commande == "info" || commande_tmp == "info"){
		currentFolder.info(cible);
	}
	
	// autre commande : message d'erreur
	else if (commande.length() > 0) emptyCommand(commande, commande_tmp);
}

// ==========================================================================
//																			|
//								ERASE_SPACE									|
//																			|
// Entrées: référence vers string cible										|
// Sortie : void															|
//			Supprime les esapces dans cible									|
//																			|
// ==========================================================================
void Terminal:: eraseSpace(string& chaine){
	int i = 0;
	while ((i = chaine.find(" ")) >= 0) 
			chaine.erase(i, 1);
}

// ==========================================================================
// ==========================================================================
