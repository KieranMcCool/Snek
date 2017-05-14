#include "Snek.h"

void moveSnek(Snek * s){
    /* For each segement of Snek, segment
     * should move in segment.dir */
    
    do { 
       switch(s->dir){ 
            case 'r':
                s->pos.x ++;
                break;
            case 'l':
                s->pos.x --;
                break;
            case 'u':
                s->pos.y --;
                break;
            case 'd':
                s->pos.y ++;
                break;
            default:
                // Snek is malformed. 
                break;
       }
    } while ((s = s->body) != NULL);
}

void checkCollision(Snek * s, Point p){
    printf("%c%d\n", s->dir, p.x);
}

void addSegment(Snek * s){
    for (; (s = s->body) != NULL; )
        ;
}
