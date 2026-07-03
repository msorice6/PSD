//struct Point;
//#ifndef PUNTO_H
//#define PUNTO_H

struct Point {
    float x;
    float y;
};

// Use "struct Point *p" instead of "Point p"
void sposta(struct Point *p, float dx, float dy);

//#endif