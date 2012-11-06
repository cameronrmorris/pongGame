#
# Makefile for pong
# so jenkins can build this LINUX ONLY

SDLFLAGS = -lSDLmain -lSDL -lSDL_image
WINDOWS = -I SDL/include -L SDL/lib -lmingw32
OTHER = -static-libgcc -static-libstdc++
EXECS = pong pong.exe
OBJS = Entity.o Ball.o button.o game.o menu.o Singleplayer.o util.o

linux: CPP=g++
linux: CPPFLAGS = -O0 -g3 -Wall
linux: pong

windows: CPP=i586-mingw32msvc-g++
windows: CPPFLAGS = -O0 -g3 -Wall -I SDL/include
windows: pong.exe

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
	
clean:
	rm -rf $(OBJS) $(EXECS)