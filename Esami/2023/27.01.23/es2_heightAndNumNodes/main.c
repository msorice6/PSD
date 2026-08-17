/*
   Implementa due funzioni:
    - heightAndNumNodes: prende in input un albero binario e calcola l'altezza ed il suo numero di nodi
    - preorder: prende in input un albero binario e stampa in maniera iterativa una visita PreOrder dell'albero
*/
#define BTREE_H "../../../../Data Structures/btree/btree.h"
#define ITEM_H "../../../../Data Structures/btree/item.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include BTREE_H
#include ITEM_H

int heightTree(BTree t);
int numNodesTree(BTree t);
int *heightAndNumNodes (BTree t);

int max(int a, int b);
int main(){
    BTree t;
    t = newTree();
    t = newRandomTree(9);
    printTree(t);
    int *b = heightAndNumNodes(t) ;


    printf("\n heightTree: %d\n", b[0]);
    printf("\n numNodesTree: %d\n", b[1]);

    return 0;
}
int *heightAndNumNodes(BTree t){
    int *a = malloc(2 * sizeof(int));

    a[0] = heightTree(t);
    a[1] = numNodesTree(t);

    return a;

}

int heightTree(BTree t){
    if(isEmptyTree(t))
        return 0;

    return 1 + max(heightTree(getLeft(t)) , heightTree(getRight(t)));
}

int numNodesTree(BTree t){
    if(isEmptyTree(t))
        return 0;

    return 1+numNodesTree(getLeft(t)) + numNodesTree(getRight(t));
}
    //return 1+ heightAndNumNodes(getLeft(t), 0) + heightAndNumNodes(getRight(t), 0);
int max(int a, int b){
    if(a>b)
        return a;
    return b;
}
