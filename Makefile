CC=clang
CFLAGS=`sdl2-config --cflags --libs` -lSDL2_ttf -W 

all:
	$(CC) -o Snek $(CFLAGS) game.c

clean:
	rm *.o
