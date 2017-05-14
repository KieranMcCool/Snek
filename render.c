#include<stdio.h>
#include<stdlib.h>
#include<SDL.h>
#include<stdbool.h>
#include "Snek.c"

#define WIDTH 640
#define HEIGHT 480
#define PAD  40

#define CELLS 40 

int drawGameBoard(SDL_Renderer *r){

    SDL_Rect outline;
    outline.x = PAD; outline.y = PAD;
    outline.w = WIDTH - (2 * PAD); outline.h = HEIGHT - (2 * PAD);

    int xLine = (WIDTH - PAD) / CELLS;
    int yLine = (HEIGHT - PAD) / CELLS;

    for (int x = PAD; x < WIDTH - PAD; x += xLine)
        SDL_RenderDrawLine(r, x, PAD, x, HEIGHT - PAD);
    for (int y = PAD; y < HEIGHT - PAD; y += yLine)
        SDL_RenderDrawLine(r, PAD, y, WIDTH - PAD, y);

    SDL_RenderDrawRect(r, &outline);
    return 1;
}

int drawSnek(SDL_Renderer *r, Snek *s){
    return 0;
}

int drawScore(SDL_Renderer *r){
    return 0;
}

int drawGameState(SDL_Renderer *r){
    drawGameBoard(r);
    drawSnek(r, NULL);
    drawScore(r);

    SDL_RenderPresent(r);
    return 0;
}

int main(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        return 1;
    }
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL){
        SDL_Quit();
        return 1;
    }
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL){
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Event  e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                 quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
        }
        drawGameState(ren);
    }
}
