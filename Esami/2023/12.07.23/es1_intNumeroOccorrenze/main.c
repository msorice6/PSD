/*
    Si implementi intNumeroOccorrenze(BTree, Item) che prende in input un labero binario
    e un elemento generico e restituisce:
        * il numero di volte che tale elemento e' contenuto nell'albero

*/

#define BTREE_H "../../../../Data Structures/btree/btree.h"
#define ITEM_H "../../../../Data Structures/btree/item.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include BTREE_H
#include ITEM_H

int intNumeroOccorrenze(BTree t, Item itm);
int treeItemEquals(BTree t, int d ,Item itm);
Item inputItemInt(int n);
int main(){
	BTree t;
	t = newTree();
    t = newRandomTree(5);
    printTree(t);

    Item itm;

    printf("numero nodi: %d\n",intNumeroOccorrenze(t, inputItemInt(3) ) );

	return 0;
}

int intNumeroOccorrenze(BTree t, Item itm){
    int numEquals;

    numEquals = treeItemEquals(t,0,itm);


    return numEquals;
}


int treeItemEquals(BTree t,int d,Item itm){

    if(isEmptyTree(t))
        return 0;

   int cmp=0;
   printf("confronto tra ");
   outputItem(getBTreeRoot(t));
   printf("e item: ");
   outputItem(itm);
   if( cmpItem(getBTreeRoot(t),itm ) == 0 ){
         cmp = 1;
         printf("           compare!");
    }
   printf("\n");

    int sx =  treeItemEquals(getLeft(t), d, itm);
    int dx =  treeItemEquals(getRight(t), d, itm);

    d = sx + dx + cmp;
    return d;
}

Item inputItemInt(int n){
	int *pt = malloc(sizeof(int)) ;
    *pt = n;
    return pt;

}


