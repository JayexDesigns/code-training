OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o llista_inverteix.o llista.o
	g++ -o program.exe program.o llista_inverteix.o llista.o
	rm *.o

program.o: program.cpp llista.hpp
	g++ -c program.cpp $(OPCIONS)

llista_inverteix.o: llista_inverteix.cpp llista.hpp
	g++ -c llista_inverteix.cpp $(OPCIONS)
	
llista.o: llista.cpp llista.hpp
	g++ -c llista.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
