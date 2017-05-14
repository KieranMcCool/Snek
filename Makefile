CC=clang
CFLAGS=`sdl2-config --cflags --libs` -W 

all:
	$(CC) -o test.o $(CFLAGS) render.c

clean:
	rm *.ok
