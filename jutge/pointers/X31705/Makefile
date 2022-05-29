OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o 
	g++ -o program.exe program.o

program.o: program.cpp stack.hpp
	g++ -c program.cpp $(OPCIONS)

clean:
	rm *.o *.exe
