#include <stdio.h>
#include <stdlib.h>
#include "item.h"

Item inputItem(){
    int *p;
    p = malloc(sizeof(int));
    scanf("%d",p);
    return p;
}

void outputItem(Item it){
    int *p = it;
    printf("%d ",*p);
}

int cmpItem(Item itA, Item itB){
    int *pA = itA;
    int *pB = itB;

    return *pA - *pB;
}