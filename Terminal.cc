#include "Terminal.hh"

Terminal ::Terminal(string invite):invite(invite){}

void Terminal:: displayPath(){
	
		cout << "\e[1;32m" ;
		for(auto it = path.begin(); it != path.end(); it ++){
				cout << "/" << (*it);
		}
		cout << "$\e[0m ";
}

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

void Terminal:: tuto(){
		
		system("clear");
		cout << "Vous avez été contacté dans le but de recueillir des informations sur l'ordinateur de Tronald Dump." << endl;
		cout << "Ce dernier possède un dossier crypté et vérouillé que vous devez absolument ouvrir." << endl;
		cout << "Trouvez un moyen de déchiffrer ce mot de passe..." << endl;
		cout << endl;
		cout << "\e[1;32mVous disposez des instructions suivantes :" << endl;
		cout << "\t -- help ;" << endl;
		cout << "\t -- ls : permet de lister les fichiers et dossiers du répertoire courant ;" << endl;
		cout << "\t -- cd [dossier]: permet de naviguer dans l'arborescence ;" << endl;
		cout <<	"\t -- open [fichier] : ouvre [fichier];\e[0m" << endl;
		cout << endl;
		cout << endl;		
		cout << "Appuyez sur Entrée pour continuer..." << endl;
		getchar();
}

void Terminal::testLS(Folder currentFolder, string cible){
	if(cible.length() > 0)
				cout << "ls: cannot access " << cible << ": No such file or directory" << endl;
	else currentFolder.ls();
}

void Terminal::emptyCommand(string commande, string commande_tmp){
	if(commande_tmp.length() > 0) cout << commande_tmp << ": command not found" << endl;
	else  cout << commande << ": command not found" << endl;
}


void Terminal:: getCommand(Folder& currentFolder, string commande){

	string commande_tmp, cible; 
	
	if(commande.find(" ") < commande.length()){
		commande_tmp = commande.substr(0, commande.find(" "));
		cible  = commande.substr(commande.find(" ")+1);
	}


	if(commande == "help" || commande_tmp == "help") 	tuto();

	else if (commande == "ls" || commande_tmp == "ls")	testLS(currentFolder, cible);

	else if (commande == "cd" || commande_tmp == "cd"){
		updatePath(currentFolder, cible, path);			
		currentFolder = currentFolder.cd(cible);
	}
	
	else if (commande == "open" || commande_tmp == "open"){
		currentFolder.open(cible);
	}
	
	else if (commande.length() > 0)	emptyCommand(commande, commande_tmp);
}

