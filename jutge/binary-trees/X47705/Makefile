OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o sizeOfTree.o 
	g++ -o program.exe program.o sizeOfTree.o 

program.o: program.cpp sizeOfTree.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

sumOfTree.o: sizeOfTree.cpp sizeOfTree.hpp BinaryTree.hpp
	g++ -c sizeOfTree.cpp $(OPCIONS)

clean:
	rm *.o *.exe
