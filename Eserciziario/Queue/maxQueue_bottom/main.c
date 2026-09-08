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
void reverseQueue(Queue q);
void maxBottomQueue(Queue q);
int main(){

    Queue q = newQueue();

    enqueue(q, inputItemString("ciao")) ;
    enqueue(q, inputItemString("bella")) ;
    enqueue(q, inputItemString("gente")) ;
    enqueue(q, inputItemString("come")) ;
    enqueue(q, inputItemString("va")) ;

    maxBottomQueue(q);

//    printQueue(q);
//    reverseQueue(q);
//    printQueue(q);
//    tstRicorsione(10);

    printQueue(q);
    return 0;
//    printf("rmDoubleQueue\n");
}

void maxBottomQueue(Queue q){
    Queue tmp_q = newQueue();
    Item max_item=dequeue(q);
    enqueue(tmp_q, max_item);
    Item item_to_compare;

    while(!isEmptyQueue(q)){
        item_to_compare = dequeue(q);
        if(cmpItem(max_item, item_to_compare ) < 0){
            max_item = item_to_compare;
        }
        enqueue(tmp_q, item_to_compare);
    }

    int flag_q = 0;
    while(!isEmptyQueue(tmp_q)) {
        item_to_compare = dequeue(tmp_q);

        if(cmpItem(item_to_compare, max_item) == 0)
            continue;

        enqueue(q, item_to_compare );
    }
    reverseQueue(q);
    enqueue(q, max_item);
    reverseQueue(q);

//    outputItem(item_to_compare);
}

void reverseQueue(Queue q){
    if(isEmptyQueue(q))
        return;
    Item itm = dequeue(q);
    reverseQueue(q);

    enqueue(q,itm);
}

Item inputItemString(char *a){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, a);
	return pString;
}
