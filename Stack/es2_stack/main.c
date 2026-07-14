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

Item inputStack(int);
Stack reverseStack(Stack s);
int* selectionSort(Item* arr, int n );


int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga

    Stack s = newStack( );
    Item stack_items[MAXSTACK];

    // elementi che inserisco nello stack
    push(s,inputStack(7));
    push(s,inputStack(4));
    push(s,inputStack(5));
    push(s,inputStack(2));
    push(s,inputStack(3));

    reverseStack(s);

    int n=0;
    while(!isEmptyStack(s)){
        stack_items[n] = top(s);
        pop(s);
        n++;
    }

//    int *daz = (int*) stack_items[0];
//    (*daz)++;
//    printf("\nteccate daz: %d\n", *daz);

    int *arr = selectionSort(stack_items, n);


    printf("\n");
    for(int i = 0; i < n ; i++){
        int *new_item = malloc(sizeof(int));
        *new_item = arr[i];
        stack_items[i] = new_item;
        push(s, stack_items[i]);
    }

    printf("preparati a ricevere gli items: \n");
    for(int i = 0; i<n;i++){
        outputItemint(stack_items[i]);
    }



    return 0;
}

int* selectionSort(Item* item, int n ){
    int *arr = malloc(sizeof(int) * n);


    for(int i = 0; i<n; i++){
        arr[i] = *(int*) item[i];
    }



    int j,tmp;
    for(int i = 1;i<n;i++){
        tmp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > tmp){
            arr[j+1] = arr[j];

            j--;
        }
        arr[j+1] = tmp;
    }


    return arr;


}

Item inputStack(int inp){
    int *a=malloc(sizeof(int));
    *a = inp;
    return a;
}

Stack reverseStack(Stack s){
    Stack tmp_stack=newStack();

    while(!isEmptyStack(s)){
         push(tmp_stack, top(s));
         pop(s);
    }

    Stack tmp_stack2=newStack();
    while(!isEmptyStack(tmp_stack)){
            push(tmp_stack2, top(tmp_stack));
            pop(tmp_stack);
    }

    while(!isEmptyStack(tmp_stack2)){
            push(s, top(tmp_stack2));
            pop(tmp_stack2);

    }
    free(tmp_stack);
    free(tmp_stack2);

    return s;
}


