OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o llista_compra_articles.o listIOint.o
	g++ -o program.exe program.o llista_compra_articles.o listIOint.o
	rm *.o

program.o: program.cpp llista_compra_articles.hpp listIOint.hpp
	g++ -c program.cpp $(OPCIONS)

llista_compra_articles.o: llista_compra_articles.cpp llista_compra_articles.hpp
	g++ -c llista_compra_articles.cpp $(OPCIONS)

listIOint.o: listIOint.cpp listIOint.hpp
	g++ -c listIOint.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
