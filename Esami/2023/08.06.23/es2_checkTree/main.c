/*
    Si implementi checkTree(BTree) che prende in input un labero binario e restituisce:
        * vero: se per ogni nodo e' vero che:
            * il figlio sinistro ha un valore minore (o ugulae) del padre ( o e' assente);
            * il figlio destro ha un valore maggiore (o ugulae) del padre ( o e' assente);')
        * falso altrimenti.
*/
#define BTREE_H "../../../../Data Structures/btree/btree.h"
#define ITEM_H "../../../../Data Structures/btree/item.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include BTREE_H
#include ITEM_H

bool checkTree(BTree h);
int bTreeHeight(BTree h);

int main(){
	BTree h;
	h = newTree();
    h = newRandomTree(3);

    printf("\nbool: %d\n",checkTree(h));
    printTree(h);

	return 0;
}

bool checkTree(BTree h){
    int n;
    n = bTreeHeight(h);
    printf("Height: %d\n", n);
    if(n>0)
        return true;
    return false;
}


int bTreeHeight(BTree h){
    if(isEmptyTree(h))
        return 0;

    if(getLeft(h) != NULL)
        if(cmpItem(getBTreeRoot(getLeft(h)), getBTreeRoot(h)) > 0){
            printf("item IF left: ");
            outputItem(getBTreeRoot(h));
            printf("\n");
            return 1;
            }

    if(getRight(h) != NULL)
       if(cmpItem(getBTreeRoot(getRight(h)), getBTreeRoot(h)) < 0){
            printf("item IF right: ");
            outputItem(getBTreeRoot(h));
            printf("\n");
            return 1;
       }

    if( ( bTreeHeight(getLeft(h)) == 1 ) || ( bTreeHeight(getRight(h)) == 1) )  return 1;

}



/* QUESTO CONTROLLA SE c'e' un figlio minore del padre
quindi se tutti i figli sono maggiori del padre ritorna 0
se c'e' quindi un figlio minore del padre ritorna 1

int bTreeHeight(BTree h){
    if(isEmptyTree(h))
        return 0;

    if(getLeft(h) != NULL)
        if(cmpItem(getBTreeRoot(getLeft(h)), getBTreeRoot(h)) <= 0){
            printf("item IF left: ");
            outputItem(getBTreeRoot(h));
            printf("\n");
            return 1;
            }

    if(getRight(h) != NULL)
       if(cmpItem(getBTreeRoot(getRight(h)), getBTreeRoot(h)) <= 0){
            printf("item IF right: ");
            outputItem(getBTreeRoot(h));
            printf("\n");
            return 1;
       }

    if( ( bTreeHeight(getLeft(h)) == 1 ) || ( bTreeHeight(getRight(h)) == 1) )  return 1;
}

*/