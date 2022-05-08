
BIN=./spidlfil
DOXY=Doxyfile
CC=g++
CFLAG= -g -Wall -pedantic --std=c++11


all: compile doc

#compile:  ./src/main.cpp main_menu.o main_menu.o game_window.o read_file.o
#	$(CC) $(CFLAG) -o spidlfil ./src/main.cpp main_menu.o game_window.o read_file.o -lncurses

compile:
	$(CC) $(CFLAG) ./src/*.cpp -o spidlfil -lncurses
#$(CC) $(CFLAG) ./src/*.cpp -o spidlfil ./src/menu_player.hpp -lncurses


main_menu.o: src/main_menu.cpp src/main_menu.hpp src/menu_player.hpp \
 src/level_menu.hpp src/game_window.hpp src/read_file.hpp \
 src/base_block.hpp src/bomberman.hpp src/moving_block.hpp
	$(CC) $(CFLAG) -c ./src/main_menu.cpp -o main_menu.o

game_window.o:  ./src/game_window.cpp read_file.o bomberman.o 
	$(CC) $(CFLAG) -c ./src/game_window.cpp -o game_window.o

read_file.o: ./src/read_file.cpp  bomberman.o
	$(CC) $(CFLAG) -c ./src/read_file.cpp -o read_file.o

base_block.o: ./src/base_block.cpp 
	$(CC) $(CFLAG) -c ./src/base_block.cpp -o base_block.o 

moving_block.o: ./src/moving_block.cpp base_block.o
	$(CC) $(CFLAG) -c ./src/moving_block.cpp  -o moving_block.o

bomberman.o: ./src/bomberman.cpp moving_block.o
	$(CC) $(CFLAG)  -c ./src/bomberman.cpp -o bomberman.o

run: compile
	./spidlfil

doc: src/* Doxyfile
	mv Doxyfile src
	cd src && doxygen
	mv -f src/Doxyfile .
	rm -rf doc
	mv -f src/html doc

clean:
	rm -f spidlfil
	rm -rf latex
	rm -rf doc
	rm -rf *.o
	rm -rf src/*.gch

	