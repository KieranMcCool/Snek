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
                position->x = x - i; position->y = y;
                break;
            case 'l':
                position->x = x + i; position->y = y;
                break;
            case 'u':
                position->x = x; position->y = y + i;
                break;
            case 'd':
                position->x = x; position->y = y - i;
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
}

void Snek_moveSnek(Snek ** s){
    Snek_AddFront(s);
    Snek_RemoveBack(*s);
}

void Snek_AddFront(Snek ** s){
   
    Snek * oldHead = *s;
    Snek * newHead;

    switch(oldHead->dir){
        case 'r':
            puts("r");
            newHead = Snek_getSnek(1, oldHead->pos.x + 1, oldHead->pos.y, oldHead->dir);
            break;
        case 'l':
            puts("l");
            newHead = Snek_getSnek(1, oldHead->pos.x - 1, oldHead->pos.y, oldHead->dir);
            break;
        case 'u':
            puts("u");
            newHead = Snek_getSnek(1, oldHead->pos.x, oldHead->pos.y - 1, oldHead->dir);
            break;
        case 'd':
            puts("d");
            newHead = Snek_getSnek(1, oldHead->pos.x + 1, oldHead->pos.y + 1, oldHead->dir);
            break;
    }

    newHead->body = oldHead;
    *s = newHead;
}

void Snek_AddBack(Snek * s){
    while(s->body != NULL){
        s = s->body;
    }
    
    switch(s->dir){
        case 'r':
            s->body = Snek_getSnek(1, s->pos.x - 1, s->pos.y, s->dir);
            break;
        case 'l':
            s->body = Snek_getSnek(1, s->pos.x + 1, s->pos.y, s->dir);
            break;
        case 'u':
            s->body = Snek_getSnek(1, s->pos.x, s->pos.y + 1, s->dir);
            break;
        case 'd':
            s->body = Snek_getSnek(1, s->pos.x, s->pos.y -1, s->dir);
            break;
    }
}

void Snek_RemoveBack(Snek * s){
    if ( s->body == NULL) return;
    
    while(1){
        // If next is last.
        if(s->body->body == NULL){
            Snek_freeSnek(s->body);
            s->body = NULL;
            break;
        } else { s = s->body; } 
    }
}
