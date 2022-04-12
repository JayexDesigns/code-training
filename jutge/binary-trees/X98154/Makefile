OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o subArbre.o 
	g++ -o program.exe program.o subArbre.o 

program.o: program.cpp subArbre.hpp arbreBin.hpp
	g++ -c program.cpp $(OPCIONS)
	
subArbre.o: subArbre.cpp subArbre.hpp arbreBin.hpp
	g++ -c subArbre.cpp $(OPCIONS)

clean:
	rm *.o *.exe
