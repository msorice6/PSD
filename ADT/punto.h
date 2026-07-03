//struct Point;
//#ifndef PUNTO_H
//#define PUNTO_H

typedef struct point *Point;


// Use "struct Point *p" instead of "Point p"
void sposta(Point p, float dx, float dy);
Point crea_punto(float x, float y);
void distruggi_punto(Point p);
float get_x(Point p);
float get_y(Point p);