OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -std=c++11

program.exe: main.o cua.o
	g++ -o program.exe main.o cua.o
	rm *.o

main.o: main.cpp cua.cpp
	g++ -c main.cpp $(OPCIONS)

cua.o: cua.cpp
	g++ -c cua.cpp $(OPCIONS)

clean:
	rm *.exe
	rm *.o
	rm *.gch

test:
	./program.exe < tests/test0.inp | diff - tests/test0.cor -s
	./program.exe < tests/test1.inp | diff - tests/test1.cor -s
	./program.exe < tests/test2.inp | diff - tests/test2.cor -s
	./program.exe < tests/test3.inp | diff - tests/test3.cor -s
	./program.exe < tests/test4.inp | diff - tests/test4.cor -s
	./program.exe < tests/test5.inp | diff - tests/test5.cor -s
	./program.exe < tests/test6.inp | diff - tests/test6.cor -s
	./program.exe < tests/test7.inp | diff - tests/test7.cor -s
	./program.exe < tests/test8.inp | diff - tests/test8.cor -s
	./program.exe < tests/test9.inp | diff - tests/test9.cor -s
	./program.exe < tests/test10.inp | diff - tests/test10.cor -s