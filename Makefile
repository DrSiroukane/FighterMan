CPP = g++ --std=c++11 -Wall
SOURCE = main.cpp Map.cpp Helper.cpp Coordinates.cpp Actor.cpp Player.cpp Arm.cpp Monster.cpp
NCURSES = -lpthread -lncurses

all : main
	
main : main.o
	$(CPP) -o main $(SOURCE)

clean :
	rm *.o