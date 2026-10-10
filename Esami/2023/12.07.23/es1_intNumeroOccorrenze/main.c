/*
Esercizio 1. Si implementi, completando il progetto fornito (Esercizio1), una funzione int numeroOccorrenze
che prenda in input un albero binario ed un elemento generico, e restituisca il numero di volte che tale elemento è contenuto nell'albero.
Modificare esclusivamente il file main.c (completando le funzioni già presenti ed aggiungendone altre se necessario)
ed il makefile, senza aggiungere o modificare altri file. NON toccare BTree.
Testare nel main la procedura sui seguenti alberi (NON chiedere input all'utente da tastiera,
inserire tutto nel codice C):

ALBERO: albero vuoto;
ELEMENTO: 1;

ALBERO: albero consistente della sola radice contenente il numero 2;
ELEMENTO: 3;

ALBERO: albero istanziato come di seguito;
ELEMENTO: 9
      7
     / \
    3   9
   / \   \
  9   5   9

ALBERO: albero casuale con 7 nodi;
ELEMENTO: elemento causale,

Utilizzare la funzione newRandomTree(int nNodes) per creare l'albero casuale (fornita dall'ADT).
Per creare l'elemento causale usare la funzione già fornita randomItem() DOPO AVER CREATO L'ALBERO CASUALE.
ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Esempio di output: (NOTA: il vostro programma DEVE riprodurre questo output,
eccetto per l'albero e l'elemento causali che dovranno essere differenti ad ogni esecuzione del programma):

Albero:
Elemento cercato: 1
Numero occorrenze: 0

Albero:
2
Elemento cercato: 3
Numero occorrenze: 0

Albero:
      7
     / \
    3   9
   / \   \
  9   5   9
Elemento cercato: 9
Numero occorrenze: 3

Albero:
      __3__
     /     \
    _6_     3_
   /   \
  2     2
 / \
4   8
Elemento cercato: 2
Numero occorrenze: 2
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
void allOutput(BTree t, Item itm);
int main(){

// INPUT 1
	BTree t_1 = newTree();
	Item i_1 = inputItemInt(1);
    allOutput(t_1, i_1);
    printf("\n");

// INPUT 2
    BTree t_2 = newTree();
    t_2 = buildTree(NULL, NULL, inputItemInt(2));
	Item i_2 = inputItemInt(3);
    allOutput(t_2, i_2);
    printf("\n");

// INPUT 3
    BTree ll_3 = newTree();
    ll_3 = buildTree(NULL, NULL, inputItemInt(9));

    BTree lr_3 = newTree();
    lr_3 = buildTree(NULL, NULL, inputItemInt(5));

    BTree l_3 = newTree();
    l_3 = buildTree(ll_3, lr_3, inputItemInt(3));

    BTree rr_3 = newTree();
    rr_3 = buildTree(NULL, NULL, inputItemInt(9));

    BTree r_3 = newTree();
    r_3 = buildTree (NULL, rr_3, inputItemInt(9));

    BTree t_3 = newTree();
    t_3 = buildTree(l_3, r_3, inputItemInt(7));

	Item i_3 = inputItemInt(9);
    allOutput(t_3, i_3);
    printf("\n");

	return 0;
}

void allOutput(BTree t, Item itm){

    printf("Albero: ");
    if(isEmptyTree(t))
        printf("\n");
    else{
        printf("\n");
        printTree(t);
    }

    printf("Elemento cercato: ");
    outputItem(itm);
    printf("\n");

    printf("Numero occorrenze: %d\n",intNumeroOccorrenze(t,itm) );


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
   if( cmpItem(getBTreeRoot(t),itm ) == 0 ){
         cmp = 1;
    }

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


