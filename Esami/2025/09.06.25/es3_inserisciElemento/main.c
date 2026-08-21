/*
*/

#define LIST_H "../../../../Data Structures/stack/list.h"
#define ITEM_H "../../../../Data Structures/stack/item.h"
#define STACK_H "../../../../Data Structures/stack/stack.h"

#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include ITEM_H
#include STACK_H
#include LIST_H

Item inputItemString(char *s);
int inserisciElemento(List l, Item el_ins, Item el_rif);
void stackToList(Stack s, List l);
void listToStack(List l, Stack s);

int main(){

    Stack s = newStack();
    push(s, inputItemString("ciao"));
    push(s, inputItemString("bella"));
    push(s, inputItemString("gente"));
    push(s, inputItemString("gente"));
    push(s, inputItemString("come"));
    push(s, inputItemString("va"));

//    printStack(s);
//    printf("\n");
    List l = newList();
    stackToList(s, l);

    inserisciElemento(l, inputItemString("ins"), inputItemString("gente"));
//    printList(l)  ;
    listToStack(l,s);
    printStack(s);

    free(s);
    free(l);
    return 0;
}
void listToStack(List l, Stack s){
    reverseList(l);
    while(!isEmpty(l)){
        push(s, getHead(l)) ;
        removeHead(l);
    }

}
int inserisciElemento(List l, Item el_ins, Item el_rif){
    List tmp_l = cloneList(l)  ;
    int c =0;

    while(!isEmpty(tmp_l)){

        if(cmpItem(el_rif, getHead(tmp_l) ) == 0 ){
            printf("aggiunta!\n");
            addListPos(l, el_ins, c+1);
            return 1;
        }

        removeHead(tmp_l);
        c++;
    }
    free(tmp_l) ;
    return 0;
}

void stackToList(Stack s, List l){
    while(!isEmptyStack(s)){
        addHead(l, top(s));
        pop(s) ;
    }

    reverseList(l);

}


Item inputItemString(char *s){

	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}
