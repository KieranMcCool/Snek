#include <stdio.h>

typedef struct point Point;
typedef struct snek Snek;

// Point has x and y
struct point { int x; int y;};
/* Snek has a head, which has a position
 * and direction * of movement, also has
 * a body expressed as another snek. */
struct snek { Point pos; char dir;  Snek * body;};

void moveSnek(Snek ** s, char dir);

void checkCollision(Snek  * s, Point p);
void Snek_AddBack(Snek * s);
void Snek_AddFront(Snek ** s, char dir);
void Snek_RemoveBack(Snek * s);
