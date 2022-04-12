OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o posInTree.o 
	g++ -o program.exe program.o posInTree.o 

program.o: program.cpp posInTree.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

posInTree.o: posInTree.cpp posInTree.hpp BinaryTree.hpp
	g++ -c posInTree.cpp $(OPCIONS)

clean:
	rm *.o *.exe
    