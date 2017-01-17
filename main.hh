#ifndef __MAIN_HH__
#define __MAIN_HH__
#include <iostream>
#include <unistd.h>
#include <string>
#include <gtkmm.h>	
#include <glibmm/ustring.h>	
#include <iostream>
#include <ctime>
#include <fstream>
#include <list>
#include "Folder.hh"
#include "Terminal.hh"
#include "Object.hh"
#include "Application.hh"
#include "Password.hh"
#include "Picture.hh"
#include "protectedPicture.hh"
#include "Text.hh"
#include "Mailbox.hh"
#include <gtkmm.h>	
#include <ncurses.h>

using namespace std;
using namespace Gtk;



// ==========================================================================
//																			|
//								PRINTMANYCHAR								|
//																			|
// Entrées: entier nb														|
//			string car														|
// Sortie : void															|
//			Affichage nb fois la chaîne de caractères car					|
//																			|
// ==========================================================================

void printManyChar(int nb, string car){
		for(int i = 0; i < nb; i++){
			cout << car;
		}
}

/* Toutes les fonctions déclarées ci-dessous des fonctions d'affichage.
 * Celles-ci sont appelées par la fonction intro(), elle-même appelée
 * dès le lancement du jeu.
 */


// ==========================================================================
//								PRINTCOMPLETE								|
// ==========================================================================

void printComplete(void){
		cout << "\e[0m[\e[0;32mCOMPLETE\e[0m]" << endl;
}

// ==========================================================================
//									INIT									|
// ==========================================================================

void init(void){
		cout << "\e[0m";

		cout << "> " << endl;
		usleep(600000);
		cout << "> " << endl;
		usleep(600000);
		cout << "> \e[1;7;31;47m WARNING: \e[0m\n>";
		usleep(900000);
		cout << " You're about to get into the Hack Portal.\n> ";
		usleep(1900000);
		cout << "Note that there'll be no possible backspace." << endl;;
		usleep(1900000);
		cout << ">\n " << endl;
		usleep(600000);
		cout << "Press Enter to launch the configuration";
		getchar();
		usleep(800000);
		system("canberra-gtk-play -f ./src/WAV/modem.wav");
		cout << endl;
}



// ==========================================================================
//									ASCII1									|
// ==========================================================================


void ascii1(void){
		cout << "\e[0;32m" ;
		cout<< "          n                                              n                   " << endl; usleep(30000);
		cout<< "        dB                 dP                   9b        9b                 " << endl; usleep(30000); 
		cout<< "  4    qXb                dX                     Xb       dXp              t " << endl; usleep(30000);
		cout<< " dX     9Xb      dXb                                     dXb      dXP      Xb" << endl; usleep(30000);
		cout<< " 9XXb          dXXXXb dXXXXbo                   odXXXXb dXXXXb           dXXP" << endl; usleep(30000);
		cout<< " 9XXXXXXXXXXXXXXXXXXXVXXXXXXXX0o             o0XXXXXXXXVXXXXXXXXXXXXXXXXXXXP " << endl; usleep(30000);
		cout<< "   9XXXXXXXXXXXXXXXXXXXXX       0008b   d8000       XXXXXXXXXXXXXXXXXXXXXP   " << endl; usleep(30000);
		cout<< "    9XXXXXXXXXXXP   9XX            98v8P            XXP   9XXXXXXXXXXP       " << endl; usleep(30000);
		cout<< "                     9X            dbdb             XP                       " << endl; usleep(30000);
		cout<< "                         Xb    dbo dPv9 odb    dX                            " << endl; usleep(30000);
		cout<< "                      dXXXXXXXXXXXb     dXXXXXXXXXXXb                        " << endl; usleep(30000);
		cout<< "                    dXXXXXXXXXXXP         9XXXXXXXXXXXb                      " << endl; usleep(30000);
		cout<< "                   dXXXXXXXXXXXXb   dIb   dXXXXXXXXXXXXb                     " << endl; usleep(30000);
		cout<< "                   9XXb     XXXXXb dXIXb dXXXXX     dXXP                     " << endl; usleep(30000);
		cout<< "                             9XXXXXX   XXXXXXP                               " << endl; usleep(30000);
		cout<< "                             XXXXX X v X XXXXX                               " << endl; usleep(30000);
		cout<< "                              XPcX  b d  XcXX                                " << endl; usleep(30000);
		cout<< "                             X  9         P  X                               " << endl; usleep(30000);
		cout<< "                              b             d                                " << endl; usleep(30000);
		cout << "\e[0m" << endl;
		usleep(1000000);
}

// ==========================================================================
//									ASCII2									|
// ==========================================================================

void ascii2(void){
	system( "echo '\e[1;32m'" );
	system(" figlet '       HACK PORTAL'");
	system( "echo '\e[0m'" );
	
	usleep(900000);
	cout << "Press Enter to go further...";
	getchar();
}


// ==========================================================================
//									STEP1									|
// ==========================================================================

void step1(void){

		cout << endl;
		cout << "Enumerating Target";
		printManyChar(40, ".");
		usleep(900000);
		printComplete();
		usleep(700000);
		cout << " [+] Host: gogole.com\n";
		usleep(400000);
		cout << " [+] IPv4: 74.125.229.160" << endl;
		usleep(400000);
}

// ==========================================================================
//									STEP2									|
// ==========================================================================


void step2(void){
		cout << "Opening SOCK5 ports on infected hosts";
		printManyChar(21, ".");
		printComplete();
		usleep(400000);
		cout << " [+] SSL entry point on 127.0.0.1:1337" << endl;
}

// ==========================================================================
//									STEP3									|
// ==========================================================================


void step3(void){
		cout << "Chaining proxies";
		printManyChar(42, ".");
		printComplete();
		usleep(400000);
		cout << " [+] 7/7 proxies chained {BEL>AUS>JAP>CHI>NOR>CAN>USA}" << endl;
}

// ==========================================================================
//									STEP4									|
// ==========================================================================


void step4(void){
		cout << "Launching port knocking sequence";
		printManyChar(26, ".");
		printComplete();
		usleep(400000);
		cout << " [+] Knock on TCP<143,993,587,456,25,587,993,80>" << endl;
}

// ==========================================================================
//									STEP5									|
// ==========================================================================


void step5(void){
		cout << "Sending PCAP datagrams for fragmentation overlap";
		printManyChar(10, ".");
		printComplete();
		usleep(400000);
		cout << " [+] Stack override ***** w00t w00t g0t r00t!\n";
		cout << "\nCongrats! you're now invisible!\n[<";
		printManyChar(67, "=");
		cout << ">]" << endl;
}

// ==========================================================================
//									STEP6									|
// ==========================================================================

void step6(void){
		
		usleep(900000);
		cout << "\n> cmd: \e[1;7;31;47mssh Dark_ARmy0108@Tronald_Dump.com \e[0m\n"<< endl;
		usleep(3000000);
		
		cout << "Sending PCAP datagrams for fragmentation overlap";
		printManyChar(10, ".");
		printComplete();
		cout << " [+] Host: gogole.com\n [+] IPv4: 74.125.289.245" << endl;
		usleep(900000);
		cout << " [+] SSL entry point on 127.0.0.1:1547" << endl;
		usleep(900000);
		cout << " [+] 3/3 proxy chained {PENTAGONE>WHITE_HOUSE>TRONALD}" << endl;
		usleep(900000);
		cout << " [+] Knock on TCP<145,116,78>" << endl;
		usleep(900000);
		cout << " [+] Stack override ***** w00t w00t g0t r00t!\n\n[<";
		printManyChar(67, "=");
		cout << ">]\n" << endl;
		
		usleep(400000);
		cout << "\e[1;31mYou're now connected to Tronald Dump's laptop\e[0m" << endl;
		cout << "Enter 'help' command to get information\n" << endl;
		usleep(900000);
}

// ==========================================================================
//									INTRO									|
// ==========================================================================

void intro(void){
		
		init();
		ascii1();
		ascii2();
				
		step1();
		step2();
		step3();
		step4();
		step5();
		step6();
}

#endif // __MAIN_HH__
