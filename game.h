#include "Snek.c"
#include<SDL.h>

#define WAITTIME 10

typedef struct gamestate {
    Point *food;
    Snek  *s;
    int score;

} Gamestate;

*Gamestate init();
void game_checkfood(Gamestate *g);
void game_checkcollision(Gamestate *g);
void game_tick(Gamestate *g);
