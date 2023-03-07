OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o abin.o
	g++ -o program.exe main.o abin.o
	rm *.o

main.o: main.cpp abin.cpp
	g++ -c main.cpp $(OPCIONS)

abin.o: abin.cpp
	g++ -c abin.cpp $(OPCIONS)

clean:
	rm *.o *.exe *.gch
