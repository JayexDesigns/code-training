OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o pilaFibonacci.o 
	g++ -o program.exe program.o pilaFibonacci.o $(OPCIONS)

program.o: program.cpp utilitats.hpp pilaFibonacci.hpp
	g++ -c program.cpp $(OPCIONS)
	
pilaFibonacci.o: pilaFibonacci.cpp pilaFibonacci.hpp
	g++ -c pilaFibonacci.cpp $(OPCIONS)

clean:
	rm *.o *.exe
