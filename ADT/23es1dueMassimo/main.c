/*
    dueMassimo, deve restituire i due item di valore massimo
    contenuti nella lista, la funzione restituisce un array di due elementi

    * il primo elemento dell'array corterra' l'elemento massimo della lista

    * il secondo elemento dell'array conterra' l'elemento della lista piu' grande
    se si esclude quello gia' inserito in prima posizione
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "list.h"
Item inputItemInt(int inp);
Item inputItemString(char* inp);

int main(){
    List l;
    l = newList();

//    char *n = malloc(sizeof(char) * 20 );
//    strcpy(n,"ciao");
//    Item itm = n;
//    addHead(l,itm);

    Item *item_list=malloc(sizeof(Item) * 10);


    addListTail(l,item_list[0]=inputItemString("jbd"));
    addListTail(l,item_list[1]=inputItemString("teq"));
    addListTail(l,item_list[2]=inputItemString("qbb"));
    addListTail(l,item_list[3]=inputItemString("gdj"));
    addListTail(l,item_list[4]=inputItemString("ruj"));
    addListTail(l,item_list[5]=inputItemString("nkm"));
    addListTail(l,item_list[6]=inputItemString("bne"));

//    printList(l);

    outputItem(item_list[3]);

    return 0;
}



Item inputItemString(char* inp){
    char *p = malloc(sizeof(char)*10);
    strcpy(p,inp);
    return p;
}

Item inputItemInt(int inp){
    int *n = malloc(sizeof(int));
    *n=inp;
    return n;
}
