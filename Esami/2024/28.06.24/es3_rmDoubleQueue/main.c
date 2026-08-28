/*
    si implementi una funzione queueArrayEquals(l'ho chiamata cmpArrList) che prende in input una coda un array  e rimuove i duplicati della coda stessa
    se un elemento compare due volte va rimossa la sua seconda occorrenza

    utilizzare solo gli operatori della coda
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
void cmpArrList(Queue q);

int main(){

    Queue q = newQueue();

    enqueue(q, inputItemString("ciaos")) ;
    enqueue(q, inputItemString("bella")) ;
    enqueue(q, inputItemString("gente")) ;
    enqueue(q, inputItemString("ciao")) ;
    enqueue(q, inputItemString("gente")) ;

//    printQueue(q);
    cmpArrList(q);
    free(q);

    return 0;
//    printf("rmDoubleQueue\n");
}

void cmpArrList(Queue q){
    int rm_flag = 0;
   Queue tmp_q_toScroll = newQueue();
   Queue tmp_q_toCmp = newQueue();
    int q_size =0;
    int c=0, d=0;
    Item itm_to_cmp;
    Item itm_to_scroll;

    //get the queue size
    while(!isEmptyQueue(q)){
        q_size++;
        enqueue(tmp_q_toScroll, dequeue(q));
        //scorre la queue e la sposta in tmp_q
    }

    while(!isEmptyQueue(tmp_q_toScroll)){
        enqueue(q, dequeue(tmp_q_toScroll));
        // scorre la queue e la sposta in tmp_q
    }

    for(int i = 0; i<q_size;i++) {
        c=0;
        while(!isEmptyQueue(q)){
            itm_to_scroll = dequeue(q);
//            printf("confronto i: %d, con c: %d\n",i,c);
            if(i==c){
                itm_to_cmp = itm_to_scroll;
            }

            enqueue(tmp_q_toScroll, itm_to_scroll);

            c++;
        }

        enqueue(q, dequeue(tmp_q_toScroll));
//        printf("---------------------------\n");
        while(!isEmptyQueue(tmp_q_toScroll)){
            itm_to_scroll = dequeue(tmp_q_toScroll);

//            printf("confronto itm_to_scroll: ");
//            outputItem(itm_to_scroll);
//            printf("    con itm_to_cmp: ");
//            outputItem(itm_to_cmp);
//            printf("\n");

            if(cmpItem(itm_to_scroll, itm_to_cmp) == 0 && rm_flag < 1){
                rm_flag++;
                i=q_size;
                continue;

            }

            enqueue(q, itm_to_scroll);
        }

        printf("---------------------------\n");

    }


    printQueue(q);

}

Item inputItemString(char *a){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, a);
	return pString;
}
