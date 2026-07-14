#include <stdio.h>
#include <stdlib.h>
#include "item.h"
 
Item inputItem(){
    int* p=malloc(sizeof(int));
    scanf("%d", p);
    return p;
}

void outputItem(Item it) {
    int* pInt=it;
    printf("%d ", *pInt);
}

int cmpItem(Item it1, Item it2) {
    int* p1=it1;
    int* p2=it2;

    return *p1-*p2;
}