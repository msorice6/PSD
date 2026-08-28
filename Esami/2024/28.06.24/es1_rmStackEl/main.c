/*
    implementa una funzione che rimuove un elemento dallo stack. se l'elemento e' presente piu' volte
    individua ed elimina soltanto il primo

    Restituisce VERO se l'elemento specificato e' stato rimosso
    Restituisce FALSO se l'elemento specificato non e' presente nello stack

    utilizzare i soli operatori dello stack
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

Item inputItemString(char *s);
Stack reverseStack(Stack s);
int isStackrm(Stack s, Item rm_itm);

int main(){

    Stack s = newStack();

    push(s, inputItemString("come"));
    push(s, inputItemString("bella"));
    push(s, inputItemString("gente"));
    push(s, inputItemString("come"));
    push(s, inputItemString("bella"));
    push(s, inputItemString("va"));
    Item in_Itm = inputItemString("bella");

    s=reverseStack(s);
    printf("Stack originale: ");
    printStack(s);
    printf("\n");
    printf("elemento da rimuovere: ");
    outputItem(in_Itm);
    printf("\n");

//    isStackrm(s,in_Itm);
    if(isStackrm(s,in_Itm))
        printf("elemento presente\n");
    else
        printf("elemento non presente\n");

    printStack(s);

    free(s);
	return 0;
}
Stack reverseStack(Stack s){

    Stack tmp_s = newStack();

    while(!isEmptyStack(s)){

        push(tmp_s,top(s)) ;
        pop(s);
    }

    return tmp_s;
}

int isStackrm(Stack s,Item rm_itm){

    Stack tmp_s = newStack();
    int is_rm_flag = 0;

    while(!isEmptyStack(s)){

        if( (cmpItem(rm_itm, top(s)) == 0) && (is_rm_flag == 0 ) )  {
            is_rm_flag = 1;
            pop(s);
            continue;
        }
        push(tmp_s, top(s));
        pop(s);
    }

    while(!isEmptyStack(tmp_s))  {
        push(s, top(tmp_s));
        pop(tmp_s) ;
    }
    free(tmp_s);

    if(is_rm_flag > 0)
        return 1;

    return 0;
}

Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return s;
}
