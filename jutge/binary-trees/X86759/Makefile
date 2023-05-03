OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o arbreBin_compleix_suma_fills.o arbreBin.o
	g++ -o program.exe program.o arbreBin_compleix_suma_fills.o arbreBin.o
	rm *.o

program.o: program.cpp arbreBin.hpp
	g++ -c program.cpp $(OPCIONS)

arbreBin_compleix_suma_fills.o: arbreBin_compleix_suma_fills.cpp arbreBin.hpp
	g++ -c arbreBin_compleix_suma_fills.cpp $(OPCIONS)
	
arbreBin.o: arbreBin.cpp arbreBin.hpp
	g++ -c arbreBin.cpp $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
