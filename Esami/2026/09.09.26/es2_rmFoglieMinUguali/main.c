/*
Esercizio 2. Si implementi, completando il progetto fornito (Esercizio2) una funzione rimuoviFoglieMinoriUguali(BTree)
che prenda in input un albero binario ed elimini tutte le foglie che hanno un valore minore o uguale a quello del proprio padre.
La funzione deve restituire il numero totale di foglie rimosse.
Per evitare dubbi si ricorda che un nodo $n$ è una foglia minore uguale del padre:
* n non ha figli;
*il valore contenuto in $n$ è minore o uguale al valore contenuto nel padre di n.
Usare la ricorsione per implementare l'algoritmo. Si indichi anche, utilizzando i commenti nel codice,
la complessità asintotica della funzione implementata, fornendo una breve giustificazione sulla risposta.
ATTENZIONE: leggere le note sui commenti e la compilazione nella prima pagina della traccia.
IMPORTANTE: visionare operatori presenti nella versione di btree.h fornita   Modificare esclusivamente i file main.c e makefile,
senza aggiungere o modificare gli operatori disponibili negli ADT forniti.
Per scrivere un codice più pulito si consiglia di creare una funzione di supporto, da richiamare nel main per ogni albero,
che prende in input l'albero, stampa l'albero, il risultato di rimuoviFoglieMinoriUguali, quindi stampa nuovamente l'albero per verifica.
ATTENZIONE: la funzione non deve fare stampe.   ATTENZIONE: affinché l'esercizio venga valutato
è necessario che il progetto modificato compili (con il comando make o con compila.bat).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.
Testare nel main la procedura sui seguenti alberi (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):
* Un albero vuoto;
* Un albero consistente della sola radice contenente il numero 4;
* Un albero istanziato come di seguito:
       7
      / \
     3   9
    / \
   2   1
* Un primo albero casuale (richiamare newRandomTree(3) per creare l'albero casuale);
* Un secondo albero casuale (richiamare newRandomTree(4) per creare l'albero casuale).
Utilizzare la funzione printTree(BTree) per stampare gli alberi e la funzione newRandomTree(int) per creare gli alberi casuali (fornite dall'ADT).
*/

#define BTREE_H "../../../../Data Structures/btree/btree.h"
#define ITEM_H "../../../../Data Structures/btree/item.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include BTREE_H
#include ITEM_H

int rimuoviFoglieMinoriUguali_ricorsione(BTree t, int c);
int rimuoviFoglieMinoriUguali(BTree t);

int main(){

    int rad_1 = 4;
    Item i_rad_1 = &rad_1;
    BTree t_rad_1 = newTree();
    t_rad_1 = buildTree(NULL,NULL,i_rad_1);
    printTree(t_rad_1);
    printf("numero foglie minori uguali del padre: %d\n", rimuoviFoglieMinoriUguali(t_rad_1));

    printf("\n");

    int rad_2 = 7, l = 3, r = 9, ll = 2, lr = 1;
    Item i_rad_2 = &rad_2, i_l = &l, i_r = &r, i_ll = &ll, i_lr = &lr;

    BTree t_ll= newTree();
    BTree t_lr=newTree();

    BTree t_l=newTree();

    BTree t_r = newTree();
    BTree t_rad_2= newTree();

    t_ll = buildTree(NULL,NULL, i_ll);
    t_lr = buildTree(NULL,NULL, i_lr);

    t_l = buildTree(t_ll,t_lr, i_l);

    t_r = buildTree(NULL,NULL, i_r);


    t_rad_2 = buildTree(t_l,t_r, i_rad_2);

    printTree(t_rad_2);
    printf("numero foglie minori uguali del padre: %d\n", rimuoviFoglieMinoriUguali(t_rad_2));


    BTree t_rad_3 = newRandomTree(3);
    printTree(t_rad_3);
    printf("numero foglie minori uguali del padre: %d\n", rimuoviFoglieMinoriUguali(t_rad_3));

    BTree t_rad_4 = newRandomTree(4);
    printTree(t_rad_4);
    printf("numero foglie minori uguali del padre: %d\n", rimuoviFoglieMinoriUguali(t_rad_4));


	return 0;
}
int rimuoviFoglieMinoriUguali(BTree t){
    int d = 0;
    d = rimuoviFoglieMinoriUguali_ricorsione(t, 0);
    return d;

}

int rimuoviFoglieMinoriUguali_ricorsione(BTree t, int c){
    if (isEmptyTree(t))
        return 0;

    int d=0;
    BTree l = getLeft(t);
    BTree r = getRight(t);

    BTree rl = getRight(getLeft(t)); // figlio destro, padre sinistro
    BTree ll = getLeft(getLeft(t)); // figlio sinistro, padre sinistro

    BTree lr = getLeft(getRight(t)); // figlio sinistro , padre destro
    BTree rr = getRight(getRight(t)); // figlio destro, padre destro

    if(!isEmptyTree(l)){
        if(isEmptyTree(ll) && isEmptyTree(rl)){
            if(cmpItem(getBTreeRoot(l), getBTreeRoot(t) ) <= 0) {
//                setTree(l); // rimuove nodo l

//                printf("foglia: ");
//                outputItem(getBTreeRoot(l));
//                printf(" e' <= padre ");
//                outputItem(getBTreeRoot(t));
//                printf("\n");
                d++;
            }
        }
    }

    if(!isEmptyTree(r)){
        if(isEmptyTree(lr) && isEmptyTree(rr)){

            if(cmpItem(getBTreeRoot(r), getBTreeRoot(t) ) <= 0) {
//                setTree(r); // rimuove nodo r

//                printf("foglia: ");
//                outputItem(getBTreeRoot(r));
//                printf(" e' <= padre ");
//                outputItem(getBTreeRoot(t));
//                printf("\n");
                d++;
            }

        }
    }

    return d + rimuoviFoglieMinoriUguali_ricorsione(getLeft(t), c) + rimuoviFoglieMinoriUguali_ricorsione(getRight(t), c);

}
