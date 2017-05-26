*Gamestate init(){
    Gamestate out = malloc(sizeof(Gamestate));
    out->s = Snek_getSnek(5, 10, 10, 'r');
    out->food = (Point){ 13, 14 };
    out->score = 0;

    return &out;
}

void game_checkfood(Gamestate *g){
    if (g->food->x == g->s.x && g->food->y == g->s.y)
        puts("food consumed");
}

void game_checkcollision(Gamestate *g){
    
}

void game_tick(Gamestate *g){
    
}
