/*
    implementa una funzione che rimuove un elemento dallo stack. se l'elemento e' presente piu' volte
    individua ed elimina soltanto il primo

    utilizzare i soli operatori di base dello stack
    non restituire un nuovo stack
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
Item input1(Stack s);
Stack rmItemStack(Stack s, Item itm);
int main(){
    Item itm;
	int pos;

    Stack s = newStack();

    itm = input1(s); // [ 2, 2, 3, 2 ]

//    printStack(s);
//    Stack dado = newStack();
    s =rmItemStack(s, itm);
    printStack(s);
    free(s);

	return 0;
}

Stack rmItemStack(Stack s, Item itm){
    Stack tmp_s = newStack();

    while(!isEmptyStack(s)){


        if(cmpItem(top(s), itm) == 0 ){
            pop(s) ;
            continue;
        }
        push(tmp_s, top(s));

        pop(s);
    }

    return tmp_s;

}

Item input1(Stack s){

    Item itm = inputItemInt(3) ;

    push(s,inputItemInt(3));
    push(s,inputItemInt(2));
    push(s,inputItemInt(3));
    push(s,inputItemInt(4));

    return itm;
}

Item inputItemInt(int n){

    int *p = malloc(sizeof(int));
    *p = n;
    return p;

}