/*

    si implementi una procedura che modifica il contenuto
    di uno stack invertendo l'ordine degli elementi in esso
    contenuti e lasciando solo gli elementi maggiori ad un
    dato elemento fornito come parametro

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "item.h"
#include "stack.h"

Item inputStack(char* );
void reverseStackOrder(Stack s);
int getStackSize(Stack s, Stack tmps);
void swapStack(Stack s, Stack s2);
int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga

    Stack s = newStack( );
    Item i;

    // elementi che inserisco nello stack
    push(s,inputStack("ciao"));
    push(s,inputStack("bella"));
    push(s,inputStack("gente"));
    push(s,inputStack("come"));
    push(s,inputStack("va"));

    char *a = "ciao"; // elemeno fornito come parametro

    reverseStackOrder(s);

    Stack tmps = newStack();

    while(!isEmptyStack(s)){

        if(strlen(top(s)) > strlen(a) ){
            push(tmps,top(s) );
        }
        pop(s);
    }

    swapStack(tmps, s);

    printf("printtmps\n");

    printStack(s);

}

Item inputStack(char *inp){
    char *a=malloc(sizeof(char)*100);
    a = inp;
    return a;
}

void reverseStackOrder(Stack s){
    Stack tmps = newStack();

    while(!isEmptyStack(s)){
        push(tmps, top(s));
        pop(s);
    }
    Stack tmps_second = newStack();

    while(!isEmptyStack(tmps)){
        push(tmps_second, top(tmps));
        pop(tmps);
    }

    while(!isEmptyStack(tmps_second)){
        push(s, top(tmps_second));
        pop(tmps_second);
    }

}





void swapStack(Stack s, Stack s2){

    while(!isEmptyStack(s)){
        push(s2, top(s));
        pop(s);
    }

}

