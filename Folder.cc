#include "Folder.hh"


Folder::Folder(const string name): name(name), prec(NULL){}

Folder::Folder(const string name, Folder * prec): name(name), prec(prec){}
 
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

Folder& Folder::operator=(const Folder& rhs){

	Folder temp(rhs);
	swap(*this, temp);
 
    return (*this);
}

ostream& operator<<(ostream& out, const Folder& rhs){
		return out << rhs.name;
}

ostream& operator<<(ostream& out, const list <Folder> & rhs){
	
	if(!(rhs.empty())){
		out << "\e[1;34m";
		for(auto it = rhs.begin(); it != rhs.end(); it++) 
			out << *it << "\t";
		out << endl;
	}
	out << "\e[0m";	
			
	return out;
}

ostream& operator<<(ostream& out, const list <Object*> & rhs){
	
	if(!(rhs.empty())){
		out << "\e[1;37m";	
		for(auto it = rhs.begin(); it != rhs.end(); it++) 
			out << (*it)->getName() << "\t";
		out << endl;
	}
	out << "\e[0m";	
			
	return out;
}

void Folder::ls(){
	cout << suiv;
	cout << obj;
} 

Folder Folder::cd(string cible){
	
	if(cible.length() == 0 || cible == "//") {
		while(prec != NULL)	*this = *prec;
		return (*this);	
	} else {
		
		if(cible == "..")
			if(prec != NULL) return (*prec);
			else return (*this);	
		else 
			for(auto it = suiv.begin(); it != suiv.end(); it++)
				if(it->name == cible)	return (*it);
		
		cout << "bash: cd: " << cible << ": No such file or directory" << endl;
		return (*this);
	}
}

void Folder::open(string cible){

	if(cible.length() > 1){
		if(!(obj.empty()))
			for(auto it = obj.begin(); it != obj.end(); it++) 
				if(cible == (*it)->getName()) {	(
					*it)->publicOpen();
					return;
				}
	}else{ 
		cout << "bash: open: No file nor application" << endl; 
		return;
	}
	cout << "bash: open: " << cible << ": No such file or application" << endl;			
}
