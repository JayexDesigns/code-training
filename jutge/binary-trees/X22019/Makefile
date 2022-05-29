OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o treeOfSums.o 
	g++ -o program.exe program.o treeOfSums.o 

program.o: program.cpp treeOfSums.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

treeOfSums.o: treeOfSums.cpp treeOfSums.hpp BinaryTree.hpp
	g++ -c treeOfSums.cpp $(OPCIONS)

clean:
	rm *.o *.exe
