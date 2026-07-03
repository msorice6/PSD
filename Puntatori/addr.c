#include<stdio.h>
#include<stdlib.h>

int main(){
    int *a;
    int i=5;

    *a=3;
    a = &i;

    printf("a: %d",*i );
    printf("\n");
//    printf("malloc: %d", m[1]);
    return 0;


}