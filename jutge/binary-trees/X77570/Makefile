OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o maximumTree.o 
	g++ -o program.exe program.o maximumTree.o 

program.o: program.cpp maximumTree.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

maximumTree.o: maximumTree.cpp maximumTree.hpp BinaryTree.hpp
	g++ -c maximumTree.cpp $(OPCIONS)

clean:
	rm *.o *.exe
