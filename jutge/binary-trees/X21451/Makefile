OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o sumAtDepthEven.o 
	g++ -o program.exe program.o sumAtDepthEven.o 

program.o: program.cpp sumAtDepthEven.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

sumOfTree.o: sumAtDepthEven.cpp sumAtDepthEven.hpp BinaryTree.hpp
	g++ -c sumAtDepthEven.cpp $(OPCIONS)

clean:
	rm *.o *.exe
