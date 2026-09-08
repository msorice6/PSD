#define BTREE_H "../../Data Structures/btree/btree.h"
#define ITEM_H "../../Data Structures/btree/item.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include BTREE_H
#include ITEM_H

int contaNodi(BTree t);
int contaAltezza(BTree t);
int max(int a, int b);
int sommaFoglieDestre(BTree t); // restutyusce la somma dei nodi foglia che sono figli destri
int sommaFoglie(BTree t);
int sumNodesLevel1Fl(BTree t, int level); // somma tutti i nodi di un dato livello dell'albero
int sommaNodi(BTree t, int level, int risultati[]);
int main(){
	BTree t;
	t = newTree();
    t = newRandomTree(4);

    printTree(t);
    printf("numero nodi: %d\n", contaNodi(t));
    printf("Altezza: %d\n", contaAltezza(t));
    printf("numero foglie: %d\n",sommaFoglie(t));
    printf("numero nodi foglia che sono figli destri: %d \n",sommaFoglieDestre(t) );

    sumNodesLevel1Fl(t,0);
/*
    printf("risultati[1]: %d\n", risultati[1]);

    int i=0;
    while(risultati[i] != '\0'){
        printf("livello: %d     valore: %d\n",i, risultati[i]) ;
        i++;
    }
*/

//    int livello = 2;
//    printf("somma nodi del livello: %d: %d\n", livello, sumNodesLevel1Fl(t,livello));
	return 0;
}

int sommaNodi(BTree t, int level, int risultati[]){

    if (isEmptyTree(t)){
        return 0;
    }
    Item itm = getBTreeRoot(t);
    int *n=itm;
    int c = *n;

    risultati[level] = risultati[level] + c;

    sommaNodi(getLeft(t), level+1, risultati);
    sommaNodi(getRight(t), level+1, risultati);
    return 0;
}
int sumNodesLevel1Fl(BTree t, int level){
    int risultati[255];
    sommaNodi( t, 0, risultati);
    return risultati[level];
}

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int sommaFoglieDestre(BTree t){ // restutyusce la somma dei nodi foglia che sono figli destri
    if (isEmptyTree(t)){
        return 0;
    }
    BTree l = getLeft(t);
    BTree r = getRight(t);

    if(getRight(t)) {
        if(!getRight(l) && !getLeft(r))
            return 1;
    }


    return sommaFoglieDestre(getLeft(t))+ sommaFoglieDestre(getRight(t));
}

int sommaFoglie(BTree t){

    if (isEmptyTree(t)){
        return 0;
    }
    int c=0;
    if(!getLeft(t) && !getRight(t)){
       return 1;



    }


    return sommaFoglie(getLeft(t))+ sommaFoglie(getRight(t));

}
int contaAltezza(BTree t){
    if (isEmptyTree(t)){
        return 0;
    }
        if(!getLeft(t) && !getRight(t) )
            return 0;

    return  1+max(contaAltezza(getLeft(t)) , contaAltezza(getRight(t)));

}

int contaNodi(BTree t){
    if (isEmptyTree(t)){
        return 0;
    }

    return 1 + contaNodi(getLeft(t)) + contaNodi(getRight(t));

}
