all: entity.o graphics.o input.o main.o threads.o audio.o standard.o game.o normal
shared: entity.o graphics.o input.o main.o threads.o audio.o standard.o library
test: entity.o graphics.o input.o main.o threads.o audio.o standard.o game run clean

entity.o:
	g++ -c ../src/entity.cpp -o entity.o
graphics.o:
	g++ -c ../src/graphics.cpp -o graphics.o
input.o:
	g++ -c ../src/input.cpp -o input.o
main.o:
	g++ -c ../src/main.cpp -o main.o
threads.o:
	g++ -c ../src/threads.cpp -o threads.o
audio.o:
	g++ -c ../src/audio.cpp -o audio.o
standard.o:
	g++ -c ../src/standard.cpp -o standard.o
game.o:
	g++ -c ../game/src/game.cpp -o game.o

normal:
	g++ game.o threads.o standard.o audio.o input.o entity.o graphics.o main.o -o game -lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_mixer

library:
	g++ threads.o standard.o audio.o input.o entity.o graphics.o main.o -o game -lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_mixer -shared -fPIC

run:
	./game

clean:
	rm *.o
	rm game