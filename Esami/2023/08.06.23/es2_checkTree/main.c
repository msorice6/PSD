/* Traccia
Esercizio 2. Si implementi, completando il progetto fornito (Esercizio2) una funzione checkTree(BTree)
che prenda in input un albero binario e restituisca   vero se, per ogni nodo, è vero che:
* il figlio sinistro ha un valore minore (o uguale) del padre (o è assente);
* il figlio destro ha un valore maggiore (o uguale) del padre (o è assente);

falso altrimenti.
Usare la ricorsione per implementare l'algoritmo. Modificare esclusivamente i file main.c e makefile, senza aggiungere o modificare gli operatori disponibili negli ADT forniti.
ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.
Testare nel main la procedura sui seguenti alberi (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):
Un albero vuoto;
Un albero consistente della sola radice contenente il numero 2;
Un albero istanziato come di seguito:
    7
   / \
  3   9
 / \
1   5
Un albero casuale con 3 nodi
Un albero casuale con 7 nodi

Utilizzare la funzione printTree(BTree) per stampare gli alberi e la funzione newRandomTree(int nNodes) per creare l'albero casuale (fornite dall'ADT).
Esempio di output:
checkTree: true

Albero:
2
checkTree: true

Albero:
    7
   / \
  3   9
 / \
1   5
checkTree: true

Albero:
  3
 / \
1   5
checkTree: true


*/
#define BTREE_H "../../../../Data Structures/btree/btree.h"
#define ITEM_H "../../../../Data Structures/btree/item.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include BTREE_H
#include ITEM_H

int checkTree(BTree t) ;
BTree buildTreem(BTree t);
void allOutput(BTree t);

int main(){
//  INPUT 1
    BTree t1 = newTree();
    allOutput(t1);
    printf("\n");

//  INPUT 2
    int rad_2=2;
    Item i_rad_2 = &rad_2;

    BTree t2 = newTree();
    t2 = buildTree(NULL,NULL, i_rad_2);

    allOutput(t2);
    printf("\n");

//  INPUT 3
    int rad_3 = 7, l_3 = 3, r_3 = 9, ll_3 = 1, lr_3 = 5;
    Item i_rad_3 = &rad_3, i_l_3 = &l_3, i_r_3 = &r_3, i_ll_3 = &ll_3, i_lr_3 = &lr_3;

    BTree ll = newTree();
    BTree lr = newTree();
    BTree l = newTree();
    BTree r = newTree();
    BTree t3 = newTree();

    ll=buildTree(NULL, NULL, i_ll_3);
    lr=buildTree(NULL, NULL, i_lr_3);
    l = buildTree(ll, lr, i_l_3);
    r = buildTree(NULL, NULL, i_r_3);
    t3 = buildTree(l, r, i_rad_3);

    allOutput(t3);
    printf("\n");

// INPUT 4
    BTree t4 = newTree();
    t4 = newRandomTree(3);
    allOutput(t4);
    printf("\n");

// INPUT 5
    BTree t5 = newTree();
    t5 = newRandomTree(7);
    allOutput(t5);
    printf("\n");


	return 0;
}

void allOutput(BTree t){
    printf("Albero:\n");
    printTree(t);
    printf("checkTree: ");
    if(checkTree(t)==0)
        printf("false\n");
    else
        printf("true\n");

}

int checkTree(BTree t) {
    if(isEmptyTree(t)) {
        return 1;
    }


    BTree r = getRight(t);
    BTree l = getLeft(t);

    if(r){
        if(cmpItem(getBTreeRoot(r), getBTreeRoot(t)) < 0  ) {

            return 0;
        }

    }

    if(l){
        if(cmpItem(getBTreeRoot(l), getBTreeRoot(t)) >0  ) {

            return 0;
        }

    }

    return checkTree(getLeft(t)) && checkTree(getRight(t));
}
