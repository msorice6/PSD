#include <math.h>
#include <stdlib.h>
#include "point.h"

struct point{
    float x; 
    float y;
};

Punto creaPunto(float x, float y){
    Punto p = malloc(sizeof(struct point));
    p->x = x;
    p->y = y;
    return p;
}

float ascissa(Punto p){
    return p->x;
}

float ordinata(Punto p){
    return p->y;
}

float distanza(Punto p1 , Punto p2 ){
    float dx,dy;
    dx = p1->x - p2->x;
    dy = p1->y - p2->y;
    return sqrt(dx*dx+dy*dy); 
}