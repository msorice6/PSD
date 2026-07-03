#include<stdio.h>
#include<stdlib.h>

int main(){
    int *c;
    int *m;

    c = ((int *) calloc(3, sizeof(int)));
    m = ((int *) malloc(3 * sizeof(int)));

    printf("calloc: %d", c[1]);
    printf("\n");
    printf("malloc: %d", m[1]);
    return 0;


}