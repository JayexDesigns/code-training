OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o esborraSenars.o 
	g++ -o program.exe program.o esborraSenars.o 

program.o: program.cpp utilitats.hpp esborraSenars.hpp
	g++ -c program.cpp $(OPCIONS)
	
esborraSenars.o: esborraSenars.cpp esborraSenars.hpp
	g++ -c esborraSenars.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
