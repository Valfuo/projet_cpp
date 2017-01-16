#include "Object.hh"

// ==========================================================================
//								CONSTRUCTEURS								|
// ==========================================================================

Object::Object(string name, string user, list<Object*>& obj): 	
					name(name), user(user),	date("not specified"){
												obj.push_back(this);	
											}
		
		
Object::Object(string name, string user, string date, list<Object*>& obj): 
					name(name), user(user),date(date){
								obj.push_back(this);	
					}

// ==========================================================================
// ==========================================================================
