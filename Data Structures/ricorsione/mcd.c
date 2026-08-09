#include <stdio.h>
#include <stdlib.h>

int mcd(int a, int b){
    int r;
    while(b!=0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int mcdRecursive(int a,int b){
    if(b == 0) 
        return a;
    else 
        return mcdRecursive(b,a%b);
}

int main(int argc, char *argv[]){
    if(argc!=3){
        fprintf(stderr, "Numero di parametri errato!\n");
        exit(EXIT_FAILURE);
    }
    int a=atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("MCD (%d,%d) = %d",a,b, mcdRecursive(a,b));

    return 0;
}