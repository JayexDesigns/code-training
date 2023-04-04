OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o arbre.o
	g++ -o program.exe main.o arbre.o
	rm *.o

main.o: main.cpp arbre.cpp
	g++ -c main.cpp $(OPCIONS)

arbre.o: arbre.cpp
	g++ -c arbre.cpp $(OPCIONS)

clean:
	rm *.o *.exe *.gch
