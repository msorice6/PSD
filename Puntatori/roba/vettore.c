#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vettore.h"
    char* input_array_dyn() {
    int n=0;
    char *a = malloc(5 * sizeof(char *));

    if (a == NULL) {
        return NULL;
    }

    strcpy(a, "spazi");

     return a;

 }

//
// void bubble_sort(int *a, int n) {
// }
//
// void output_array(const int *a, int n) {
// }

void helloWorld(){
    printf("\nhWord da vettore.c \n");
}
