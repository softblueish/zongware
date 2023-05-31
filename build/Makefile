all: headers entity.o graphics.o input.o main.o threads.o audio.o standard.o libzongware.so install clean
compile: entity.o graphics.o input.o main.o threads.o audio.o standard.o libzongware.so clean

headers:
	mkdir -p /usr/include/zongware
	sudo cp ../headers/*.hpp /usr/include/zongware/

entity.o:
	g++ -c ../src/entity.cpp -o entity.o -fPIC
graphics.o:
	g++ -c ../src/graphics.cpp -o graphics.o -fPIC
input.o:
	g++ -c ../src/input.cpp -o input.o -fPIC
main.o:
	g++ -c ../src/main.cpp -o main.o -fPIC
threads.o:
	g++ -c ../src/threads.cpp -o threads.o -fPIC
audio.o:
	g++ -c ../src/audio.cpp -o audio.o -fPIC
standard.o:
	g++ -c ../src/standard.cpp -o standard.o -fPIC

libzongware.so:
	g++ threads.o standard.o audio.o input.o entity.o graphics.o main.o -o libzongware.so -lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_mixer -shared

install:
	sudo cp libzongware.so /usr/lib/

run:
	./game

clean:
	rm *.o
	rm libzongware.so