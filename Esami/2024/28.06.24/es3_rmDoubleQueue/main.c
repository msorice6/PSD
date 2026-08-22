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

Item inputItemString(char *a);
void queueToList(Queue q, List l);
int rmDoubleList(List l);
void listToQueue(List l, Queue q);

int main(){

    Queue q = newQueue();

    enqueue(q, inputItemString("ciao")) ;
    enqueue(q, inputItemString("bella")) ;
    enqueue(q, inputItemString("gente")) ;
    enqueue(q, inputItemString("ciao")) ;
    enqueue(q, inputItemString("gente")) ;

//    printQueue(q);

    List l = newList();
//    printQueue(q);
    queueToList(q, l);

    while(rmDoubleList(l) == 1);
    listToQueue(l,q);
//    printList(l);
    printQueue(q);
    free(q);
    free(l) ;

    return 0;
//    printf("rmDoubleQueue\n");
}

void listToQueue(List l, Queue q){
    while(!isEmpty(l)){
        enqueue(q, getHead(l)) ;
        removeHead(l);
    }
}

int rmDoubleList(List l) {
//    reverseList(l);
    List tmp_l = cloneList(l);

    List s_tmp_l = cloneList(l);
    int c =0;
    int d =0;
    while(!isEmpty(tmp_l) ){
       // if cmpitemp
       s_tmp_l = cloneList(tmp_l);
       removeHead(s_tmp_l);
//       c = 0;
       d=0;
       while(!isEmpty(s_tmp_l)){

            if( cmpItem( getHead(tmp_l), getHead(s_tmp_l) ) == 0 ){

//                printf("confronto tmp_l: ");
//                outputItem(getHead(tmp_l));
//                printf("          con s_tmp_l: ");
//                outputItem(getHead(s_tmp_l));
//                printf("con c = %d\n", d);
//                printf("\n");
                removeListPos(l, c+d+1);

                free(tmp_l);
                free(s_tmp_l);
                return 1;
            }
//                removeListItem(l,n);
            removeHead(s_tmp_l);
            d++;
        }
        removeHead(tmp_l) ;
        c++;
    }

//    reverseList(l);
    free(tmp_l) ;
    free(s_tmp_l);
    return 0;
}

void queueToList(Queue q, List l){
    while(!isEmptyQueue(q))
        addHead(l, dequeue(q)) ;

        reverseList(l);
}

Item inputItemString(char *a){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, a);
	return pString;
}
