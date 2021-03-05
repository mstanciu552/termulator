CC = g++
EXT = exe
OBJ = main.cpp rendering/Screen.cpp rendering/Screen.h rendering/Font.cpp rendering/Font.h

# 32bit version
SDL_LIB_RELATIVE = ./dependencies/SDL2/lib
SDL_INCLUDE_RELATIVE = ./dependencies/SDL2/include
SDL_TTF_LIB = ./dependencies/SDL2_ttf/lib
SDL_TTF_INCLUDE = ./dependencies/SDL2_ttf/include

OPTIONS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

execute: build run

build: $(OBJ)
	$(CC) -Wall $(OBJ) -I$(SDL_INCLUDE_RELATIVE) -L$(SDL_LIB_RELATIVE) -I$(SDL_TTF_INCLUDE) -L$(SDL_TTF_LIB) $(OPTIONS) -o build/main.$(EXT)
	
run: ./build/main.$(EXT)
	build/main.$(EXT)

clean: 
	rm build/*.$(EXT)

.PHONY: clean