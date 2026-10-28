/*


Esercizio 2: Si implementi, completando il progetto fornito (Esercizio2) una funzione sommaFoglieDestre che, dato in input un albero binario,
restituisce la somma dei valori contenuti nei nodi foglia che sono figli destri.

Un nodo n si considera foglia destra se:

n non ha figli;

n è il figlio destro del suo genitore.

Usare la ricorsione per implementare l'algoritmo. Si indichi anche, utilizzando i commenti nel codice, la complessità asintotica della funzione implementata,
fornendo una breve giustificazione sulla risposta. ATTENZIONE: leggere le note sui commenti e la compilazione nella prima pagina della traccia.

Modificare esclusivamente i file main.c e makefile, senza aggiungere o modificare gli operatori disponibili negli ADT forniti.

ATTENZIONE: la funzione non deve fare stampe.

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Testare nel main la procedura sui seguenti alberi (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):

Un albero vuoto;

Un albero consistente della sola radice contenente il numero 2;

Un albero instanziato come di seguito:

      7
     / \
    3   6
   / \
  1   5
Un primo albero casuale (richiamare newRandomTree(3) per creare l'albero casuale);

Un secondo albero casuale (richiamare newRandomTree(4) per creare l'albero casuale).

Utilizzare la funzione printTree(BTree) per stampare gli alberi e la funzione newRandomTree(int) per creare l'albero casuale (fornite dall'ADT).

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
void evryOutput(BTree t);
int main(){
    BTree t_5 = newTree();
    t_5 = newRandomTree(4) ;
    printTree(t_5);
    printf("somma nodi: %d\n", sommaFoglieDestre(t_5));
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

BTree input1(BTree t){

    BTree l = newTree();
    BTree r = newTree();

    BTree ll = newTree();
    BTree lr = newTree();

    ll = buildTree(NULL,NULL,inputItemInt(1));
    lr = buildTree(NULL,NULL, inputItemInt(5));



    r = buildTree(NULL, NULL, inputItemInt(6));
    l = buildTree(ll,lr,inputItemInt(3));


    t = buildTree(l, r, inputItemInt(7));
    return t;

}

