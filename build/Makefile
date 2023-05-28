all: compile run clean

compile:
	g++ -c ../src/entity.cpp -o entity.o
	g++ -c ../src/graphics.cpp -o graphics.o
	g++ -c ../src/input.cpp -o input.o
	g++ -c ../src/main.cpp -o main.o
	g++ -c ../game/src/game.cpp -o game.o
	g++ game.o input.o entity.o graphics.o main.o -o game -lSDL2 -lSDL2_image -lSDL2_gfx

run:
	./game

clean:
	rm *.o