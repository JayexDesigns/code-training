OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o isomorfs.o 
	g++ -o program.exe program.o isomorfs.o 

program.o: program.cpp  isomorfs.hpp arbreBin.hpp
	g++ -c program.cpp $(OPCIONS)
	
isomorfs.o: isomorfs.cpp isomorfs.hpp arbreBin.hpp
	g++ -c isomorfs.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
