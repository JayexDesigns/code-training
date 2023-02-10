OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o llista.o solution.o
	g++ -o program.exe main.o llista.o solution.o
	rm *.o

solution.exe: main.o llista.o solution.o
	g++ -o solution.exe main.o llista.o solution.o
	rm *.o

solution.o: solution.cpp llista.hpp
	g++ -c solution.cpp $(OPCIONS)

main.o: main.cpp llista.hpp
	g++ -c main.cpp $(OPCIONS)

llista.o: llista.cpp llista.hpp
	g++ -c llista.cpp $(OPCIONS)

clean:
	rm *.o *.exe *.gch

test:
	./program.exe < tests/test0.inp | diff - tests/test0.cor -s
	./program.exe < tests/test1.inp | diff - tests/test1.cor -s
	./program.exe < tests/test2.inp | diff - tests/test2.cor -s
	./program.exe < tests/test3.inp | diff - tests/test3.cor -s
	./program.exe < tests/test4.inp | diff - tests/test4.cor -s
	./program.exe < tests/test5.inp | diff - tests/test5.cor -s