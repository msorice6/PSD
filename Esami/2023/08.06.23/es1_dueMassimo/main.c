/*
    Sviluppare completando il progetto fornito, l'operatore ADT list dueMAssimo. L'operatore deve restituire i due Item  di valore massimo contenuti nella lista
    La funzione restituisce un array di due elementi ( il primo elemento dell'array conterra' l'elementom assimo della lista,
    il secondo elemento dell'array conterra' l'elemento della lista piu' grande se si esclude quello gia' inserito in prima posizione).
     nota: non alterare ( neanche temporaneamente ), clonare o ordinare la lista.

*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h" 
#include "item.h"

Item inputStack(int n);
Item* dueMassimoInt(List l);

int main(){

	int pos;

	List l = newList();
	addHead(l, inputStack(1));
	addHead(l, inputStack(4));
	addHead(l, inputStack(7));
	addHead(l, inputStack(0));
	addHead(l, inputStack(3));

	List now_l = newList();
    now_l = cloneList(l);
    reverseList(now_l);
    Item *itms = malloc((sizeof(Item) ) );

    itms = dueMassimoInt(now_l);
    outputItem(itms[0]);
    outputItem(itms[1]);

    free(now_l);
	free(l);
    free(itms);

	return 0;
}

Item* dueMassimoInt(List l){
    List tmpl = newList();
    tmpl = cloneList(l);

    int i = 0;
    int c;
    Item tmp;

    tmp = getHead(tmpl);

    while(getHead(tmpl) != NULL){

        if(cmpItem(getHead(tmpl), tmp ) > 0 ){
            tmp = getHead(tmpl);
            c = i;
        }
        removeHead(tmpl);
        i++;
    }
    Item *a = malloc(sizeof(Item));

    tmpl = cloneList(l);
    removeListPos(tmpl,c);
    Item tmp2 = getHead(tmpl);



        while(getHead(tmpl) != NULL){

            if( cmpItem(getHead(tmpl), tmp2 ) > 0 ){
                tmp2 = getHead(tmpl);
            }
            removeHead(tmpl);
        }

    a[0] = tmp;
    a[1] = tmp2;

    free(tmpl);
    return a;
}

Item inputStack(int inp){
    int *a = malloc(sizeof(int));
    *a = inp;
    return a;

}