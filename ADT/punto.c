#include <stdlib.h>
#include "punto.h"

//struct Point;

void sposta(struct Point *p, float dx, float dy){
    p->x = p->x + dx;
    p->y = p->y + dx;

}