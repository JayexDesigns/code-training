OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o subPila.o 
	g++ -o program.exe program.o subPila.o 

program.o: program.cpp utilitats.hpp subPila.hpp
	g++ -c program.cpp $(OPCIONS)
	
subPila.o: subPila.cpp subPila.hpp
	g++ -c subPila.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
