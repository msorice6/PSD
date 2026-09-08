/*
    si implementi una funzione queueArrayEquals(l'ho chiamata cmpArrList) che prende in input una coda un array  e rimuove i duplicati della coda stessa
    se un elemento compare due volte va rimossa la sua seconda occorrenza
*/
#define LIST_H "../../../Data Structures/queue/list.h"
#define ITEM_H "../../../Data Structures/queue/item.h"
#define QUEUE_H "../../../Data Structures/queue/queue.h"


#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include LIST_H
#include ITEM_H
#include QUEUE_H

Item inputItemString(char *a);
void rvQueue(Queue q);
void tstRicorsione(int n);
int main(){

    Queue q = newQueue();

    enqueue(q, inputItemString("ciao")) ;
    enqueue(q, inputItemString("bella")) ;
    enqueue(q, inputItemString("gente")) ;
    enqueue(q, inputItemString("come")) ;
    enqueue(q, inputItemString("va")) ;

//    printQueue(q);
    rvQueue(q);
    printQueue(q);
//    tstRicorsione(10);

    return 0;
//    printf("rmDoubleQueue\n");
}
void tstRicorsione(int n){
    if(n<0)
        return;

    printf("ricorsione in ordine: : %d", n);
    n--;
    tstRicorsione(n);

    printf("ricorsione al contrario: : %d", n);

}
void rvQueue(Queue q) {
    if (isEmptyQueue(q)) {
        return;
    }

    Item temp = dequeue(q);

    rvQueue(q);

    enqueue(q, temp);
}

Item inputItemString(char *a){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, a);
	return pString;
}
