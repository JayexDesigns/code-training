OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o reverseTree.o 
	g++ -o program.exe program.o reverseTree.o 

program.o: program.cpp reverseTree.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

sumOfTree.o: reverseTree.cpp reverse.hpp BinaryTree.hpp
	g++ -c reverseTree.cpp $(OPCIONS)

clean:
	rm *.o *.exe
