
/*
Esercizio 1. Si implementi, completando il progetto fornito (Esercizio1) una funzione sumLeafNodes(BTree) che prenda in input un albero binario
e restituisca la somma di tutti le chiavi (intere) contenute nei nodi foglia. Usare la ricorsione per implementare l'algoritmo. Modificare il file main.c,
senza aggiungere o modificare gli operatori disponibili negli ADT forniti.

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Testare nel main la procedura sui seguenti alberi (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):

Un albero vuoto;

Un albero consistente della sola radice contenente il numero 2;

Un albero instanziato come di seguito

Plaintext
    7
   / \
  3   9
 / \
1   5
Un albero casua e con 7 nodi

Utilizzare la funzione printTree(BTree) per stampare gli alberi e la funzione newRandomTree(int nNodes) per creare l'albero casuale (fornite dall'ADT).

Esempio di output: (NOTA: il vostro programma DEVE riprodurre questo output, eccetto nel caso dell'albero casuale
che deve essere differente ad ogni esecuzione del programma)

Albero:

Somma nodi foglia: 0

Albero:
2
Somma nodi foglia: 2

Albero:
    7
   / \
  3   9
 / \
1   5
Somma nodi foglia: 15

Albero:
       2
     /   \
    5     3
   /       \
  6         9
 / \
8   1
Somma nodi foglia: 18

*/
#define BTREE_H "../../../../Data Structures/btree/btree.h"
#define ITEM_H "../../../../Data Structures/btree/item.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include BTREE_H
#include ITEM_H

int sumLeafNodes(BTree t);
int max(int a, int b);
void evryOutput(BTree t);
Item inputItemInt(int n);
int main(){
    BTree t_1=newTree();
    evryOutput(t_1);
    printf("\n");

    BTree t_2=newTree();
    t_2 = buildTree(NULL,NULL, inputItemInt(2));
    evryOutput(t_2);
    printf("\n");

    BTree t_3=newTree();
    BTree t_3_l = newTree();
    BTree t_3_ll = newTree();
    BTree t_3_lr = newTree();
    BTree t_3_r = newTree();

    t_3_ll = buildTree(NULL,NULL, inputItemInt(1));
    t_3_lr = buildTree(NULL,NULL,inputItemInt(5));

    t_3_l = buildTree(t_3_ll, t_3_lr, inputItemInt(3));
    t_3_r = buildTree(NULL,NULL,inputItemInt(9));

    t_3 = buildTree(t_3_l,t_3_r, inputItemInt(7));
    evryOutput(t_3);
    printf("\n");

    BTree t_4 = newTree();
    t_4 = newRandomTree(7) ;
    evryOutput(t_4);
    printf("\n");


//    printTree(t);
//    sumLeafNodes(t, 0);
//    printf("somma delle chiavi di ogni nodo: %d", sumLeafNodes(t));
//    sumLeafNodes(t, 0);
    return 0;
}

Item inputItemInt(int n) {
    int *pInt=malloc(sizeof(int));
    *pInt=n;
    return pInt;
}
void evryOutput(BTree t) {
    printf("Albero: \n") ;
    printTree(t);
    printf("somma nodi foglia: %d", sumLeafNodes(t));
    printf("\n");



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

//    }
    // Passo Ricorsivo: Chiedo le somme ai rami sinistro e destro e le unisco
//    int sx = sumLeafNodes(getLeft(t));
//    int dx = sumLeafNodes(getRight(t));
    return  *val +sumLeafNodes(getLeft(t)) +sumLeafNodes(getRight(t));
}