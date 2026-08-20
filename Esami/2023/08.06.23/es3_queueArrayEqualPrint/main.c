/*
    implementi una funzione che ricevuta in input una coda
    rimuova gli elementi duplicati della coda stessa
    ( se un elemento compare due volte, va rimossa la sua seconda occorrenza )
*/
#define LIST_H "../../../../Data Structures/queue/list.h"
#define ITEM_H "../../../../Data Structures/queue/item.h"
#define QUEUE_H "../../../../Data Structures/queue/queue.h"

#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include LIST_H
#include ITEM_H
#include QUEUE_H

Item inputItemString(char *a);
void queueToList(Queue q, List l);
void rmSecondDoubleList(List l);
int main(){
    List l = newList();
    Queue q = newQueue();
    enqueue(q, inputItemString("ciao")) ;
    enqueue(q, inputItemString("bella")) ;
    enqueue(q, inputItemString("gente")) ;
    enqueue(q, inputItemString("come")) ;
    enqueue(q, inputItemString("va")) ;

    queueToList(q, l);

//    printQueue(q);
    printList(l);

    free(l);
    free(q);
    return 0;
}
void rmSecondDoubleList(List l){
    List tmp_l = cloneList(l) ;
    reverseList(tmp_l);

    searchListItem(l, Item, int *)

//    while(!isEmpty(tmp_l)){
//        removeHead(tmp_l) ;
//    }

    free(tmp_l);
}

void queueToList(Queue q, List l){

    while(!isEmptyQueue(q)){
        addHead(l, dequeue(q));
    }
    reverseList(l);
}


Item inputItemString(char *a){

	char *pString=malloc(21*sizeof(char));
	strcpy(pString, a);
	return pString;



}