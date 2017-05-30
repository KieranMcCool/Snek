#include <SDL.h>
#include <stdbool.h>
#include "Snek.c"
#include "render.c"

#define WAITTIME 10

typedef struct gamestate {
    Point *food;
    Snek  *s;
    int score;
    bool playing;
    bool eventRec;
    char dir;

} Gamestate;

Gamestate *init();
void game_checkfood(Gamestate *g);
void game_checkcollision(Gamestate *g);
void game_tick(Gamestate *g);
void processEvent(Gamestate *g, SDL_Renderer * ren);
Point *game_foodgen();
