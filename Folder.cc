#include "Folder.hh"

// ==========================================================================
//								CONSTRUCTEURS								|
// ==========================================================================
Folder::Folder(const string name): name(name), prec(NULL){}

Folder::Folder(const string name, Folder * prec): name(name), prec(prec){}
 
// Constructeur par copie
Folder::Folder(const Folder& rhs): name(rhs.name), prec(rhs.prec){
	
	suiv.clear();
	for(auto it = (rhs.suiv).begin(); it != (rhs.suiv).end(); it++){
				suiv.push_back(*it);
	}
	
	obj.clear();
	for(auto it = (rhs.obj).begin(); it != (rhs.obj).end(); it++){
				obj.push_back(*it);
	}
}

// ==========================================================================
//					SURCHAGES DES OPÉRATEURS ('=' ET '<<')					|
// ==========================================================================

// L'opérateur '=' permet l'affectation d'un objet de type "Folder" 
//	à un autre
Folder& Folder::operator=(const Folder& rhs){

	Folder temp(rhs);
	swap(*this, temp);
 
    return (*this);
}

// Opérateur '<<':
// Entrées : flux de sortie, Folder rhs
// Sortie : Affichage coloré du nom de l'objet
ostream& operator<<(ostream& out, const Folder& rhs){
		return out << "\e[1;34m" + rhs.name + "\e[0m/";
}

// Opérateur '<<':
// Entrées : flux de sortie, liste de Folder rhs
// Sortie : Affichage de tous les noms des objets de la liste 
ostream& operator<<(ostream& out, const list <Folder> & rhs){
	
	if(!(rhs.empty())){
		int cpt = 0;
		
		for(auto it = rhs.begin(); it != rhs.end(); it++){
			out << *it << " \t";
			cpt++;
			if(cpt == 5){
				out << endl;
				cpt = 0;
			}
		}
	}
	out << "\e[0m";	
			
	return out;
}

// Opérateur '<<':
// Entrées : flux de sortie, liste de pointeurs sur Object rhs
// Sortie : Affichage en couleur de tous les noms des objets de la 
//			liste
ostream& operator<<(ostream& out, const list <Object*> & rhs){
	
	if(!(rhs.empty())){
		int cpt = 0;
		for(auto it = rhs.begin(); it != rhs.end(); it++) {
			out << (*it)->printColorName() ;
			
			// Gestion de l'affichage (alignement des noms)
			out << " \t";
			cpt ++;
			if(cpt == 5){
					out << endl;
					cpt = 0;
			}
		}
	}
	out << endl;
	out << "\e[0m";	
			
	return out;
}


// ==========================================================================
//																			|
//									LS										|	
//																			|
// Entrées : rien															|
// Sortie : void  															|
//			Affichage en couleur de tous les objets (Object et Folder) 		|
//			issus du répertoire courant. On utilise les surchages des		|
//			opérateurs précedemment définies								|
//																			|
// ==========================================================================

void Folder::ls() const{
	cout << suiv;
	cout << obj;
} 

// ==========================================================================
//																			|
//									CD										|
//																			|
// Entrées : string cible													|	
// Sortie : void  															|		
// 			Affectation d'un Folder fils nommé cible à l'object courant 	|
//			On utilise la surchage de l'opérateur '='						|
//			+ Gestion des erreurs de saisie par l'utilisateur				|
//			Permet ainsi d'actualiser le répertoire courant et de se		|
//			déplacer dans l'arborescence									|
//																			|
// ==========================================================================

Folder Folder::cd(string cible) {
	
	// Retour à la racine :
	if(cible.length() == 0 || cible == "//") {
		while(prec != NULL)	*this = *prec;
		return (*this);	
	} else {
		
	// Retour vers le dossier précédent
		if(cible == "..")
			if(prec != NULL) return (*prec);
			else return (*this);	
				
	// Déplacement vers le sous-dossier cible
		else
			for(auto it = suiv.begin(); it != suiv.end(); it++)
				if(it->name == cible)	return (*it);
		
	// Erreur sinon
		cout << "bash: cd: " << cible << ": No such file or directory" << endl;
		return (*this);
	}
}

// ==========================================================================
//																			|
//									OPEN									|
//																			|
// Entrées : string cible													|
// Sortie : void  															|
//			Ouverture de l'object cible appelée								|
//			On utilise la fonction open() redéfinie dans chacuns des 		|
//			objets hérités de la classe Object								|
//			+ Gestion des erreurs de saisie par l'utilisateur 				|	
//																			|
// ==========================================================================

void Folder::open(string cible) const{
	
	// Test la validité de la cible et appel de sa fonction open()
	if(cible.length() > 1){
		if(!(obj.empty()))
				for(auto it = obj.begin(); it != obj.end(); it++) {
					string tmp = (*it)->getName().substr(0, (*it)->getName().find("."));
					if(	(cible == (*it)->getName()) || 
						(cible == tmp)) {	
						(*it)->open();										
						return;
					}
				}
	}
	// Message d'erreur
	else{ 
		cout << "bash: open: No file nor application" << endl; 
		return;
	}
	cout << "bash: open: " << cible << ": No such file or application" << endl;			
}

// ==========================================================================
//																			|
//									INFO									|
//																			|
// Entrées : string cible													|
// Sortie : void  															|
// 			Affichage des infos de l'object cible appelée					|
//			On utilise a fonction info() redéfinie dans chacuns des 		|
//			objects non abstraits hérités de la classe Object				|
//			+ Gestion des erreurs de saisie par l'utilisateur 				|	
//																			|
// ==========================================================================

void Folder::info(string cible) const{

	// Test la validité de la cible
	if(cible.length() > 0){
		if(!(obj.empty()))
	
			// Liste les infos de tous les objets si cible = *
			if( cible == "*" ){
				for(auto it = obj.begin(); it != obj.end(); it++) (*it)->getInfos();										
					return;
				}
			
			// Liste les infos de la cible spécifique sinon
			for(auto it = obj.begin(); it != obj.end(); it++) {
				string tmp = (*it)->getName().substr(0, (*it)->getName().find("."));
				if(	(cible == (*it)->getName()) || 
					(cible == tmp)) {	
					(*it)->getInfos();										
					return;
				}
			}
	}
	// Message d'erreur sinon
	else{ 
		cout << "bash: info: No file nor application" << endl; 
		return;
	}
	cout << "bash: info: " << cible << ": No such file or application" << endl;			
}

// ==========================================================================
//																			|
//									SWAP									|
//																			|
// Entrées : 2 références vers des Folders first et second					|
// Sortie : void  															|
// 			Echange les attributs de first et second						|	
//			Utilisée pour la surcharge de l'opérateur = 					|
//																			|
// ==========================================================================


void Folder::swap(Folder& first, Folder& second){
	using std::swap;
	swap(first.name, second.name);
	swap(first.prec, second.prec);
	swap(first.suiv, second.suiv);
	swap(first.obj, second.obj);
 }
// ==========================================================================
// ==========================================================================
