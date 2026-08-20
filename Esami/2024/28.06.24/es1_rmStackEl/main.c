/*
    implementa una funzione che rimuove un elemento dallo stack. se l'elemento e' presente piu' volte
    individua ed elimina soltanto il primo

    Restituisce VERO se l'elemento specificato e' stato rimosso
    Restituisce FALSO se l'elemento specificato non e' presente nello stack
*/

#define LIST_H "../../../../Data Structures/stack/list.h"
#define ITEM_H "../../../../Data Structures/stack/item.h"
#define STACK_H "../../../../Data Structures/stack/stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include ITEM_H
#include STACK_H
#include LIST_H

void stackToList(Stack s, List l);
bool rmListEl(List l, Item el);
Item inputItemString(char *s);
void listToStack(List l, Stack s);
int main(){

    Stack s = newStack();
    List l = newList();

    push(s, inputItemString("come"));
    push(s, inputItemString("bella"));
    push(s, inputItemString("gente"));
    push(s, inputItemString("come"));
    push(s, inputItemString("va"));

    stackToList(s,l);

    printf(" boolean: %d \n", rmListEl(l, inputItemString("va")));
    listToStack(l,s);
//    printList(l);
    printStack(s);

    free(s);
    free(l);
	return 0;
}

void listToStack(List l, Stack s){
    reverseList(l);
    while(!isEmpty(l)) {
        push(s, getHead(l));
        removeHead(l);
    }
}

bool rmListEl(List l, Item el){
    bool isTrue = false;
    List tmp_l = cloneList(l);
    int c=0;
    while(!isEmpty(tmp_l)){
        if(cmpItem(el, getHead(tmp_l)) == 0 ){
            removeListPos(l, c);
            isTrue = true;
            break;
        }

        removeHead(tmp_l);
        c++;
    }
    free(tmp_l);
    return isTrue;
}

void stackToList(Stack s, List l){

    while(!isEmptyStack(s)){
        addHead(l,top(s));
        pop(s);
    }
    reverseList(l);
}

Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return s;
}
