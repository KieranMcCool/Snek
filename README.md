# Snek - A Snake clone written in C.

## What is Snek?

\~~Snek is a Snake clone written in C in an effort to get myself more 
comfortable with C programming.~~

Snek is a revolutionary, immersive gaming experience. It is redefining the 
standard of cutting edge graphics and gameplay and bringing a new and exciting 
genre to the mainstream.

## How does it work?

[This probably explains it better than I could in the off chance you've never 
played Snake 
before.](https://en.wikipedia.org/wiki/Snake_(video_game)#Gameplay)

## No, but **how** does it work?

This implementation of the game uses [SDL2](https://www.libsdl.org/) for 
rendering and event capture. The Snek.c/h files contain the code which allow 
the representation and manipulation of the Snek struct.

## Compilation

Can be compiled with:

```
gcc -o Snek render.c
```
