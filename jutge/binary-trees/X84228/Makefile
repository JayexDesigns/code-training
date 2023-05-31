OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o sumOfTree.o 
	g++ -o program.exe program.o sumOfTree.o 

program.o: program.cpp sumOfTree.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

sumOfTree.o: sumOfTree.cpp sumOfTree.hpp BinaryTree.hpp
	g++ -c sumOfTree.cpp $(OPCIONS)

clean:
	rm *.o *.exe
