CC = g++
EXT = exe

# 32bit version
SDL_LIB_RELATIVE = ./dependencies/SDL2/lib
SDL_INCLUDE_RELATIVE = ./dependencies/SDL2/include

OPTIONS = -lmingw32 -lSDL2main -lSDL2

execute: build run

build: main.cpp
	$(CC) -Wall main.cpp -I$(SDL_INCLUDE_RELATIVE) -L$(SDL_LIB_RELATIVE) $(OPTIONS) -o main.$(EXT)
	

run: main.$(EXT)
	./main.$(EXT)

clean: 
	rm *.$(EXT)