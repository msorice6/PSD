/*
Esercizio 1. Sviluppare, completando il progetto fornito (Esercizio1), l'operatore dell'ADT List dueMassimo.
L'operatore deve restituire i due Item di valore massimo contenuti nella lista. La funzione restituisce un array di due elementi
(il primo elemento dell'array conterrà l'elemento massimo della lista, il secondo l'elemento dell'array conterrà l'elemento della lista più grande
se si esclude quello già inserito in prima posizione). Nota: non alterare (neanche temporaneamente), clonare o ordinare la lista.

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Testare nel main la procedura sulle seguenti liste (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):
Una lista vuota;
Una lista consistente il solo elemento: ciao
Una lista contenente due elementi: ciao mondo
Una lista contenente 7 elementi casuali. Utilizzare la funzione fornita randomItem() per creare gli Item casuali da inserire nella lista.

Usare la funzione printDueMassimo(List) per stampare una lista ed i due Item massimi.
Esempio di output: (NOTA: il vostro programma deve riprodurre questo output)

Plaintext
List prima:
dueMassimo:
List dopo:

List prima: ciao
dueMassimo: ciao
List dopo: ciao

List prima: ciao mondo
dueMassimo: mondo ciao
List dopo: ciao mondo

List prima: jbd teq qib gdj ruj zkm bwa
dueMassimo: zkm teq
List dopo: jbd teq qib gdj ruj zkm bwa
*/
#define LIST_H "../../../../Data Structures/list/list.h"
#define ITEM_H "../../../../Data Structures/list/item.h"

#include <stdio.h>
#include <stdlib.h>

#include LIST_H
#include ITEM_H

//Item inputStack(int n);
Item* dueMassimoInt(List l);
void allOutput(List l);
Item *dueMassimo(List l);
//Item chk_max

int main(){
    char *in1 = "ciao", *in2 = "mondo";
    Item i_in1 = in1, i_in2 = in2;

    char *in3 = "jbd", *in4="teq",*in5="qib",*in6="gdj",*in7="ruj",*in8="zkm",*in9="bwa";
    Item i_in3 = in3 , i_in4=in4 ,i_in5=in5 ,i_in6=in6 ,i_in7=in7 ,i_in8=in8,i_in9=in9;

/*
    List l1 = newList();
    addListTail(l1,i_in3);
    addListTail(l1,i_in4);
    addListTail(l1,i_in5);
    addListTail(l1,i_in6);
    addListTail(l1,i_in7);
    addListTail(l1,i_in8);
    addListTail(l1,i_in9);
*/
    List l1 = newList();
    allOutput(l1);
    printf("\n");

    List l2 = newList();
    addListTail(l2,i_in1);
    allOutput(l2);
    printf("\n");
//
    List l3 = newList();
    addListTail(l3,i_in1);
    addListTail(l3,i_in2);
    allOutput(l3);
    printf("\n");

    List l4 = newList();
    l4 = randomList();
    allOutput(l4);
    printf("\n");

//    List l4 = newList();
//    addListTail(l4,i_in3);
//    addListTail(l4,i_in4);
//    addListTail(l4,i_in5);
//    addListTail(l4,i_in6);
//    addListTail(l4,i_in7);
//    addListTail(l4,i_in8);
//    addListTail(l4,i_in9);
//    allOutput(l4);
//    printf("\n");


	return 0;
}

void allOutput(List l){

    printf("List prima: ");
    printList(l);
    printf("\n");

    Item *arr_itm = dueMassimo(l);

    if(arr_itm != NULL){
        printf("dueMassimo: ");
        if(arr_itm[0] != "\0")
            outputItem(arr_itm[0]);
        printf(" ");
        if(arr_itm[1] != "\0");
            outputItem(arr_itm[1]);
        printf("\n");
    }else{
        printf("dueMassimo: ");
        printf(" ");
        printf("\n");
    }

    printf("List dopo: ");
    printList(l);
    printf("\n");

}

Item *dueMassimo(List l){
    if(isEmpty(l)){
        return NULL;
    }


    int c = 0;
    int pos_flag=-1;

    Item *arr_itm = malloc(2*sizeof(Item));
    arr_itm[0] = "\0";
    arr_itm[1] = "\0";

    List tmp_l = newList();
    int flag = 0;
    Item s_l;
    while(!isEmpty(l)){
        s_l = removeHead(l);

        if(cmpItem(s_l, arr_itm[flag]) > 0 ) {
            arr_itm[flag] = s_l;
            pos_flag = c;
        }

        addHead(tmp_l,s_l);
        c++;

    }
    flag++;
      int n = sizeList(tmp_l) - 1;


    pos_flag = n - pos_flag  ;
    c=0;
    while(!isEmpty(tmp_l)){
        s_l = removeHead(tmp_l);


        if(cmpItem(s_l, arr_itm[flag]) > 0 && c != pos_flag  ) {
            arr_itm[flag] = s_l;

        }

        addHead(l,s_l);
        c++;
    }


   return arr_itm;
}