#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define DIM 30

Item inputItem(){
    char *p = malloc(DIM*sizeof(char));
    scanf("%s",p);
    return p;
}

void outputItem(Item it){
    char *p = it;
    printf("%s ",p);
}

int cmpItem(Item itA, Item itB){
    char *pA = itA;
    char *pB = itB;

    return strcmp(pA,pB);
}