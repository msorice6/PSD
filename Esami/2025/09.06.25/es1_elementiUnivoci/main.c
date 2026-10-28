/*
Esercizio 1. Si implementi, completando il progetto fornito (esercizio1), la funzione elementiUnivoci che ricevuto in input una lista,
restituisce il numero di elementi univoci presenti nella lista (guardare l'esempio di output se si hanno dubbi).

Si indichi anche, utilizzando i commenti nel codice, la complessità asintotica della funzione implementata, fornendo una breve giustificazione sulla risposta.
ATTENZIONE: leggere le note sui commenti e la compilazione nella prima pagina della traccia.

Modificare esclusivamente i file main.c e makefile aggiungendo le funzioni necessarie e completando int main().

ATTENZIONE: la procedura e la funzione non devono fare stampe.

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make o con compila.bat).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Testare la procedura sui seguenti esempi di lista (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):


ciao

ciao casa

ciao ciao ciao ciao

bella gente bella ciao va ciao ciao

9 item casuali (per generare gli item casuali usare randomItem() già fornita)

Esempio di output: (NOTA: il vostro programma DEVE riprodurre questo output, eccetto per l'ultimo caso che dovrà essere differente ad ogni esecuzione del programma)

Lista prima:
Elementi: 0
Elementi univoci: 0
Lista dopo :

Lista prima:         ciao
Elementi: 1
Elementi univoci: 1
Lista dopo :         ciao

Lista prima:         ciao  casa
Elementi: 2
Elementi univoci: 2
Lista dopo :         ciao  casa

Lista prima:         ciao  ciao  ciao  ciao
Elementi: 4
Elementi univoci: 1
Lista dopo :         ciao  ciao  ciao  ciao

Lista prima:         bella gente bella ciao va    ciao ciao
Elementi: 7
Elementi univoci: 4
Lista dopo :         bella gente bella ciao va    ciao ciao

*/

#define LIST_H "../../../../Data Structures/list/list.h"
#define ITEM_H "../../../../Data Structures/list/item.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include LIST_H
#include ITEM_H

int elementiUnivoci(List l);
int chk_elementiUnivoci(List l, Item chk_el);
void listToArray(List l, Item *arr);
void arrayToList(Item *arr, List l);


Item inputItemString(char *s);

void everyoutput(List l);

int main(){
	List l_1 = newList();
    everyoutput(l_1);
    printf("\n");

    List l_2 = newList();
    addListTail(l_2, inputItemString("ciao"))  ;
    everyoutput(l_2);
    printf("\n");

    List l_3 = newList();
    addListTail(l_3, inputItemString("ciao"))  ;
    addListTail(l_3, inputItemString("casa"))  ;
    everyoutput(l_3);
    printf("\n");

    List l_4 = newList();
    addListTail(l_4, inputItemString("ciao"))  ;
    addListTail(l_4, inputItemString("ciao"))  ;
    addListTail(l_4, inputItemString("ciao"))  ;
    addListTail(l_4, inputItemString("ciao"))  ;
    everyoutput(l_4);
    printf("\n");

    List l_5 = newList();
    addListTail(l_5, inputItemString("bella"))  ;
    addListTail(l_5, inputItemString("gente"))  ;
    addListTail(l_5, inputItemString("bella"))  ;
    addListTail(l_5, inputItemString("ciao"))  ;
    addListTail(l_5, inputItemString("va"))  ;
    addListTail(l_5, inputItemString("ciao"))  ;
    addListTail(l_5, inputItemString("ciao"))  ;
    everyoutput(l_5);
    printf("\n");

    List l_6 = newList();
    addListTail(l_6, inputItemString("z"))  ;
    addListTail(l_6, inputItemString("i"))  ;
    addListTail(l_6, inputItemString("z"))  ;
    addListTail(l_6, inputItemString("t"))  ;
    addListTail(l_6, inputItemString("x"))  ;
    addListTail(l_6, inputItemString("m"))  ;
    addListTail(l_6, inputItemString("i"))  ;
    addListTail(l_6, inputItemString("f"))  ;
    addListTail(l_6, inputItemString("r"))  ;
    everyoutput(l_6);
    printf("\n");

	return 0;
}

void everyoutput(List l){
    printf("Lista prima: ");
    printList(l);
    printf("\n");
    printf("Elementi: %d\n", sizeList(l));
    printf("Elementi univoci: %d\n",elementiUnivoci(l));
    printf("Lista dopo: ");
    printList(l);

    printf("\n");

}


void listToArray(List l, Item *arr) {
    int n_list = sizeList(l);

    for (int i = 0; i < n_list; i++) {
        arr[i] = getHead(l);
        removeHead(l);
    }

    //ripristino la lista
    for (int i = 0; i < n_list; i++)
        addListTail(l,arr[i]);
}
int chk_elementiUnivoci(List l, Item chk_el) {
    int chk_contaUnivoci =0;
    Item cmp_el;
    List tmp_l = newList();

    cmp_el = getHead(l);
    addHead(tmp_l, cmp_el);
    removeHead(l);

    while (!isEmpty(l)) {
        cmp_el = getHead(l);

//        printf("confronto: ") ;
//        outputItem(chk_el);
//        printf("         con: ");
//        outputItem(cmp_el);
//        printf("\n");


        if (cmpItem(chk_el, cmp_el) == 0) {
            chk_contaUnivoci++;
            removeHead(l);
            continue;
        }
        addHead(tmp_l,cmp_el);
        removeHead(l);

    }


    while (!isEmpty(tmp_l)) {
        cmp_el = getHead(tmp_l);
        addHead(l,cmp_el);
        removeHead(tmp_l);

    }
    return chk_contaUnivoci;

}
int elementiUnivoci(List l){
    int contaUnivoci = 0;
    int n_list = sizeList(l);
    Item *arr = malloc(n_list * sizeof(Item)) ;
    listToArray(l,arr);

    Item cmp_el;
    List tmp_l = newList();
    while (!isEmpty(l)) {
        cmp_el = getHead(l);
        chk_elementiUnivoci(l, cmp_el);
        addHead(tmp_l,cmp_el);
        removeHead(l);

    }

    contaUnivoci = sizeList(tmp_l);

    for (int i = 0; i<n_list; i++)
        addListTail(l, arr[i]) ;

//    while (!isEmpty(tmp_l)) {
//        cmp_el = getHead(tmp_l);
//        addHead(l,cmp_el);
//        removeHead(tmp_l);
//    }

//    for (int i = 0; i < n_list; i++) {
//        printf("list el: ");
//        outputItem(arr[i]);
//        printf("\n");
//    }



    return contaUnivoci;
}


Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}

