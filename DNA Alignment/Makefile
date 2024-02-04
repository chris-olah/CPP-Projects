CC= g++ -std=c++17
CFLAGS= -g -Wall -Werror -std=c++0x -pedantic
SFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
Boost= -lboost_unit_test_framework

all: EDistance

EDistance: main.o EDistance.o
          $(CC) main.o EDistance.o -o EDistance $(SFLAGS) 

main.o: main.cpp EDistance.hpp
        $(CC) -c main.cpp EDistance.hpp $(CFLAGS)
 
EDistance.o: EDistance.cpp EDistance.hpp
        $(CC) -c EDistance.cpp EDistance.hpp $(CFLAGS)

clean:
        rm *.o
        rm *.gch
        rm EDistance
