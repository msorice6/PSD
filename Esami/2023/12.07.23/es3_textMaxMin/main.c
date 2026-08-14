/*
    Scrivere una funzione testMaxMin che calcoli il valore
    massimo contenuto in uno stack e il valore minimo contenuto
    in una coda e restituisca:
     - 1 se questi sono uguali
     - 0 altrimenti

    ATTENZIONE: non alterare il contenuto dello stack e della coda
*/
#define LIST_H "../../../../Data Structures/queue/list.h"
#define ITEM_H "../../../../Data Structures/queue/item.h"
#define QUEUE_H "../../../../Data Structures/queue/queue.h"
#define STACK_H "../../../../Data Structures/stack/stack.h"

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include LIST_H
#include ITEM_H
#include QUEUE_H
#include STACK_H

Item inputItemInt(int n);
void queue_to_List(Queue q, List l_q);
void stack_to_List(Stack s, List l_s);
Item chk_s_min(List l_s);
int testMaxMin();
int main(){

    Stack s=newStack();
    Queue q = newQueue();

    push(s, inputItemInt(3));
    push(s, inputItemInt(4));
    push(s, inputItemInt(2));

    enqueue(q, inputItemInt(6)) ;
    enqueue(q, inputItemInt(0)) ;
    enqueue(q, inputItemInt(2)) ;


    List l_q = newList();
    List l_s = newList();

    queue_to_List(q, l_q);
    stack_to_List(s,l_s);

    printf("ritorno: %d ",testMaxMin(l_s, l_q));

    free(l_q);
    free(l_s);
    free(s);
    free(q);

    return 0;
}
int testMaxMin(List l_s, List l_q){
    if(cmpItem(chk_s_min(l_s), chk_s_min(l_q)) == 0 )
        return 1;
    else
        return 0;
}

Item chk_s_min(List l_s){

    List tmp_l = newList();
    tmp_l = cloneList(l_s);

    Item min;
    min = getHead(tmp_l);
    removeHead(tmp_l);
    while(!isEmpty(tmp_l)) {
        if(cmpItem(min, getHead(tmp_l)) > 0 ){
            min = getHead(tmp_l);
            }
        removeHead(tmp_l);
    }


    free(tmp_l);
    return min;
}
void stack_to_List(Stack s, List l_s){
    while(!isEmptyStack(s)){
        addHead(l_s, top(s));
        pop(s);
    }

    // restore stack:
    List tmp_l = newList();
    tmp_l = cloneList(l_s);
    reverseList(tmp_l);
    while(!isEmpty(tmp_l)){
        push(s,getHead(tmp_l));
        removeHead(tmp_l);
    }
    free(tmp_l);


}

void queue_to_List(Queue q, List l_q){
    while(!isEmptyQueue(q)){
       addHead(l_q, dequeue(q)) ;

    }
    reverseList(l_q);

    // restore queue:
    List tmp_l = newList();
    tmp_l = cloneList(l_q);

    while(!isEmpty(tmp_l)){
        enqueue(q,getHead(tmp_l));
        removeHead(tmp_l);
    }

    free(tmp_l);

}

Item inputItemInt(int n){
	int *pInt=malloc(sizeof(int));
	*pInt=n;
	return pInt;
}