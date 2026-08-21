/* implementa una funzione sommaFoglieDestre(BTree) che prenda in input un labero binario
    e:
     - restituisce la somma dei valori contenuti nei nodi foglia
     che sono figli destri
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

int sommaFoglieDestre(BTree t);

int *outputItemInt(Item itm);
int main(){
    BTree t = newTree();
    t = newRandomTree(8) ;
    printTree(t);
    printf("somma nodi: %d\n", sommaFoglieDestre(t));
//    int *sa =outputItemInt(inputItem()) ;
//    int da = *sa;
//    printf("salve salvino: %d", da);



    return 0;
}

int *outputItemInt(Item itm){
	int *pt = itm;
    return pt;
}


int sommaFoglieDestre(BTree t){
//    Item c;
    Item c_itm;
    int *c=0;
    int n=0;
    if(isEmptyTree(t))
        return 0;

    BTree l = getLeft(t);
    BTree r = getRight(t);

    if(!isEmptyTree(getRight(t))){
        if(isEmptyTree(getRight(r)) && isEmptyTree(getRight(l))  ) {
            c = outputItemInt(getBTreeRoot(t)) ;

//             printf("questo albero ha la foglia destra: ") ;
//             outputItem( getBTreeRoot (t) );
//             printf("\n") ;
            n = *c;
//            printf("guarda n: %d\n", n);
        }



    }
    return n + sommaFoglieDestre(getLeft(t)) + sommaFoglieDestre(getRight(t));
}