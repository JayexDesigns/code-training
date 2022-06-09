OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o numberSubtreesEvaluateToParam.o utils.o
	g++ -o program.exe program.o numberSubtreesEvaluateToParam.o utils.o

program.o: program.cpp numberSubtreesEvaluateToParam.hpp BinaryTree.hpp
	g++ -c program.cpp $(OPCIONS)

numberSubtreesEvaluateToParam.o: numberSubtreesEvaluateToParam.cpp numberSubtreesEvaluateToParam.hpp BinaryTree.hpp
	g++ -c numberSubtreesEvaluateToParam.cpp $(OPCIONS)

utils.o: utils.cpp utils.hpp
	g++ -c utils.cpp $(OPCIONS)

clean:
	rm *.o *.exe
