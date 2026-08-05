
/*
    sumLeafNodes(BTree) prende in input un albero binario
    e restituisce la somma delle chiavi contenute nei nodi foglia

*/

#include <stdio.h>
#include "btree.h"
#include "item.h"
#include <stdbool.h> // <-- Aggiungi questa libreria!

int sumLeafNodes(BTree t, int pt);

int main(){
    BTree t;
    t = newTree();
    t = newRandomTree(5);
    printTree(t);

    sumLeafNodes(t, 0);
    return 0;
}
int sumLeafNodes(BTree t, int pt){

    if(isEmptyTree(t)){
        return 0;
    }
    if(getLeft(t) != NULL && getRight(t) != NULL) {
        Item itm1 = getBTreeRoot(getLeft(t));
        Item itm2 = getBTreeRoot(getRight(t));
        int *it1 = itm1;
        int *it2 = itm2;
        pt += *it1 + *it2;
   }else{
        if(getLeft(t) != NULL){
            Item itm1 = getBTreeRoot(getLeft(t));
            int *it1 = itm1;
            pt += *it1 ;
       }
        if(getRight(t) != NULL){
            Item itm2 = getBTreeRoot(getRight(t));
            int *it2 = itm2;
            pt += *it2;
       }
   }

   // deve ritornare pt e deve ritornare il massimo tra i due sumLeafNodes
    sumLeafNodes(getLeft(t), pt);
    sumLeafNodes(getRight(t), pt);
    return 1;
}






