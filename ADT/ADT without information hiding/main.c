// Header file for input output functions
#include <stdio.h>
#include <stdlib.h>
#include "punto.h"



int main() {
    struct Point *p = malloc(sizeof(struct Point));

    p->x = 2.0;
    p->y = 3.0;

    printf("Hello World ADT");
    sposta(p,7.0, 1.0);

    printf("%f\n", p->x);

free(p);
    return 0;

}