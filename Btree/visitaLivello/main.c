
#include <stdio.h>
#include "btree.h"
#include "item.h"
#include <stdbool.h> // <-- Aggiungi questa libreria!
#include <stdlib.h>

int visitaPerLivello(BTree t, int livello, int risultati[]);

int main(){
    BTree t = newTree();
    t = newRandomTree(5);
    int arrayRisultati[10] = {0};
    printf("livelli: %d\n", visitaPerLivello(t,0,arrayRisultati));
    printTree(t);


    printf("lunghi livelli: \n") ;

    for(int i = 0; i<10;i++)
        printf("livello %d: %d\n", i, arrayRisultati[i]) ;

    return 0;
}

int visitaPerLivello(BTree t, int livello, int risultati[]){
    if(isEmptyTree(t)){
        return livello;
    }

    int *n = malloc(sizeof(int)) ;
    *n= *(int*) getBTreeRoot(t) ;
    risultati[livello] = risultati[livello] + *n; //getBTreeRoot(t);

    free(n);
    visitaPerLivello(getLeft(t), livello + 1, risultati) ;
    visitaPerLivello(getRight(t), livello + 1, risultati);

}



