CXX=g++
CFLAGS= -Wall -std=c++0x -g
EXEC=main
GTK = `pkg-config gtkmm-3.0 --cflags --libs`
all: $(EXEC)

main: Folder.o Terminal.o main.o 
	$(CXX) -o $@ $^ $(GTK)	

Folder.o: Folder.cc Folder.hh
	$(CXX) -o $@ -c $< $(CFLAGS)
	
#Password.o: Password.cc Password.hh
#	$(CXX) -o $@ -c $< $(CFLAGS) $(GTK)

#Architecture.o: Architecture.cc Architecture.hh Folder.hh
#	$(CXX) -o $@ -c $< $(CFLAGS)

Terminal.o: Terminal.cc Terminal.hh
	$(CXX) -o $@ -c $< $(CFLAGS)
	
main.o: main.cc
	$(CXX) -o $@ -c $< $(CFLAGS) $(GTK)	

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)			
