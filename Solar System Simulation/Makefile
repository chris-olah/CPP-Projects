CC= g++ -std=c++17
CFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJECTS = main.o CelestialBody.o

all: 
	make NBody

NBody:$(OBJECTS)
		$(CC) -o NBody main.o CelestialBody.o $(CFLAGS)

main.o:	main.cpp
	$(CC) -c main.cpp

CelestialBody.o: CelestialBody.cpp CelestialBody.h
	$(CC) -c CelestialBody.cpp 

clean:
	rm $(OBJECTS) NBody