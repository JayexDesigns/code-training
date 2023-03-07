OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o deque.o
	g++ -o program.exe main.o deque.o
	rm *.o

main.o: main.cpp deque.cpp
	g++ -c main.cpp $(OPCIONS)

deque.o: deque.cpp
	g++ -c deque.cpp $(OPCIONS)

clean:
	rm *.o *.exe *.gch

test:
	./program.exe < tests/test0.inp | diff - tests/test0.cor -s