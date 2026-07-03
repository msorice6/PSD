#include <stdlib.h>
#include "punto.h"

//struct Point;
struct point {
    float x;
    float y;
};

void sposta(Point p, float dx, float dy){
    p->x = p->x + dx;
    p->y = p->y + dx;
}

// Constructor allocates memory
Point crea_punto(float x, float y) {
    Point p = malloc(sizeof(struct point));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

// Destructor frees memory
void distruggi_punto(Point p) {
    free(p);
}

float get_x(Point p) { return p ? p->x : 0.0f; }
float get_y(Point p) { return p ? p->y : 0.0f; }