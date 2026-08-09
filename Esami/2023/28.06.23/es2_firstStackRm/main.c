/*
    implementa una funzione che rimuove un elemento dallo stack. se l'elemento e' presente piu' volte
    individua ed elimina soltanto il primo
*/

#define LIST_H "../../../../Data Structures/stack/list.h"
#define ITEM_H "../../../../Data Structures/stack/item.h"
#define STACK_H "../../../../Data Structures/stack/stack.h"

#include <stdio.h>
#include <stdlib.h>
#include ITEM_H
#include STACK_H
#include LIST_H

Item inputItemInt(int n);
void input1(Stack s);
void stackToList(Stack s, List l);
int chkItemList(List l, Item itm);
void ListToStack(List l, Stack s);
int main(){

	int pos;

    Stack s = newStack();

    input1(s); // [ 2, 2, 3, 2 ]

    List l = newList();
    stackToList(s,l);
    int isChk;

    isChk = chkItemList(l, inputItemInt(9)); // elemento che vuoi rimuovere
    printf("guarda isChk: %d", isChk);

//    printStack(s);
    printf("\n");


    ListToStack(l,s);
//    printList(l);
    if(isChk > 0)
        printStack(s);
    else
        printf("elemento non presente nello stack");

    free(l);
    free(s);
	return 0;

}

void ListToStack(List l, Stack s){
    reverseList(l);
    while( getHead(l) != NULL){
        push(s,getHead(l));
        removeHead(l);
    }
}

int chkItemList(List l, Item itm){
    int isChk = 0;
    int c = 0;
    List tmp_l= newList();
    tmp_l=cloneList(l);

    while(getHead(tmp_l) != NULL ){

        if(cmpItem(itm, getHead(tmp_l)) == 0 ){
            printf("rm pos %d\n", c);
            removeListPos(l, c) ;
            isChk++;
            break;
        }

        removeHead(tmp_l);
        c++;
    }

    return isChk;


}

void stackToList(Stack s, List l){
    Stack tmp_s = newStack();

    List tmp_l= newList();


    while(top(s) != NULL){
        addHead(l,top(s) );
        pop(s);
    }

    tmp_l=cloneList(l);
    reverseList(l);

    printf("\n\nitem: ");
    outputItem(getHead(tmp_l));
    printf("\n\n-----------\n\n");

    reverseList(l);
    free(tmp_l);

}
void input1(Stack s){

    push(s,inputItemInt(3));
    push(s,inputItemInt(2));
    push(s,inputItemInt(3));
    push(s,inputItemInt(4));

}

Item inputItemInt(int n){

    int *p = malloc(sizeof(int));
    *p = n;
    return p;

}