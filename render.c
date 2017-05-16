#include<stdio.h>
#include<stdlib.h>
#include<SDL.h>
#include<SDL_ttf.h>
#include<stdbool.h>
#include "Snek.c"
#include<unistd.h>

#define WIDTH 640
#define HEIGHT 640
#define PAD  40

#define CELLS 40 

int ErrorNo;
enum Errors { GAMEBOARD_ERROR, SNEKRENDER_ERROR, SCORERENDER_ERROR, SDL_ERROR};

int drawGameBoard(SDL_Renderer *r){

    SDL_Rect outline;
    outline.x = PAD; outline.y = PAD;
    outline.w = WIDTH - (2 * PAD); outline.h = HEIGHT - (2 * PAD);

    int xLine = (WIDTH - 2 * PAD) / CELLS;
    int yLine = (HEIGHT - 2 * PAD) / CELLS;

    for (int x = PAD; x < WIDTH - PAD; x += xLine)
        SDL_RenderDrawLine(r, x, PAD, x, HEIGHT - PAD);
    for (int y = PAD; y < HEIGHT - PAD; y += yLine)
        SDL_RenderDrawLine(r, PAD, y, WIDTH - PAD, y);
    SDL_RenderDrawRect(r, &outline);
    return 0;
}

int drawFood(SDL_Renderer *r, Point *foodpos){
    int xLine = (WIDTH - 2 * PAD) / CELLS;
    int yLine = (HEIGHT - 2 * PAD) / CELLS;

    SDL_Rect food;
    food.x = xLine * foodpos->x + PAD;
    food.w = xLine;
    food.y = yLine * foodpos->y  + PAD;
        food.h = yLine;

    SDL_RenderFillRect(r, &food);
    return 0;
}
int drawSnek(SDL_Renderer *r, Snek *s){
    int width = (WIDTH - 2 * PAD) / CELLS;
    int height = (HEIGHT - 2 * PAD) / CELLS;

    SDL_Rect segment;
    int count = 0;
    printf("Drawing Snek:\n");
    do {
        if(count % 2 == 0)
            SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
        else
            SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
        count++;
        printf("\tSegment: (%d, %d)\n", s->pos.x, s->pos.y);
        segment.x = s->pos.x * width + PAD;
        segment.y = s->pos.y * height + PAD;
        segment.w = width;
        segment.h = height;
        printf("\tTranslated Points: (%d, %d)\n", segment.x, segment.y);

        SDL_RenderFillRect(r, &segment);
        
    } while ( (s = s->body) != NULL);

    SDL_SetRenderDrawColor(r, 255,255,255,255);
    return 0;
}

int drawScore(SDL_Renderer *r, int score){
    TTF_Font* Sans = TTF_OpenFont("Arial.ttf", 72); 

    char * scoreText;
    scoreText = malloc(sizeof(char) * 256);
    sprintf(scoreText, "Score: %d", score);

    SDL_Color White = {255, 255, 255, 255};  
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, scoreText, White); 
    SDL_Texture* Message = SDL_CreateTextureFromSurface(r, surfaceMessage); 

    SDL_Rect Message_rect; 
    Message_rect.x = WIDTH - PAD - 80;  
    Message_rect.y = HEIGHT - PAD + 2;  
    Message_rect.w = 80;
    Message_rect.h = PAD - 10;
    
    SDL_RenderCopy(r, Message, NULL, &Message_rect);

    TTF_CloseFont(Sans);
    SDL_DestroyTexture(Message);
    SDL_FreeSurface(surfaceMessage);
    free(scoreText);
    
    return 0;
}

int drawGameState(SDL_Renderer *r, Snek *s, Point food, int score){
    if(drawGameBoard(r) < 0) {
        ErrorNo = GAMEBOARD_ERROR;
        return -1;
    }
    if(drawSnek(r, s) < 0) {
       ErrorNo = SNEKRENDER_ERROR;
       return -1;
    }
    if(drawScore(r, score) < 0){
        ErrorNo = SCORERENDER_ERROR;
        return -1;
    }

    SDL_RenderPresent(r);
    return 0;
}

int main(){
    Snek *s = Snek_getSnek(5, 20, 20, 'd');
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        return 1;
    }
    if(TTF_Init() != 0){ 
        return 1;
    }
    SDL_Window *win = SDL_CreateWindow("Snek", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
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
        drawGameState(ren, s, 3);
    }
}
