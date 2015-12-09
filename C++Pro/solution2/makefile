solution2:test.o Acc.o CAcc.o OAcc.o SAcc.o
	g++ -o solution2 test.o Acc.o CAcc.o OAcc.o SAcc.o
test.o:test.cpp Acc.h CAcc.h OAcc.h SAcc.h
	g++ -c test.cpp
Acc.o:Acc.cpp Acc.h
	g++ -c Acc.cpp
CAcc.o:CAcc.cpp Acc.h CAcc.h
	g++ -c CAcc.cpp
OAcc.o:OAcc.cpp Acc.h OAcc.h
	g++ -c OAcc.cpp
SAcc.o:SAcc.cpp Acc.h SAcc.h
	g++ -c SAcc.cpp
