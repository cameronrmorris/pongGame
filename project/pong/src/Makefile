#
# Makefile for pong

SDLFLAGS = -lSDLmain -lSDL -lSDL_image -lSDL_ttf
WINDOWS = -I SDL/include -L SDL/lib -lmingw32
OTHER = -static-libgcc -static-libstdc++
EXECS = pong pong.exe
OBJS = Entity.o Ball.o button.o game.o menu.o Singleplayer.o util.o Timer.o Paddle.o HumanPaddle.o ComputerPaddle.o Text.o

all: linux

linux: CPP=g++
linux: CPPFLAGS = -O0 -g -Wall
linux: pong

windows: CPP=i586-mingw32msvc-g++
windows: CPPFLAGS = -O0 -g3 -Wall -I SDL/include
windows: pong.exe

mingw: CPP=g++
mingw: CPPFLAGS = -O0 -g3 -Wall -I SDL/include
mingw: pong.exe


install: all
	cp pong ../../../game/

pong.exe: $(OBJS) main.cpp
	$(CPP) $(OTHER) $(WINDOWS) $(CPPFLAGS) -o pong.exe main.cpp $(OBJS) $(SDLFLAGS)

pong: $(OBJS) main.cpp
	$(CPP) $(OTHER) $(CPPFLAGS) -o pong main.cpp $(OBJS) $(SDLFLAGS)	

Entity.o:	Entity.cpp Entity.h
	$(CPP) $(CPPFLAGS) -c -o Entity.o Entity.cpp

Ball.o:	Ball.cpp Ball.h
	$(CPP) $(CPPFLAGS) -c -o Ball.o Ball.cpp

button.o:	button.cpp button.h
	$(CPP) $(CPPFLAGS) -c -o button.o button.cpp	

game.o:	game.cpp game.h
	$(CPP) $(CPPFLAGS) -c -o game.o game.cpp

menu.o:	menu.cpp menu.h
	$(CPP) $(CPPFLAGS) -c -o menu.o menu.cpp

Singleplayer.o:	Singleplayer.cpp Singleplayer.h
	$(CPP) $(CPPFLAGS) -c -o Singleplayer.o Singleplayer.cpp

util.o:	util.cpp util.h
	$(CPP) $(CPPFLAGS) -c -o util.o util.cpp

Timer.o: Timer.cpp Timer.h
	$(CPP) $(CPPFLAGS) -c -o Timer.o Timer.cpp

Paddle.o: Paddle.h Paddle.cpp
	$(CPP) $(CPPFLAGS) -c -o Paddle.o Paddle.cpp

HumanPaddle.o: HumanPaddle.h HumanPaddle.cpp
	$(CPP) $(CPPFLAGS) -c -o HumanPaddle.o HumanPaddle.cpp

ComputerPaddle.o: ComputerPaddle.h ComputerPaddle.cpp
	$(CPP) $(CPPFLAGS) -c -o ComputerPaddle.o ComputerPaddle.cpp
	
Text.o: Text.h Text.cpp
	$(CPP) $(CPPFLAGS) -c -o Text.o Text.cpp	



## Test section

UNITS = testBall

tests: CPP=g++
tests: CPPFLAGS = -O0 -g3 -Wall
tests: testBall

testBall: Ball.o Entity.o testBall.cpp util.o
	$(CPP) $(CPPFLAGS) -o testBall testBall.cpp Ball.o Entity.o util.o $(SDLFLAGS)


clean:
	rm -rf $(OBJS) $(EXECS) $(UNITS)
