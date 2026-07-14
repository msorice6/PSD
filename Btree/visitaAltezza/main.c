/*

    Visita altezza albero binario

*/
#include <stdio.h>
#include "btree.h"
#include "item.h"
#include <stdbool.h> // <-- Aggiungi questa libreria!
int calcolaAltezza(BTree t);
int massimo(int a, int b);
int main(){
    BTree t;

    t = newRandomTree(7);
    printTree(t);

    printf("ecco il val: %d \n",calcolaAltezza(t));



    return 0;
}

int calcolaAltezza(BTree t){

    if(isEmptyTree(t)) {
        return 0;
    }

    if(isEmptyTree(getLeft(t)) && isEmptyTree(getRight(t))){
        return 0;
    }

        return 1 + (massimo(  (calcolaAltezza(getLeft(t))) , calcolaAltezza(getRight(t))) )  ;

}

int massimo(int a, int b){

    if(a>b){
        return a;
    }else{
        return b;
    }

    return a;
}