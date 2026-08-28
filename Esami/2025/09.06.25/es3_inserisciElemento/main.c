/*
    implementa funzione inserisciElemento che ricevuti in unput uno stack, un elemento da inserire, e un elemento di riferimento
    inserisca l'elemento da inserire subito dopo la prima occorrenza dell'elemento di riferimento partendo dalla base dello stack
    quindi l'elemento piu' vicino alla cima dello stack rispetto all'elemento di riferimento

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
int inserisciElemento(Stack s, Item el_ins, Item el_rif);
Stack reverseStack(Stack s);

int main(){

    Stack s = newStack();
    push(s, inputItemString("ciao"));
    push(s, inputItemString("bella"));
    push(s, inputItemString("gente"));
    push(s, inputItemString("gente"));
    push(s, inputItemString("come"));
    push(s, inputItemString("va"));

    s = reverseStack(s);

    inserisciElemento(s, inputItemString("cappio"), inputItemString("come") );
//    printStack(s);

    return 0;
}

int inserisciElemento(Stack s, Item el_ins, Item el_rif){
    Stack tmp_s = newStack();
    while(!isEmptyStack(s)){

        if(cmpItem(top(s), el_rif) == 0){
            push(tmp_s, top(s));
            push(tmp_s, el_ins);
            pop(s);
            continue;
        }

        push(tmp_s, top(s));
        pop(s);

    }

    while(!isEmptyStack(tmp_s)){
         push(s, top(tmp_s));
         pop(tmp_s);
    }

    printStack(s);

    return 0;
}


Stack reverseStack(Stack s){

    Stack tmp_s = newStack();

    while(!isEmptyStack(s)){

        push(tmp_s, top(s));
        pop(s);
    }

    return tmp_s;
}
Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}
