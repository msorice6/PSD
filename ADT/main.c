// Header file for input output functions
#include <stdio.h>
#include <stdlib.h>
#include "punto.h"



int main() {
    // 1. Create the point using the constructor
    Point p = crea_punto(2.0, 3.0);

    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Hello World ADT\n");

    // 2. Perform operations
    sposta(p, 7.0, 1.0);

    // 3. Use getters to print values (since p->x is inaccessible here)
    printf("New X: %f\n", get_x(p));

    // 4. Free the memory using the destructor
    distruggi_punto(p);

    return 0;
}