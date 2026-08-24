/*
    data una coda, cerca l'elemento piu' piccolo e spostalo alla testa della coda
        * se sono presenti + elementi minimi uguali, sposta soltanto il primo

*/


#define LIST_H "../../../../Data Structures/queue/list.h"
#define ITEM_H "../../../../Data Structures/queue/item.h"
#define QUEUE_H "../../../../Data Structures/queue/queue.h"


#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>

#include LIST_H
#include ITEM_H
#include QUEUE_H

Item inputItemString(char *s);
void mvQueueTop(Queue q, Item itm);


int main(){
    Queue q = newQueue();

    enqueue(q, inputItemString("ciao" ));
    enqueue(q, inputItemString("come" ));
    enqueue(q, inputItemString("gente" ));
    enqueue(q, inputItemString("come" ));
    enqueue(q, inputItemString("va" ));
    printf("\n");

    mvQueueTop(q, inputItemString("come"));
    printQueue(q);

	return 0;
}
Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}


void mvQueueTop(Queue q, Item itm){
    Queue tmp_q = newQueue();
    int n_flag ;
    n_flag = 0;

    Item deq;
    Item top_deq;

    while(!isEmptyQueue(q)){
        deq = dequeue(q);

        if( (cmpItem(deq, itm) == 0) && n_flag < 1  ){
           n_flag = 1;
           continue;
           }

        enqueue(tmp_q, deq) ;
    }

    while(!isEmptyQueue(tmp_q))
        enqueue(q, dequeue(tmp_q)) ;

    enqueue(q, itm) ;

    printQueue(tmp_q);
    free(tmp_q);
}