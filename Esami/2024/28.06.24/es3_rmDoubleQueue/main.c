/*
    si implementi una funzione queueArrayEquals(l'ho chiamata cmpArrList) che prende in input una coda un array  e rimuove i duplicati della coda stessa
    se un elemento compare due volte va rimossa la sua seconda occorrenza
*/
#define LIST_H "../../../../Data Structures/queue/list.h"
#define ITEM_H "../../../../Data Structures/queue/item.h"
#define QUEUE_H "../../../../Data Structures/queue/queue.h"


#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include LIST_H
#include ITEM_H
#include QUEUE_H

void reverseQueue(Queue q);
Item inputItemString(char *s);
int trovaDoppioni(Queue q);
void queueToQueue(Queue q, Queue tmp_q);
int scrollItemQueue(Queue q,Item itm_to_cmp);

void every_output(Queue q);
void input1(Queue q);
void input2(Queue q);
void input3(Queue q);
void input4(Queue q);

void output(Queue q);
int main(){

    Queue q = newQueue();
    input1(q);
    every_output(q);

    q = newQueue();
    input2(q);
    every_output(q);

    q = newQueue();
    input3(q);
    every_output(q);

    q = newQueue();
    input4(q);
    every_output(q);

    return 0;
}
void every_output(Queue q){
    printf("Coda originale: ");
    printQueue(q);
    printf("\nsono stati rimossi %d elementi\n", trovaDoppioni(q));
    printf("coda dopo rim.: ");
    printQueue(q);
    printf("\n");
    printf("\n");
}

void input1(Queue q){
}

void input2(Queue q){
    enqueue(q, inputItemString("ciao")) ;
}

void input3(Queue q){
    enqueue(q, inputItemString("ciao")) ;
    enqueue(q, inputItemString("bella")) ;
    enqueue(q, inputItemString("gente")) ;
    enqueue(q, inputItemString("bella")) ;
    enqueue(q, inputItemString("va")) ;
}

void input4(Queue q){
    enqueue(q, inputItemString("o")) ;
    enqueue(q, inputItemString("f")) ;
    enqueue(q, inputItemString("i")) ;
    enqueue(q, inputItemString("zk")) ;
    enqueue(q, inputItemString("d")) ;
    enqueue(q, inputItemString("e")) ;
    enqueue(q, inputItemString("e")) ;
    enqueue(q, inputItemString("t")) ;
    enqueue(q, inputItemString("e")) ;
    enqueue(q, inputItemString("k")) ;
    enqueue(q, inputItemString("f")) ;
}

int scrollItemQueue(Queue q,Item itm_to_cmp){
    Item dequeued;
    Queue tmp_q = newQueue();
    int flag = 0;
    while(!isEmptyQueue(q)){

        dequeued = dequeue(q);
        if(cmpItem(itm_to_cmp, dequeued) == 0 ) {
            flag++;
                continue;
        }
        enqueue(tmp_q, dequeued);
    }

    queueToQueue(tmp_q, q);

    return flag;
}

int trovaDoppioni(Queue q){
    if(isEmptyQueue(q))
        return 0;


    Queue tmp_q = newQueue();
    Item itm_to_cmp;
    int rmvd_items = 0;
    while(!isEmptyQueue(q)){
        itm_to_cmp = dequeue(q);
        rmvd_items+=scrollItemQueue(q,itm_to_cmp);
        enqueue(tmp_q, itm_to_cmp);
    }

    queueToQueue(tmp_q, q);
    return rmvd_items;
}

void queueToQueue(Queue q, Queue tmp_q){
    while(!isEmptyQueue(q))
        enqueue(tmp_q, dequeue(q));
}
void reverseQueue(Queue q){
    if(isEmptyQueue(q))
        return;

    Item q_itm = dequeue(q);
    reverseQueue(q);

    enqueue(q,q_itm);
}


Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString,s);
	return pString;
}
