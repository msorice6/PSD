/*
Esercizio 3. Si implementi, completando il progetto fornito (Esercizio3), una procedura che modifica il contenuto di uno stack
invertendo l'ordine degli elementi in esso contenuti, e lasciando solo gli elementi maggiori
ad un dato elemento fornito come parametro (vedere esempio di output).
Modificare esclusivamentei i file main.c e makefile aggiungendo le funzioni necessarie e completando int main().
Utilizzare i soli operatori di base dello stack (non modificare stack.c e stack.h). Non restituire un nuovo stack.

Testare la procedura sui seguenti parametro/stack (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):

Parametro: "ciao"; Stack: stack_vuoto

Parametro: "ciao"; Stack: "ciao"

Parametro: "ciao"; Stack (ordine di inserimento): "ciao", "bella", "gente", "come", "va"

Parametro: "dado"; Stack (ordine di inserimento): "ciao", "bella", "gente", "come", "va"

Parametro: item_casuale; Stack: 7 item causali

(per generare gli item casuali usare randomItem())

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault)
e produca un output.

Esempio di output: (NOTA: il vostro programma DEVE riprodurre questo output, eccetto per lo stack causale
che dovrà essere differente ad ogni esecuzione del programma)


Elemento parametro: ciao
Stack originale:
Stack invertito:

Elemento parametro: ciao
Stack originale: ciao
Stack invertito:

Elemento parametro: ciao
Stack originale: va       come   gente bella ciao
Stack invertito: gente    come   va

Elemento parametro: dado
Stack originale: va       come   gente bella ciao
Stack invertito: gente    va

Elemento parametro: dep
Stack originale: fbj      zdm    d       rri    cjk    kwi    ccp
Stack invertito: kwi      rri    zdm     fbj*/

#define LIST_H "../../../../Data Structures/stack/list.h"
#define ITEM_H "../../../../Data Structures/stack/item.h"
#define STACK_H "../../../../Data Structures/stack/stack.h"

#include<string.h>
#include <stdio.h>
#include <stdlib.h>

#include ITEM_H
#include STACK_H
#include LIST_H

Item inputItemString(char *n);
void stackReverseBigger(Stack s, Item i_cmp);
void evryOutput(Stack s, Item i_cmp);
int main(){

	Stack s_1 = newStack();
	Item i_cmp_1 = inputItemString("ciao");
	evryOutput(s_1, i_cmp_1);
	printf("\n");



	Stack s_2 = newStack();
	push(s_2,inputItemString("ciao")) ;
	Item i_cmp_2 = inputItemString("ciao");
	evryOutput(s_2, i_cmp_2);
	printf("\n");

	Stack s_3 = newStack();
	push(s_3,inputItemString("va")) ;
	push(s_3,inputItemString("come")) ;
	push(s_3,inputItemString("gente")) ;
	push(s_3,inputItemString("bella")) ;
	push(s_3,inputItemString("ciao")) ;
	Item i_cmp_3 = inputItemString("ciao");
	evryOutput(s_3, i_cmp_3);
	printf("\n");


	Stack s_4 = newStack();
	push(s_4,inputItemString("va")) ;
	push(s_4,inputItemString("come")) ;
	push(s_4,inputItemString("gente")) ;
	push(s_4,inputItemString("bella")) ;
	push(s_4,inputItemString("ciao")) ;
	Item i_cmp_4 = inputItemString("dado");
	evryOutput(s_4, i_cmp_4);
	printf("\n");
/*
    Stack s_5=newStack();
    push(s_5,randomItem()) ;
    push(s_5,randomItem()) ;
    push(s_5,randomItem()) ;
    push(s_5,randomItem()) ;
    push(s_5,randomItem());
    push(s_5,randomItem()) ;
    push(s_5,randomItem()) ;

	Item i_cmp_5 = randomItem());
	evryOutput(s_5,i_cmp_5);
	printf("\n");
	*/
}
void evryOutput(Stack s, Item i_cmp) {

	printf("Elemento parametro: ");
	outputItem(i_cmp);
	printf("\nStack originale: ");
	printStack(s);

	stackReverseBigger(s,i_cmp)	;

	printf("\nStack invertito: ");
	printStack(s);
	printf("\n");

}

void stackReverseBigger(Stack s, Item i_cmp) {
	if (isEmptyStack(s)) {
		return ;

	}
	Item s_cmp;
	Stack tmp_s=newStack();
	Stack tmp_s_2 = newStack();

	while (!isEmptyStack(s)) {
		s_cmp = top(s);
		if (cmpItem(s_cmp, i_cmp) < 0 ) {
			pop(s);
			continue;
		}

		push(tmp_s, s_cmp);
		pop(s);
	}

	while (!isEmptyStack(tmp_s)) {
		s_cmp = top(tmp_s);
		push(tmp_s_2, s_cmp);
		pop(tmp_s);
	}

	while (!isEmptyStack(tmp_s_2)) {
		s_cmp = top(tmp_s_2);
		push(s, s_cmp);
		pop(tmp_s_2);
	}

}
/*
Stack rvStack(Stack s) {
	Stack tmp_s_2 = newStack();
	Stack tmp_s = newStack();
	Item s_cmp;
	while (!isEmptyStack(s)) {
		s_cmp = top(s);
		push(tmp_s, s_cmp);
		pop(s);
	}

	while (!isEmptyStack(tmp_s)) {
		s_cmp = top(tmp_s);
		push(tmp_s_2, s_cmp);
		pop(tmp_s);
	}

	while (!isEmptyStack(tmp_s_2)) {
		s_cmp = top(tmp_s_2);
		push(s, s_cmp);
		pop(tmp_s_2);
	}

	return tmp_s;
}
*/
Item inputItemString(char *s){
	char *pString=malloc(25*sizeof(char));

    strcpy(pString,s);
	return pString;
}