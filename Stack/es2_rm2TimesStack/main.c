/*
    una funzione che rimuove un elemento dallo stack, e nel caso in cui l'elemento sia presente piu' volte nello stack
    individua ed elimina soltanto il prima, se non e' presente invece il programma stampa un messaggio informativo
    per l'utente
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"
#include "list.h"
Item inputItems(char* inp);
List stackTolist(Stack s);
Stack listToStack(List l);

void inputStack1(Stack s);
void inputStack2(Stack s);
void inputStack3(Stack s);

void rmItemList(List l,Stack s, Item rmItem);
int main(){
    Item rmItem;

	Stack s=newStack();
    inputStack1(s);
    rmItem = inputItems("g") ;

    List l = newList();
    l=stackTolist(s);
    printf("lista prima di essere cambiata: \n");
    printList(l);
    printf("\n");

    rmItemList(l,s, rmItem);
    printf("lista dopo  essere cambiata: \n");
    printList(l);
    printf("\n");

    printf("stack dopo essere stato cambiato: \n");
    s = listToStack(l);
    printStack(s);



	free(l);
	free(s);
	return 0;

}
void rmItemList(List l,Stack s, Item rmItem){
    int size =sizeList(l) ;

    List l2 = newList();
    l2 = cloneList(l);

   /* Dovrei fare il reverse list di l2, perche' c'e' la parte della traccia che dice di eliminare il primo elemento dello stack se ne sono due, e gli stack sono LIF)*/
    int posrm=-1;
    Item tmp;
    for(int i =0; i<size; i++){
        tmp = getHead(l2);
        if(cmpItem(rmItem, tmp) == 0){
/*
            printf("elemento: ");
            outputItem(tmp);
            printf(" simile all'elemento: ");
            outputItem(rmItem);
            printf("\n");
*/
            posrm = i;
            }

//        outputItem(tmp);
        removeHead(l2);
    }
    free(l2);
    if(posrm>=0){
    removeListPos(l, posrm);
        printf("elemento uguale in posizione %d\n", posrm);
    }else{
        printf("nessuna corrispondenza\n") ;
    }


}
Stack listToStack(List l){
    reverseList(l);
    Stack st = newStack();
    int size = sizeList(l);

    for(int i =0; i<size;i++){
        push(st, getHead(l)   );
        removeHead(l);
    }
    return st;


}

List stackTolist(Stack s){

    List l=newList();

    while(!isEmptyStack(s)) {
         addHead(l,top(s));
         pop(s);
    }



    return l;
}



Item inputItems(char* inp){
    Item itm = malloc(sizeof(char*) * 21);
    strcpy(itm,inp);
    return itm;
}

void inputStack1(Stack s){
    push(s,inputItems("s"));
    push(s,inputItems("hz"));
    push(s,inputItems("g"));
    push(s,inputItems("v"));
    push(s,inputItems("g"));
    push(s,inputItems("c"));
    push(s,inputItems("x"));
    push(s,inputItems("z"));
    push(s,inputItems("m"));

}
