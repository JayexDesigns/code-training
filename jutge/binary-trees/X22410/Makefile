OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o treeOfHeights.o 
	g++ -o program.exe program.o treeOfHeights.o 

program.o: program.cpp treeOfHeights.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

treeOfHeights.o: treeOfHeights.cpp treeOfHeights.hpp BinaryTree.hpp
	g++ -c treeOfHeights.cpp $(OPCIONS)

clean:
	rm *.o *.exe
