CXX=g++
CFLAGS= -Wall -std=c++0x -g
EXEC=main
GTK = `pkg-config gtkmm-3.0 --cflags --libs`
all: $(EXEC)

main: Folder.o Object.o Application.o Password.o Mailbox.o Text.o Picture.o protectedPicture.o Terminal.o main.o 
	$(CXX) -o $@ $^ $(GTK) -lncurses

Folder.o: Folder.cc Folder.hh
	$(CXX) -o $@ -c $< $(CFLAGS)

Object.o: Object.cc Object.hh	
	$(CXX) -o $@ -c $< $(CFLAGS)
	
Application.o: Application.cc Application.hh
	$(CXX) -o $@ -c $< $(CFLAGS)
	
Password.o: Password.cc Password.hh
	$(CXX) -o $@ -c $< $(CFLAGS) $(GTK)	
	
Mailbox.o: Mailbox.cc Mailbox.hh
	$(CXX) -o $@ -c $< $(CFLAGS) $(GTK)	

Text.o: Text.cc Text.hh
	$(CXX) -o $@ -c $< $(CFLAGS)

Picture.o: Picture.cc Picture.hh
	$(CXX) -o $@ -c $< $(CFLAGS) $(GTK)	
	
protectedPicture.o: protectedPicture.cc protectedPicture.hh
	$(CXX) -o $@ -c $< $(CFLAGS) $(GTK)	

Terminal.o: Terminal.cc Terminal.hh																														
	$(CXX) -o $@ -c $< $(CFLAGS) -lncurses 
	
main.o: main.cc main.hh
	$(CXX) -o $@ -c $< $(CFLAGS) $(GTK) -lncurses

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)			
