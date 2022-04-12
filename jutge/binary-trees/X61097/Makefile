OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o camiEnArbre.o 
	g++ -o program.exe program.o camiEnArbre.o 

program.o: program.cpp camiEnArbre.hpp arbreBin.hpp
	g++ -c program.cpp $(OPCIONS)
	
camiEnArbre.o: camiEnArbre.cpp camiEnArbre.hpp arbreBin.hpp
	g++ -c camiEnArbre.cpp $(OPCIONS)

clean:
	rm *.o *.exe
