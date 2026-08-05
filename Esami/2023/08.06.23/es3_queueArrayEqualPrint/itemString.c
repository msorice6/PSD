#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define DIM 20

Item inputItem() {
    char* p=malloc(DIM*sizeof(char));
    scanf("%s", p);
    return p;
}

void outputItem(Item it) {
    char* p=it;
    printf("%s ", p);
}

int cmpItem(Item it1, Item it2) {
    char* p1=it1;
    char* p2=it2;
    return (strcmp(p1, p2));
}