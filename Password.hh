#ifndef __PASSWORD_HH__
#define __PASSWORD_HH__
#include "Application.hh"

using namespace std;

class Password : public Application{

	public :
		Password(string name, bool readEnable, string user): Application(name, readEnable, user){};
		void open() const;
};

#endif // __PASSWORD_H__
