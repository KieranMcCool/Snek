#include "Snek.h"

void moveSnek(Snek * s){
    /* For each segement of Snek, segment
     * should move in segment.dir */
    
    do { 
       switch(s->dir){ 
            case 'r':
                Point p = *s->pos;
                p.x++;
                break;
            case 'l':
                Point p = *s->pos;
                p.x--;
                break;
            case 'u':
                Point p = *s->pos;
                p.y--;
                break;
            case 'd':
                Point p = *s->pos;
                p.y++;
                break;
            default:
                // Snek is malformed. 
                break;
       }
    } while ((s = s->body) != NULL);
}

void checkCollision(Snek * s, Point p){


}

void addSegment(Snek * s){

}
