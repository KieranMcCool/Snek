#include<stdio.h>
#include<stdlib.h>
#include<SDL.h>
#include<stdbool.h>

#define HEIGHT 600
#define WIDTH 480

// Snek's body segment sizes.
#define SEG_X_LEN 30
#define SEG_Y_LEN 10

int drawSquare(SDL_Renderer * ren, Point * p1, Point *  p2){
    SDL_RenderDrawLine(ren, p1->x, p1->y, p2->x, p1->y);
    SDL_RenderDrawLine(ren, p1->x, p1->y, p1->x, p2->y);
    SDL_RenderDrawLine(ren, p2->x, p2->y, p1->x, p2->y);
    SDL_RenderDrawLine(ren, p2->x, p2->y, p2->x, p1->y);
    return 1;
}

int drawSnek(SDL_Renderer * ren, Snek * snek){
    do{
        Point p1 = { snek->pos.x, snek->pos.y - SEG_X_LEN};
        Point p2 = { snek->pos.x + SEG_Y_LEN, snek->pos.y};
        drawSquare(ren, &p1, &p2);
    } while ((snek = snek->body) != NULL);
    return 1;
}

int main(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        return 1;
    }
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, HEIGHT, WIDTH, SDL_WINDOW_SHOWN);
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
        Snek head = { {10, 20}, 'r', NULL}; 
        Snek *last = &head;
        for(int i = 0; i < 10; i++){
            Snek new = {{ last->pos.x + SEG_X_LEN, last->pos.y}, 'r', NULL };
            last->body = &new;
            last = &new;
        }
        drawSnek(ren, &head);
    }
}
