CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++14
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all:
	make PhotoMagic

PhotoMagic: PhotoMagic.o FibLFSR.o 
	$(CC) $(CFLAGS) PhotoMagic.o FibLFSR.o -o PhotoMagic $(LIBS)

PhotoMagic.o: PhotoMagic.cpp
	$(CC) $(CFLAGS) -c PhotoMagic.cpp

FibLFSR.o: FibLFSR.cpp FibLFSR.h 
	$(CC) $(CFLAGS) -c FibLFSR.cpp

clean:
	rm -f *.o *~ PhotoMagic