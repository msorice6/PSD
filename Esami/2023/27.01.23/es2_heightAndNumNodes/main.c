/*
Esercizio 2. Si implementi, completando il progetto fornito (Esercizio2), due funzioni:

heightAndNumNodes che prende in input un albero binario e che calcola la sua altezza ed il suo numero di nodi
(la funzione restituisce un array di due elementi, il primo contenente l'altezza ed il secondo il numero di nodi).
Usare la tecnica della ricorsione e scorrere l'albero una sola volta per calcolare entrambi i valori
(sia altezza che numero dei nodi - non calcolare separatamente i due valori).

preorder che prende in input un albero binario e stampa in maniera iterativa una visita PreOrder dell'albero.

Modificare esclusivamente il file main.c (completando le funzioni già presenti ed eventualmente aggiungendone altre se necessario) ed il makefile,
senza aggiungere o modificare altri file. NON toccare BTree. Soluzioni non realizzate in main.c non verranno prese in considerazione.

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Testare nel main la procedura sui seguenti alberi:

Un albero vuoto;

Un albero consistente della sola radice contenente il numero 2;

Un albero instanziato come di seguito

Plaintext
    7
   / \
  3   9
     / \
    1   5
Un albero casuale con 8 nodi

Utilizzare la funzione newRandomTree(int nNodes) per creare l'albero casuale (fornita dall'ADT) e la funzione printHeightNumNodesAndPreorder(BTree)
per stampare altezza, numero nodi e visita preorder dell'albero.

Esempio di output: (NOTA: il vostro programma deve riprodurre questo output)

Albero:
Altezza albero: 0
Numero nodi albero: 0
Visita preorder iterativa:

Albero:
2
Altezza albero: 0
Numero nodi albero: 1
*/
#define BTREE_H "../../../../Data Structures/btree/btree.h"
#define ITEM_H "../../../../Data Structures/btree/item.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include BTREE_H
#include ITEM_H

int *heightAndNumNodes (BTree t);
int chk_heightAndNumNodes(BTree t, int *arr);
int preorder(BTree t);

Item inputItemInt(int n);

int max(int a, int b);
void evryOutput(BTree t);
int main(){

    BTree t_1 = newTree();
    evryOutput(t_1);
    printf("\n");

    BTree t_2 = newTree();
    t_2 = buildTree(NULL,NULL,inputItemInt(2));
    evryOutput(t_2);
    printf("\n");

    BTree t_3 = newTree();
    BTree t_3_l = newTree();
    BTree t_3_r = newTree();
    BTree t_3_rl = newTree();
    BTree t_3_rr = newTree();

    t_3_rr = buildTree(NULL,NULL,inputItemInt(5));
    t_3_rl = buildTree(NULL,NULL,inputItemInt(1));
    t_3_r = buildTree(t_3_rl, t_3_rr, inputItemInt(9));
    t_3_l = buildTree(NULL,NULL, inputItemInt(3));
    t_3 = buildTree(t_3_l, t_3_r, inputItemInt(7));

    evryOutput(t_3);

    return 0;
}
void evryOutput(BTree t) {

    int *arr = heightAndNumNodes(t);
    printf("Altezza albero: %d\n", arr[1]);
    printf("Numero nodi albero: %d\n",arr[0]);
    printf("Visita preorder iterativa: ");
    preorder(t);
    printf("\n");

}


int preorder(BTree t) {


    if (isEmptyTree(t))
        return 0;

    outputItem(getBTreeRoot(t));
    printf(" ");

    preorder(getLeft(t));
    preorder(getRight(t));



}

int chk_heightAndNumNodes(BTree t, int *arr) {
    if (isEmptyTree(t))
        return 0;

    *arr +=  1;

    return 1+ max(chk_heightAndNumNodes(getLeft(t),arr), chk_heightAndNumNodes(getRight(t),arr) );


}

Item inputItemInt(int n){
    int *pt ;
    pt = malloc(sizeof(int));

    *pt = n;
    return pt;
}

int *heightAndNumNodes (BTree t) {

    Item *arr_itm = malloc(2*sizeof(Item));
    arr_itm[0] = inputItemInt(0);
    arr_itm[1] = inputItemInt(0);


    int *arr_int = malloc (sizeof(int)); //= malloc (2 *sizeof(int));
    *arr_int= 0;


    int altezza = chk_heightAndNumNodes(t, arr_int);




    int *ris_arr_int = malloc (2*sizeof(int));
    ris_arr_int[0] = *arr_int;
    ris_arr_int[1] = altezza;
    return ris_arr_int;
}

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}
