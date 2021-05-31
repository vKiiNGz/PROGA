main: File1.cpp list.cpp person.cpp
	g++ File1.cpp list.cpp person.cpp -Wall -pedantic -o main
	./main
test: LR_7_Test.cpp File1.h File1.cpp list.cpp person.cpp 
	g++ LR_7_Test.cpp File1.h File1.cpp list.cpp person.cpp -Wall -pedantic -Dmain=_main -o test -fprofile-arcs -ftest-coverage
	./test
