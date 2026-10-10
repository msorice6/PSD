/*
Esercizio 3. Si implementi, completando il progetto fornito (Esercizio3), una funzione queueArrayEquals
che prende in input una coda, un array, il numero di elementi dell'array e restituisce
vero se coda ed array sono uguali,
falso altrimenti.

Al termine dell'esecuzione della funzione la coda originale deve risultare ancora composta degli stessi elementi.
Modificare esclusivamente i file main.c e makefile aggiungendo la/le funzione/i e completando le funzioni main e queueArrayEqualsPrint.
queueArrayEqualsPrint è una funzione che stampa la coda, l'array, il risultato di queueArrayEquals, quindi
stampa nuovamente la coda e l'array per verifica.   Nel main richiamate la funzione queueArrayEqualsPrint (invece che queueArrayEquals)
in modo da scrivere un codice più compatto.
Testare la procedura sui seguenti coda - array (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):

Coda: coda_vuota;
Array: array vuoto

Coda: "ciao";
Array: "ciao"

Coda: "ciao";
Array: "ciao", "bella"

Coda: "ciao", "bella";
Array: "ciao", "bella"

Coda: "ciao", "bella", "gente";
Array: "ciao", "brutta", "gente"

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.
 Esempio di output:

Coda (prima):
Array (prima):
Confronto coda e array: uguali
Coda (dopo):
Array (dopo):

Coda (prima):     ciao
Array (prima):    ciao
Confronto coda e array: uguali
Coda (dopo):      ciao
Array (dopo):     ciao

Coda (prima):     ciao
Array (prima):    ciao bella
Confronto coda e array: diversi
Coda (dopo):      ciao
Array (dopo):     ciao bella

Coda (prima):     ciao bella
Array (prima):    ciao bella
Confronto coda e array: uguali
Coda (dopo):      ciao bella
Array (dopo):     ciao bella

Coda (prima):     ciao bella gente
Array (prima):    ciao brutta    gente
Confronto coda e array: diversi
Coda (dopo):      ciao bella gente
Array (dopo):     ciao brutta    gente
*/

// #define LIST_H "../../../../Data Structures/queue/list.h"
#define ITEM_H "../../../../Data Structures/queue/item.h"
#define QUEUE_H "../../../../Data Structures/queue/queue.h"

#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

// #include LIST_H
#include ITEM_H
#include QUEUE_H
Item inputItemString(char *a);
int queueArrayEquals(Queue q, Item* arr, int n_arr);
void allOutput(Queue q, Item *arr, int n_arr);
int main(){

//  INPUT 1
    Queue q_1 = newQueue();

    Item *arr_1;
    int n_arr_1 = 0;

    allOutput(q_1, arr_1, n_arr_1);
    printf("\n\n");

// INPUT 2
    Queue q_2 = newQueue();
    enqueue(q_2, inputItemString("ciao")) ;

    int n_arr_2 = 1;
    Item *arr_2 = malloc(n_arr_2 * sizeof(Item));
    arr_2[0] = inputItemString("ciao");

    allOutput(q_2, arr_2, n_arr_2);
    printf("\n\n");

// INPUT 3
    Queue q_3 = newQueue();
    enqueue(q_3, inputItemString("ciao")) ;

    int n_arr_3 = 2;
    Item *arr_3 = malloc(n_arr_3 * sizeof(Item));
    arr_3[0] = inputItemString("ciao");
    arr_3[1] = inputItemString("bella");


    allOutput(q_3, arr_3, n_arr_3);
    printf("\n\n");

// INPUT 4
    Queue q_4 = newQueue();
    enqueue(q_4, inputItemString("ciao")) ;
    enqueue(q_4, inputItemString("bella")) ;
    enqueue(q_4, inputItemString("gente")) ;

    int n_arr_4 = 3;
    Item *arr_4 = malloc(n_arr_3 * sizeof(Item));
    arr_4[0] = inputItemString("ciao");
    arr_4[1] = inputItemString("brutta");
    arr_4[2] = inputItemString("gente");

    allOutput(q_4, arr_4, n_arr_4);
    printf("\n\n");

    return 0;
}

void allOutput(Queue q, Item *arr, int n_arr){
    int flag;

    printf("Coda (prima): ");

    if(!isEmptyQueue(q))
        printQueue(q);
    else
        printf("coda_vuota");

    printf("\n");

    printf("Array (prima): ");

    if(n_arr>0)
        for(int i = 0; i<n_arr; i++){
            outputItem(arr[i]);
            printf(" ");
        }
    else
        printf("array_vuoto");

    printf("\n");
    printf("Confronto coda e array: ");

    flag =queueArrayEquals(q,arr,n_arr) ;

    if (flag == 0 )
        printf("FALSO!\n");
    if (flag == 1)
        printf("VERO!\n") ;
    if ( flag == -1)
        printf(" ");


    printf("Coda (dopo): ");

    if(!isEmptyQueue(q))
        printQueue(q);
    else
        printf("coda_vuota");

    printf("\n");

    printf("Array (dopo): ");

    if(n_arr>0)
        for(int i = 0; i<n_arr; i++){
            outputItem(arr[i]);
            printf(" ");
        }
    else
        printf("array_vuoto");

}

int queueArrayEquals(Queue q, Item* arr, int n_arr){

    if(isEmptyQueue(q) && n_arr == 0)
        return 1;

    if(isEmptyQueue(q))
        return 0;

    if(n_arr == 0)
        return 0;

    Queue tmp_q = newQueue();
    int n_q=0, flag = 0;

    Item c_q;
    while(!isEmptyQueue(q)){
        c_q = dequeue(q);
        enqueue(tmp_q, c_q );
        n_q++;
    }
    if(n_q == n_arr)
        flag = 1;

    int c = 0;

    while(!isEmptyQueue(tmp_q)){
        c_q = dequeue(tmp_q);

    if(flag == 1)
        if(cmpItem(c_q, arr[c]) != 0 )
            flag = 0;

        enqueue(q, c_q );
        c++;
    }

    return flag;
}

Item inputItemString(char *a){

	char *pString=malloc(21*sizeof(char));
	strcpy(pString, a);
	return pString;

}