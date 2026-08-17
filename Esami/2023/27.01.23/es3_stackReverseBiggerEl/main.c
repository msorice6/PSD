/*
    implementa una funzione che inverte l'ordine degli elementi in uno stack,
       - lascia solo gli elementi maggiori di un dato elemento fornito come parametro
       - inverte il contenuto dello stack
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
void stackToList(Stack s, List l);
void maxReverseMin(List s, Item itm);

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
    List l = newList();
    stackToList(s,l);

    maxReverseMin(l, inputItemString("dep"));
    printList(l);

//    outputItem(el);
//    printStack(s);
    free(l);


}
void maxReverseMin(List l, Item itm){
    List tmp_l = newList();
    tmp_l = cloneList(l);

    while(!isEmpty(tmp_l)){
         if(cmpItem(itm, getHead(tmp_l) ) > 0 )
            removeListItem(l, getHead(tmp_l));

        removeHead(tmp_l) ;
    }


    free(tmp_l);
}

void stackToList(Stack s, List l){

    while(!isEmptyStack(s)) {
         addHead(l, top(s) );
         pop(s);
    }

}
Item inputItemString(char *s){
	char *pString=malloc(25*sizeof(char));

    strcpy(pString,s);
	return pString;


}