OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o longestLeftmostPath.o 
	g++ -o program.exe program.o longestLeftmostPath.o 

program.o: program.cpp longestLeftmostPath.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

longestLeftmostPath.o: longestLeftmostPath.cpp longestLeftmostPath.hpp BinaryTree.hpp
	g++ -c longestLeftmostPath.cpp $(OPCIONS)

clean:
	rm *.o *.exe
