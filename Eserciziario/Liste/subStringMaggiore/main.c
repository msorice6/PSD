/*
    si implementi la funzione elementiUnivoci che ricevuto in input una lista,
    restituisce il numero di elementi univoci presenti nella lisa
*/
#define LIST_H "../../../Data Structures/list/list.h"
#define ITEM_H "../../../Data Structures/list/item.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include LIST_H
#include ITEM_H

Item inputItemString(char *s);
List listaPiuLunga(List l);
int main(){

	List l = newList();
    addHead(l, inputItemString("a"));
    addHead(l, inputItemString("b"));
    addHead(l, inputItemString("c"));
    addHead(l, inputItemString("a"));
    addHead(l, inputItemString("b"));
    addHead(l, inputItemString("a"));

    listaPiuLunga(l);


    printList(l);
    free(l);
	return 0;
}


List listaPiuLunga(List l){
    List tmp_l =cloneList(l);

    List longList = newList();
    Item tmp_l_compare = removeHead(tmp_l);
    Item tmp_l_compare_next = removeHead(tmp_l);

    while(!isEmpty(tmp_l)) {
        if(cmpItem(tmp_l_compare, tmp_l_compare_next) < 0){
            addHead(longList, tmp_l_compare);

            tmp_l_compare = removeHead(tmp_l);
            tmp_l_compare_next = removeHead(tmp_l);
            addHead(longList, tmp_l_compare);
            continue;
        }

        longList = newList();

    }
    printList(longList);
}


Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}
