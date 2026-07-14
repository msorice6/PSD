/*

    Si implementi, completando il progetto fornito (Esercizio3), una procedura ricorsiva che
    inverte il contenuto di una coda, lasciando solo gli elementi inferiori ad un dato elemento fornito
    come parametro (vedere esempio di output). Modificare esclusivamente il mafile main.c
    aggiungendo le funzioni necessarie e completando int main(). Utilizzare i soli operatori di base
    della coda, senza utilizzare alcuna struttura dati ausiliaria.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "queue.h"


int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga

    Queue q;
    q = newQueue();
    enqueue(q,"ciazio") ;
    enqueue(q,"i") ;
    enqueue(q,"fatti") ;
    enqueue(q,"tuoi") ;
    enqueue(q,"beato") ;


    Item *item_queue = malloc(sizeof(Item) * 5);
    for(int i = 0; i < 5; i++){
        item_queue[i] = dequeue(q);
    }

    char *arr = malloc(sizeof (char) * 4) ;

    for(int i = 0; i < 5; i++)
        arr[i] = *(char*) item_queue[i];

    arr[5] = '\0';
;
printf("contenuto array: \n");
printf("%s %s %s %s %s\n",
           (char*) item_queue[0],
           (char*) item_queue[1],
           (char*) item_queue[2],
           (char*) item_queue[3],
           (char*) item_queue[4]
           );

printf("contenuto array: \n");
for(int i = 0; i < 5; i++){
    printf("arr[%d]: %c\n", i, arr[i][0]);
}



    printQueue(q);
    free(item_queue);
    free(arr);
}

