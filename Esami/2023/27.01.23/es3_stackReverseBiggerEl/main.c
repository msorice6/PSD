/*
    implementa una funzione che inverte l'ordine degli elementi in uno stack,
       - lascia solo gli elementi maggiori di un dato elemento fornito come parametro
       - inverte il contenuto dello stack\

       utilizza solo gli operatori dello Stack
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

Item inputItemString(char *n);
Stack maxReverseMin(Stack s, Item itm);

int main(){
    Stack s=newStack();
    push(s,inputItemString("fbj")) ;
    push(s,inputItemString("zdm")) ;
    push(s,inputItemString("d")) ;
    push(s,inputItemString("rri")) ;
    push(s,inputItemString("cjk")) ;
    push(s,inputItemString("kwi")) ;
    push(s,inputItemString("ccp")) ;
//    Item el = inputItemInt(3);

    s = maxReverseMin(s, inputItemString("dep"));
//    s = maxReverseMin(s, inputItemString("dep"));

    printStack(s);

//    outputItem(el);
//    printStack(s);
    free(s);

}

Stack maxReverseMin(Stack s, Item itm){

    Stack tmp_s = newStack();

    while(!isEmptyStack(s)){

        if(cmpItem( top(s), itm) < 0) {
            pop(s);
            continue;
        }

        push(tmp_s, top(s));
        pop(s);

    }


    // stack reverse
       while(!isEmptyStack(tmp_s)){

           push(s, top(tmp_s));
           pop(tmp_s);

       }
    free(tmp_s) ;

    return s;
}


Item inputItemString(char *s){
	char *pString=malloc(25*sizeof(char));

    strcpy(pString,s);
	return pString;

}