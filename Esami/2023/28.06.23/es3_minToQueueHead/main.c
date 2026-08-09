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

#include LIST_H
#include ITEM_H
#include QUEUE_H


Item inputItemInt(int n);
void queueToList(Queue q, List l);
void minListToTopQueue(List l, Queue q);

void listToQueue(List l, Queue q);


int main(){
    Queue q = newQueue();
    List l = newList();

    enqueue(q, inputItemInt(6));
    enqueue(q, inputItemInt(2));
    enqueue(q, inputItemInt(1));
    enqueue(q, inputItemInt(4));
    enqueue(q, inputItemInt(5));

//    printQueue(q);
    queueToList(q, l);

    minListToTopQueue(l, q);
//    printList(l);
    listToQueue(l, q);
    printQueue(q);

    free(q);
    free(l);
	return 0;
}
void minListToTopQueue(List l, Queue q){

    List tmp_l = newList();
    tmp_l = cloneList(l);

    int c=0;
    int min_pos=0;

    Item min=getHead(tmp_l);

    //trovo pos del minimo
    while(!isEmpty(tmp_l) ){

        if(cmpItem(min,getHead(tmp_l)) > 0 ){
            min=getHead(tmp_l);
            min_pos=c;
        }
        removeHead(tmp_l);
        c++;
    }
    removeListPos(l,min_pos) ;
    addListTail(l,min);


    free(tmp_l);

}
void listToQueue(List l, Queue q){
    List tmp_l=newList();

    tmp_l = cloneList(l);

    while(!isEmpty(tmp_l) ){
        enqueue(q,getHead(tmp_l));
        removeHead(tmp_l);
    }

}

void queueToList(Queue q, List l){
    List tmp_l = newList();

    while(!isEmptyQueue(q) ){
        addHead(l, dequeue(q));
    }
    reverseList(l);

    tmp_l = cloneList(l);

//restore queue
//    while(!isEmpty(tmp_l) ){
//        enqueue(q,getHead(tmp_l));
//        removeHead(tmp_l);
//    }

    free(tmp_l);
}

Item inputItemInt(int n){
    int *pInt=malloc(sizeof(int));
    *pInt = n;
    return pInt;
}
