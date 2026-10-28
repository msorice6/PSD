/*

Esercizio 2. Si implementi, completando il progetto fornito (Esercizio2) una funzione sumTreeFL(BTree)
che prenda in input un albero binario e restituisca un intero positivo la somma dei nodi che sono padri di almeno una foglia.
Se l'albero è vuoto o contiene la sola radice, restituisce il valore 0.

Usare la ricorsione per implementare l'algoritmo. Si indichi anche, utilizzando i commenti nel codice, la complessità asintotica della funzione implementata, fornendo una breve giustificazione sulla risposta.
ATTENZIONE: leggere le note sui commenti e la compilazione nella prima pagina della traccia.

Modificare esclusivamente i file main.c e makefile, senza aggiungere o modificare gli operatori disponibili negli ADT forniti.

ATTENZIONE: la funzione non deve fare stampe.

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make o con compila.bat).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Testare nel main la procedura sui seguenti alberi (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):

Un albero vuoto;

Un albero consistente della sola radice contenente il numero 2;

Un albero istanziato come di seguito

Plaintext
    _7_
   /   \
  3     9
 / \   /
1   5 4
Un primo albero casuale (richiamare newRandomTree(3) per creare l'albero casuale);

Un secondo albero casuale (richiamare newRandomTree(4) per creare l'albero casuale).

Utilizzare la funzione printTree(BTree) per stampare gli alberi e la funzione newRandomTree(int) per creare gli alberi casuali (fornite dall'ADT).

Esempio di output: (NOTA: il vostro programma DEVE riprodurre questo output, eccetto per gli alberi casuali che devono essere differenti ad ogni esecuzione del programma)


Albero:
sumTreeFL: 0

Albero:
2

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
Item inputItemInt(int n);
int isPadreFoglia(BTree t);
void evryOutput(BTree t);
int main(){
    BTree t_1 = newTree();

    BTree t;
    t = newTree();
    t = newRandomTree(9);
    printTree(t);

    printf("ora guarda questo: \n");
    BTree l = getLeft(t) ;

//    if(!isEmptyTree(getLeft(l)) )
//        outputItem(getBTreeRoot(getLeft(l)));
//     else
//        printf("e' vuoto!\n");

    printf("somma nodi: %d \n", sumTreeFL(t));

    return 0;
}
void evryOutput(BTree t) {
   printf("\n");


}
int sumTreeFL(BTree t){
    if(isEmptyTree(t))
        return 0;

    int c=0;

    BTree l = getLeft(t) ;
    BTree r = getRight(t);

    if(!isEmptyTree(l)  ) {
        if(isEmptyTree(getLeft(l)) && isEmptyTree(getLeft(r) )  ){
           printf("padre left: ");
           outputItem(getBTreeRoot(t));
           printf("\n");
           c=1;
           }
    }

    if( !isEmptyTree(r) ){
           if(isEmptyTree(getRight(l) ) && isEmptyTree(getRight(r) ) ){
               printf("padre Right: ");
               outputItem(getBTreeRoot(t));
               printf("\n");
               c=1;
               }
    }

    return c + sumTreeFL(getLeft(t)) + sumTreeFL(getRight(t) );

}
Item inputItemInt(int n) {

    int *pInt=malloc(sizeof(int));
    *pInt=n;
    return pInt;


}
