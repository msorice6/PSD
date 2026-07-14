#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "queue.h"

int main(){
    Queue q = newQueue();

    int *num =malloc(sizeof(int) );
    *num =6;
    Item it = num;


    Item ita = malloc(sizeof(int) );
    *(int*) ita = 7;

    enqueue(q,ita);
    enqueue(q, it);

    int *arr = malloc(sizeof(int) * 5);

    arr[0] = *(int*) ita;

    printf("eccote arr[0]: %d\n", arr[0]);


    Item *item_arr = malloc(sizeof(int) * 3);
//    free(num);
    free(ita);


     item_arr[0] =  num;
     arr[0] = *(int*) item_arr[0];
     arr[0]++;

    printf("ecco item_arr[0]: %d\n",*(int*)item_arr[0]);
    printf("ecco di nuovo arr[0]: %d",arr[0]);

    free(arr);

//    printQueue(q);



    return 0;

	}	
