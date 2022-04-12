OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o searchInBST.o 
	g++ -o program.exe program.o searchInBST.o 

program.o: program.cpp searchInBST.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

posInTree.o: searchInBST.cpp searchInBST.hpp BinaryTree.hpp
	g++ -c searchInBST.cpp $(OPCIONS)

clean:
	rm *.o *.exe
    