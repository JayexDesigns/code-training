OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o remove01.o 
	g++ -o program.exe program.o remove01.o 

program.o: program.cpp remove01.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

sumOfTree.o: remove01.cpp remove01.hpp BinaryTree.hpp
	g++ -c remove01.cpp $(OPCIONS)

clean:
	rm *.o *.exe
