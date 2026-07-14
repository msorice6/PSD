
/*
    heightAndNumNodes che prende in input un albero binario e che calcola la sua altezza ed il
    suo numero di nodi (la funzione restituisce un array di due elementi, il primo contenente
    l’altezza ed il secondo il numero di nodi). Usare la tecnica della ricorsione e scorrere l’albero
    una sola volta per calcolare entrambi i valori (sia altezza che numero dei nodi - non calcolare
    separatamente i due valori).
    • preorder che prende in input un albero binario e stampa in maniera iterativa una visita
    PreOrder dell’albero.
*/


#include <stdio.h>
#include "btree.h"
#include "item.h"
#include <stdbool.h> // <-- Aggiungi questa libreria!

int contaNodi(BTree t, int c);
int contaAltezza(BTree t, int c);
int calcolaAltezza(BTree t, int cl, int cr);
int main(){
    BTree t;

    t = newRandomTree(7);
    printTree(t);

    printf("\n\n");

    int c=0;
    c = contaNodi(t,0) ;
    printf("nodi in c: %d\n", c);
    c = 0;
    c = calcolaAltezza(t,0,0,true);
    printf("altezza in c: %d\n", c);

    return 0;
}

int calcolaAltezza(BTree t, int cl, int cr) {

    if(isEmptyTree(t))
        return cl;

    cl++;
    if(isLeft)
    cl = calcolaAltezza(getLeft(t),cl,cr);

    cr++;
    cr = calcolaAltezza(getRight(t),cl,cr);
}

int contaAltezza(BTree t, int c){

    if(isEmptyTree(t))
        return c;

    c++;


    c= contaAltezza(getLeft(t), c);
    c= contaAltezza(getRight(t), c);


    return c;
}



int contaNodi(BTree t, int c){

    if(isEmptyTree(t))
        return c;

    c++;
    printf("valore di c: %d\n", c);
    printf("nodo letto: ");
    outputItem(getBTreeRoot(t));
    printf("\n");
    printf("\n");

     c= contaNodi(getLeft(t), c);
     c= contaNodi(getRight(t), c);


//        c = contaNodi(t,c) ;
    return c;

}





