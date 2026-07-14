#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"
#include "queue.h"
#include "list.h"

void inputQueue1(Queue q, Item *item_array);
Item inputItemChar(char *inp );
int calcolaItemSize(Item *item_array);
int queueArrayEqualsPrint(Queue q, Item *item_array);

void listToQueue(List l, Queue q);
void queueToList(Queue q, List l);

void arrToList(Item *item_array, List l);

int cmpArrList(List al, List ql);

//Item_array* ListToArray(List l);
//List ArrayToList(Item* item_array);



int main(){
    int item_size;
    Item *item_array = malloc(sizeof(Item)*10);

    Queue q = newQueue();
    inputQueue1(q, item_array);
//    printQueue(q);
    item_size = calcolaItemSize(item_array);

    List ql = newList();
    queueToList(q, ql);
//    listToQueue(ql,q);

    List al = newList();
    arrToList(item_array, al);
//    printList(al);

//    printList(ql);
    printf("valore di ritorno cmpArrList: %d\n", cmpArrList(al, ql));

    free(q);
    free(item_array);
}
int cmpArrList(List al, List ql){
    List al2 = newList();
    al2 = cloneList(al);

    List ql2 = newList();
    ql2 = cloneList(ql);


    Item tmp_al,tmp_ql;

    while(!isEmpty(al2) && !isEmpty(ql2)){
        tmp_al = getHead(al2);
        tmp_ql = getHead(ql2);

        if( cmpItem(tmp_al, tmp_ql) != 0 ){
            return -1;
        }else{
             removeHead(al2);
             removeHead(ql2);
        }
    }



    free(al2);
    free(ql2);

    return 0;


}



void arrToList(Item *item_array, List l){
    int size = calcolaItemSize(item_array);

    for(int i = 0; i < size; i++){
       addListTail(l, item_array[i]) ;
//        printf("ciao\n");
//        outputItem(item_array[i]);
    }

}


void queueToList(Queue q, List l){
    while(!isEmptyQueue(q)){
         addListTail(l, dequeue(q));
    }

}

void listToQueue(List l, Queue q){

    while(!isEmpty(l)){
         enqueue(q,getHead(l));
    }
    printQueue(q);

}

void inputQueue1(Queue q, Item *item_array){
    enqueue (q, inputItemChar ("ciao"));
    enqueue (q, inputItemChar ("bella"));
    enqueue (q, inputItemChar ("gente"));

    free(item_array);
    *item_array = malloc(sizeof(Item)*10) ;
    item_array[0] = inputItemChar("ciao");
    item_array[1] = inputItemChar("brutta");
    item_array[2] = inputItemChar("gente");
    item_array[3] = NULL;
}

Item inputItemChar(char *inp ){
    Item item = malloc(sizeof(char));
    strcpy(item,inp);
     return item;
}
int calcolaItemSize(Item *item_array){
    int size = 0;

    while (item_array[size] != NULL) {
            size++;
    }
    return size;

}