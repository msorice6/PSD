
/*
    sumLeafNodes(BTree) prende in input un albero binario
    e restituisce la somma delle chiavi contenute nei nodi

*/
#define BTREE_H "../../../../Data Structures/btree/btree.h"
#define ITEM_H "../../../../Data Structures/btree/item.h"

#include <stdio.h>
#include <stdbool.h>

#include BTREE_H
#include ITEM_H

int sumLeafNodes(BTree t);
int max(int a, int b);

int main(){
    BTree t;
    t = newTree();
    t = newRandomTree(5);
    printTree(t);

//    sumLeafNodes(t, 0);
    printf("somma delle chiavi di ogni nodo: %d", sumLeafNodes(t));
//    sumLeafNodes(t, 0);
    return 0;
}
int sumLeafNodes(BTree t) {
    // Caso base: se l'albero è vuoto, la somma è 0
    if (isEmptyTree(t)) {
        return 0;
    }

    // Condizione Foglia: se non ho figli sinistro e destro, restituisco il mio valore
//    if (isEmptyTree(getLeft(t)) && isEmptyTree(getRight(t))) {
        Item itm = getBTreeRoot(t);
        int *val = (int*)itm;
//        return *val;

//    }
    // Passo Ricorsivo: Chiedo le somme ai rami sinistro e destro e le unisco
    int sx = sumLeafNodes(getLeft(t));
    int dx = sumLeafNodes(getRight(t));
    return *val +sx+dx;
}