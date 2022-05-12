CC= g++ -std=c++17
CFLAGS= -g -Wall -Werror -std=c++0x -pedantic
SFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
Boost= -lboost_unit_test_framework
 
all: KSGuitarSim
 
KSGuitarSim: KSGuitarSim.o StringSound.o CircularBuffer.o
	$(CC) KSGuitarSim.o StringSound.o CircularBuffer.o -o KSGuitarSim $(SFLAGS)
 
KSGuitarSim.o: KSGuitarSim.cpp StringSound.hpp
	$(CC) -c KSGuitarSim.cpp StringSound.hpp $(CFLAGS)
 
StringSound.o: StringSound.cpp StringSound.hpp
	$(CC) -c StringSound.cpp StringSound.hpp $(CFLAGS)
 
CircularBuffer.o: CircularBuffer.cpp CircularBuffer.hpp
	$(CC) -c CircularBuffer.cpp CircularBuffer.hpp $(CFLAGS)
 
clean:
	rm *.o
	rm *.gch
	rm KSGuitarSim
