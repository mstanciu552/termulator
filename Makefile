CC = g++
EXT = exe
OBJ = main.cpp rendering/Screen.cpp rendering/Screen.h

# 32bit version
SDL_LIB_RELATIVE = ./dependencies/SDL2/lib
SDL_INCLUDE_RELATIVE = ./dependencies/SDL2/include

OPTIONS = -lmingw32 -lSDL2main -lSDL2

execute: build run

build: main.cpp
	$(CC) -Wall $(OBJ) -I$(SDL_INCLUDE_RELATIVE) -L$(SDL_LIB_RELATIVE) $(OPTIONS) -o build/main.$(EXT)
	
run: ./build/main.$(EXT)
	build/main.$(EXT)

clean: 
	rm build/*.$(EXT)

.PHONY: clean