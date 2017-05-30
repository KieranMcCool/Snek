#include "game.h"

Gamestate *game_init(){
    Gamestate *out = malloc(sizeof(Gamestate));
    out->s = Snek_getSnek(5, 10, 10, 'r');
    out->food = game_foodgen();
    out->score = 0;
    out->playing = true;
    out->dir = 'r';
    out->eventRec = false;
    return out;
}

void game_checkfood(Gamestate *g){
    if (g->food->x == g->s->pos.x && g->food->y == g->s->pos.y) {
        g->score++;
        Snek_AddBack(g->s);
        g->food = game_foodgen(); 
    }
}

void game_checkcollision(Gamestate *g){
    Snek *s = g->s->body;
    Point head = g->s->pos;

    // Outsite bounds
    if (head.x >= CELLS ||  head.y >= CELLS ||  
            head.x <= 0 || head.y <= 0)
        g->playing = false;
    
    // Snek too small to collide with self.
    if (s == NULL) return;

    // For each body segment, check collision.
    do {
        if ( s->pos.x == head.x && 
                s->pos.y == head.y) {
            // collision
            g->playing = false;
            return;
        }
    } while ((s = s->body) != NULL);
}

void game_tick(Gamestate *g){
    game_checkfood(g);
    game_checkcollision(g);
    Snek_moveSnek(&g->s, g->dir);
}

int randR(int min, int max){
    return rand() % (max + 1 - min) + min;
}

Point *game_foodgen() {
    Point *p = malloc(sizeof(Point));
    p->x = randR(0, CELLS);
    p->y = randR(0, CELLS);
    return p;
}

void processEvent(Gamestate *g, SDL_Renderer *ren){
    char c;
    SDL_Event e;
    while (SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT){
            g->playing = false;
            g->eventRec = true;
            return;
        } else if (e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym){
                case 'w': c = c == 'd' ? 'd' : 'u'; break;
                case 's': c = c == 'u' ? 'u' : 'd'; break;
                case 'a': c = c == 'r' ? 'r' : 'l'; break;
                case 'd': c = c == 'l' ? 'l' : 'r'; break;
                default: break;
            }

            g->s->dir = c;
            g->dir = c;
            g->eventRec = true;
        }
    }

    game_tick(g); 
    drawGameState(ren, g->s, g->food, g->score);
    if(g->eventRec == false) usleep(400 * 1000);
    else g->eventRec = false;
}

int main(){
    Gamestate *g = game_init();
    SDL_Renderer *ren = initialiseRenderere();
    drawGameState(ren, g->s, g->food, g->score);
    while(g->playing) {
        processEvent(g, ren);
    }
}
