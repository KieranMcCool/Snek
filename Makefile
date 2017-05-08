CC=clang
CFLAGS=`sdl2-config --cflags --libs` -W 

all:
	$(CC) -o test.o $(CFLAGS) Snek.c

clean:
	rm *.ok
