OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG  -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o LlistaIOParInt.o ParInt.o
	g++ -o program.exe program.o LlistaIOParInt.o ParInt.o

ParInt.o:  ParInt.cpp ParInt.hh 
	g++ -c ParInt.cpp $(OPCIONS)

LlistaIOParInt.o:  LlistaIOParInt.cpp LlistaIOParInt.hh ParInt.hh 
	g++ -c LlistaIOParInt.cpp $(OPCIONS)

program.o: program.cpp LlistaIOParInt.hh ParInt.hh 
	g++ -c program.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe

