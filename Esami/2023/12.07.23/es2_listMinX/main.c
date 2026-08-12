/*
    data una lista ed un elemento x, modifica la lista in modo che tutti
    gli elementi minori di x siano nella parte iniziale della lista e gli
    elementi magiori o uguali di x siano nella parte finale della lista
*/

#define LIST_H "../../../../Data Structures/list/list.h"
#define ITEM_H "../../../../Data Structures/list/item.h"

#include <stdio.h>
#include <stdlib.h>

#include LIST_H
#include ITEM_H

int *inputItemInt(int n);
List mvMinAndMax(List l, Item x);

int main(){
    List l = newList();
    addHead(l,inputItemInt(5));
    addHead(l,inputItemInt(4));
    addHead(l,inputItemInt(3));
    addHead(l,inputItemInt(2));
    addHead(l,inputItemInt(1));
    addHead(l,inputItemInt(9));

    printList(mvMinAndMax(l, inputItemInt(5)));

	return 0;
}
List mvMinAndMax(List l, Item x){

    List tmp_l = newList();

    reverseList(l);
    printf("\n");

    int c=0;
    int n=0;

    while(!isEmpty(l)){
        if(cmpItem(getHead(l), x) <= 0 ) {
            addHead(tmp_l,getHead(l));
            n++;
        }

        if(cmpItem(getHead(l), x) > 0 ) {
            addListTail(tmp_l,getHead(l));
            n++;
        }

        removeHead(l);
        c++;
    }


    while(!isEmpty(tmp_l)){

        addHead(l,getHead(tmp_l));
        removeHead(tmp_l);

    }
    reverseList(l);

    return l;

}

int *inputItemInt(int n){
	int *pInt=malloc(sizeof(int));
	*pInt = n;
	return pInt;

}