/*
    si implementi la funzione elementiUnivoci che ricevuto in input una lista,
    restituisce il numero di elementi univoci presenti nella lisa
*/
#define LIST_H "../../../../Data Structures/list/list.h"
#define ITEM_H "../../../../Data Structures/list/item.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include LIST_H
#include ITEM_H

void chkUniqueElList(List ul, Item el);
Item inputItemString(char *s);
int elementiUnivoci(List l);
int main(){

	List l = newList();
    addHead(l, inputItemString("bella"));
    addHead(l, inputItemString("gente"));
    addHead(l, inputItemString("bella"));
    addHead(l, inputItemString("ciao"));
    addHead(l, inputItemString("va"));
    addHead(l, inputItemString("ciao"));
    addHead(l, inputItemString("ciao"));

//    printList(l);
    printf("numero di elementi univoci presenti nella lista: %d\n", elementiUnivoci(l));
    free(l);
	return 0;
}


void chkUniqueElList(List ul, Item el){

    List tmp_ul = cloneList(ul);

    int isAdd = 0;
    while(!isEmpty(tmp_ul)){

        if( cmpItem(getHead(tmp_ul), el)  == 0 )  {
            isAdd++;
        }
        removeHead(tmp_ul) ;
    }

    if(isAdd < 1){
        addHead(ul,el);
        }


    free(tmp_ul);

}

int elementiUnivoci(List l){
    List tmp_l = cloneList(l);

    List ul = newList();;
    while(!isEmpty(tmp_l)){
        chkUniqueElList(ul, getHead(tmp_l));
        removeHead(tmp_l);
    }
    int n = sizeList(ul);
//    printList(ul);
    free(ul);
    free(tmp_l);
    return n;
}
Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}
