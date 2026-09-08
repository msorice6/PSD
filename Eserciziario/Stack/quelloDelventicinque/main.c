/*
    implementa una funzione che rimuove un elemento dallo stack. se l'elemento e' presente piu' volte
    individua ed elimina soltanto il primo
*/

#define LIST_H "../../../Data Structures/stack/list.h"
#define ITEM_H "../../../Data Structures/stack/item.h"
#define STACK_H "../../../Data Structures/stack/stack.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include ITEM_H
#include STACK_H
#include LIST_H

Item inputItemString(char *s);
void rvStack(Stack s);
int main(){
    Stack s = newStack();
    push(s, inputItemString("ciao"));
    push(s, inputItemString("bella"));
    push(s, inputItemString("gente"));
    push(s, inputItemString("come"));
    push(s, inputItemString("va"));

    printStack(s);
    rvStack(s) ;
//    printStack(s);

	return 0;

}
Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}

void rvStack(Stack s){
    if(isEmptyStack(s)){
        return ;
    }
    Item stack_pop = top(s);
    pop(s);

    rvStack(s);
    push(s, stack_pop);





}
