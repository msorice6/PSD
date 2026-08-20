/* implementa una funzione sumTreeFL(BTree) che prenda in input un labero binario
    e:
     - restituisce un intero positivo che e' la somma dei nodi
     che sono padri di almeno una foglia



*/

#define BTREE_H "../../../../Data Structures/btree/btree.h"
#define ITEM_H "../../../../Data Structures/btree/item.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include BTREE_H
#include ITEM_H
int sumTreeFL(BTree t);
int sumLeaf(BTree t);

int isPadreFoglia(BTree t);
int main(){
    BTree t;
    t = newTree();
    t = newRandomTree(9);
    printTree(t);

    printf("ora guarda questo: \n");
    BTree l = getLeft(t) ;

//    if(!isEmptyTree(getLeft(l)) )
//        outputItem(getBTreeRoot(getLeft(l)));
//     else
//        printf("e' vuoto!\n");

    printf("somma nodi: %d \n", sumTreeFL(t));

    return 0;
}
int sumTreeFL(BTree t){
    if(isEmptyTree(t))
        return 0;

    int c=0;

    BTree l = getLeft(t) ;
    BTree r = getRight(t);

    if(!isEmptyTree(l)  ) {
        if(isEmptyTree(getLeft(l)) && isEmptyTree(getLeft(r) )  ){
           printf("padre left: ");
           outputItem(getBTreeRoot(t));
           printf("\n");
           c=1;
           }
    }

    if( !isEmptyTree(r) ){
           if(isEmptyTree(getRight(l) ) && isEmptyTree(getRight(r) ) ){
               printf("padre Right: ");
               outputItem(getBTreeRoot(t));
               printf("\n");
               c=1;
               }
    }

    return c + sumTreeFL(getLeft(t)) + sumTreeFL(getRight(t) );

}
