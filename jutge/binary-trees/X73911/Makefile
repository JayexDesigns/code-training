OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o maxOfTree.o 
	g++ -o program.exe program.o maxOfTree.o 

program.o: program.cpp maxOfTree.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

sumOfTree.o: maxOfTree.cpp maxOfTree.hpp BinaryTree.hpp
	g++ -c maxOfTree.cpp $(OPCIONS)

clean:
	rm *.o *.exe
