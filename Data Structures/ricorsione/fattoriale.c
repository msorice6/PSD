#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int n){
    int i, f=1;
    for(i=n;i>1;i--){
        f*=i;
    }
    return f;
}

int factRic(int n){
    if(n<=1) 
        return 1;
    else
        return n*factRic(n-1);
}

int main(int argc, char *argv[]){
    if(argc!=2){
        fprintf(stderr, "Numero di parametri errato!\n");
        exit(EXIT_FAILURE);
    }
    int n=atoi(argv[1]);
    printf("Il fattoriale è uguale a: %d", factRic(n));

    return 0;
}