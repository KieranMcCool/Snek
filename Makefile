CC=clang
CFLAGS=`sdl2-config --cflags --libs` -lSDL2_ttf -W 

all:
	$(CC) -o test.o $(CFLAGS) render.c

clean:
	rm *.ok
