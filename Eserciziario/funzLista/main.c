/*
    si implementi la funzione elementiUnivoci che ricevuto in input una lista,
    restituisce il numero di elementi univoci presenti nella lisa
*/
#define LIST_H "../../Data Structures/list/list.h"
#define ITEM_H "../../Data Structures/list/item.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../Data Structures/stack/list.h"

#include LIST_H
#include ITEM_H

Item inputItemString(char *s);
void chkMaxSeq(List l);
void listToList(List l, List max_seq_l);
int main(){


	List l = newList();
    addListTail(l, inputItemString("a"));
    addListTail(l, inputItemString("b"));
    addListTail(l, inputItemString("c"));
    addListTail(l, inputItemString("d"));
	addListTail(l, inputItemString("e"));

	chkMaxSeq(l);

	return 0;
}
void chkMaxSeq(List l){
	if (isEmpty(l))
		return;
	List max_seq_l = newList();
	List seq_l = newList();
	List tmp_l = newList();

	Item cmp_l_1;
	Item cmp_l_2;

	cmp_l_1 = getHead(l);
	addHead(tmp_l, cmp_l_1);
	removeHead(l);

	cmp_l_2 = getHead(l);
	addHead(tmp_l, cmp_l_2);
	removeHead(l);



	while (!isEmpty(l)) {


			if (cmpItem(cmp_l_1, cmp_l_2)<=0) {
				addListTail(seq_l, cmp_l_1);



			}if(cmpItem(cmp_l_1, cmp_l_2)>0)  {
				printf("vais!\n");

				if (sizeList(seq_l)>sizeList(max_seq_l)) {
//					listToList(seq_l,max_seq_l);
					while (!isEmpty(max_seq_l))
						removeHead(max_seq_l);



					while (!isEmpty(seq_l)) {
						addHead(max_seq_l, getHead(seq_l));
						removeHead(seq_l);
					}


				}

			}




/*
		printf("cmp_l_1: ");
		outputItem(cmp_l_1);
		printf("     cmp_l_2: ");
		outputItem(cmp_l_2);
		printf("\n");
*/
		cmp_l_1 = cmp_l_2;

		cmp_l_2 = getHead(l);


		addHead(tmp_l, cmp_l_2);
		removeHead(l);

	}


	printf("\n%d\n", sizeList(max_seq_l));
	//printList(seq_l);

	printList(max_seq_l);






}


Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}
void listToList(List seq_l, List max_seq_l) {
	while (!isEmpty(max_seq_l))
		removeHead(max_seq_l);



	while (!isEmpty(seq_l)) {
		addListTail(max_seq_l, getHead(seq_l));
		removeHead(seq_l);
	}

	printList(max_seq_l);
}
