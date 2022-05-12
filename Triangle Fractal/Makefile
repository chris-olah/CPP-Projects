CC = g++

all: TFractal

TFractal: Triangle.o TFractal.o
	g++ Triangle.o TFractal.o -o TFractal -lsfml-graphics -lsfml-window -lsfml-system

Triangle.o: Triangle.cpp Triangle.h
	g++ -c Triangle.cpp -Wall -Werror -pedantic

TFractal.o: TFractal.cpp
	g++ -c TFractal.cpp -Wall -Werror -pedantic
clean:
	rm *.o TFractal