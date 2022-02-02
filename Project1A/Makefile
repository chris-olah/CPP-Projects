CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++14
Boost = -lboost_unit_test_framework

all:
	make ps1a

ps1a: test.o FibLFSR.o
	$(CC) $(CFLAGS) -o ps1a test.o FibLFSR.o $(Boost)

FibLFSR.o: FibLFSR.h FibLFSR.cpp main.cpp
	$(CC) $(CFLAGS) -c FibLFSR.cpp main.cpp

test.o:	test.cpp
	$(CC) $(CFLAGS) -c test.cpp 

clean:
	rm -f *.o *~ ps1a