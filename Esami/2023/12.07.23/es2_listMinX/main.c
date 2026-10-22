/*
Esercizio 2. Sviluppare, completando il progetto fornito (Esercizio2) una funzione che, data una lista ed un elemento x,
modifichi la lista in modo che tutti gli elementi minori di x siano nella parte inziale della lista (mantenendo tra loro lo stesso ordine originale)
e gli elementi maggiori o uguali di x siano nella parte finale della lista (mantenendo tra loro lo stesso ordine originale).
Modificare esclusivamente il file main.c (completando le funzioni già presenti ed aggiungendone altre se necessario) ed il makefile,
senza aggiungere o modificare altri file. Nota: non ordinare o clonare la lista.

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Testare nel main la procedura sui seguenti elemento x/lista (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):

Elemento x: "ciao"; Lista: lista_vuota

Elemento x: "ciao"; Lista: "ciao"

Elemento x: "ciao"; Lista: "ciao", "casa"

Elemento x: "ciao"; Lista: "bella", "gente", "bella", "va", "ciao"

Elemento x: item_casuale; Lista: 7 item causali

(per generare gli item casuali usare randomItem() già fornita)

Esempio di output: (NOTA: il vostro programma DEVE riprodurre questo output, eccetto per la lista e l'elemento causali che dovranno essere differenti
ad ogni esecuzione del programma)

List prima:
Elemento x: ciao
List dopo :

List prima: ciao
Elemento x: ciao
List dopo : ciao

List prima: ciao  casa
Elemento x: ciao
List dopo : casa  ciao

List prima: bella gente bella va      ciao
Elemento x: ciao
List dopo : bella bella gente va      ciao

List prima: u     i     x     v     d     v     a
Elemento x: f
List dopo : d     a     u     i     x     v     v
*/

#define LIST_H "../../../../Data Structures/list/list.h"
#define ITEM_H "../../../../Data Structures/list/item.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include LIST_H
#include ITEM_H

Item inputItemString(char *s);
void listMinX(List l, Item x);
void evryOutput(List l, Item x);

int main(){
	/*
    List l_1 = newList();

    addListTail(l_1,inputItemString("u"));
	addListTail(l_1,inputItemString("i"));
	addListTail(l_1,inputItemString("x"));
	addListTail(l_1,inputItemString("v"));
	addListTail(l_1,inputItemString("d"));
	addListTail(l_1,inputItemString("v"));
	addListTail(l_1,inputItemString("a"));


	Item itm_in_1 = inputItemString("f");
*/
	List l_1 = newList();
	Item x_1 = inputItemString("ciao");
	evryOutput(l_1, x_1);
	printf("\n");

	List l_2 = newList();
	addListTail(l_2,inputItemString("ciao"));
	Item x_2 = inputItemString("ciao");
	evryOutput(l_2, x_2);
	printf("\n");

	List l_3 = newList();
	addListTail(l_3,inputItemString("ciao"));
	addListTail(l_3,inputItemString("casa"));
	Item x_3 = inputItemString("ciao");
	evryOutput(l_3, x_3);
	printf("\n");

	List l_4 = newList();
	addListTail(l_4,inputItemString("ciao"));
	addListTail(l_4,inputItemString("bella"));
	addListTail(l_4,inputItemString("gente"));
	addListTail(l_4,inputItemString("bella"));
	addListTail(l_4,inputItemString("va"));
	addListTail(l_4,inputItemString("ciao"));
	Item x_4 = inputItemString("ciao");
	evryOutput(l_4, x_4);
	printf("\n");

	/*
	List l_5 = newList();
	addListTail(l_5,randomItem());
	addListTail(l_5,randomItem());
	addListTail(l_5,randomItem());
	addListTail(l_5,randomItem());
	addListTail(l_5,randomItem());
	addListTail(l_5,randomItem());
	addListTail(l_5,randomItem());

	Item x_5 = inputItemString("ciao");
	evryOutput(l_5, x_5);
	printf("\n");
*/
	return 0;
}

void evryOutput(List l, Item x){
	printf("List prima: ");
	printList(l);
	printf("\n");

	printf("Elemento x: ");
	outputItem(x);
	printf("\n");

	listMinX(l,x);
	printf("List dopo: ");
	printList(l);
	printf("\n");

}

void listMinX(List l, Item x) {
	if (isEmpty(l))
		return;

	List tmp_l = newList();
	Item itm_to_cmp;


	while (!isEmpty(l)) {
		itm_to_cmp = getHead(l);
		if (cmpItem(itm_to_cmp, x) >= 0)
			addHead(tmp_l, itm_to_cmp);
		else
			addListTail(tmp_l, itm_to_cmp);

		removeHead(l);
	}


	while (!isEmpty(tmp_l)) {
//		printf("Item: ");
//		outputItem(getHead(tmp_l));
//		printf("\n-----------------\n");

		addHead(l, getHead(tmp_l));
		removeHead(tmp_l);

	}


}

Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;

}