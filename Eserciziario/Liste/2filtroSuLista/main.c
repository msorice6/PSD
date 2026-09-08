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
void chkDoubleChar(List l, char c);
int main(){

	List l = newList();
    addHead(l, inputItemString("casa"));
    addHead(l, inputItemString("buongiorno"));
    addHead(l, inputItemString("testo"));
    addHead(l, inputItemString("lenzuolo"));

    chkDoubleChar(l, 't');

    printList(l);
    free(l);
	return 0;
}
void chkDoubleChar(List l, char c){
    List tmp_l = cloneList(l);
    char *s = malloc(21*sizeof(char)) ;
    char firstLetter;

    while(!isEmpty(tmp_l)){

        strcpy(s,getHead(tmp_l));
        firstLetter = s[0];

        if(firstLetter == c)
            removeListItem(l,getHead(tmp_l));

        removeHead(tmp_l);
    }
    free (tmp_l);
    reverseList(l);
}


Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}
