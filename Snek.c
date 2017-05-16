#include "Snek.h"

Snek *
Snek_getSnek(int len, int x, int y, char dir){
    Snek * head;
    Snek * new;
    Point * position;

    Snek * last = NULL;
    Point * lastp;

    for(int i = 0; i < len; i++){
        new = malloc(sizeof(Snek));
        position = malloc(sizeof(Point));
        
        switch (dir){
            case 'r':
                position->x = x + i; position->y = y;
                break;
            case 'l':
                position->x = x - i; position->y = y;
                break;
            case 'u':
                position->x = x; position->y = y - i;
                break;
            case 'd':
                position->x = x; position->y = y + i;
                break;
        }

        new->pos = *position;
        new->body = NULL;
        new->dir = 'r';

        if(last != NULL){
            last->body = new;
        } else if(i == 0){
            head = new;
        }

        last = new;
    }
    
    return head;
}

void Snek_freeSnek(Snek * s){
    if(s->body != NULL)
        Snek_freeSnek(s->body);
    free(&(s->pos));
    free(&(s->dir));
    free(s);
}

void Snek_moveSnek(Snek * s){
    
}

void Snek_addSegment(Snek * s){
    while(s->body != NULL)
        s = s->body;

    puts("Loop exited");
    Snek * add = malloc(sizeof(Snek));
    Point * p = malloc(sizeof(Point));

    add->dir = s->dir; 
    p->x = s->pos.x;
    p->y = s->pos.y;

    switch(s->dir){ 
        case 'r':
            p->x++;                 
            break;
        case 'l':
            p->x--;
            break;
        case 'u':
            p->y--;
            break;
        case 'd':
            p->y++;
            break;
        default:
            break;
    }

    add->pos = *p;
    add->body = NULL;
    s->body = add;
}
