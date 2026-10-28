/*
Esercizio 1. Si implementi, completando il progetto fornito (Esercizio1), una funzione che rimuove un elemento dallo stack.
Nel caso in cui l'elemento sia presente più volte nello stack, individua ed elimina soltanto il primo. La funzione restituisce
VERO se l'elemento specificato è stato rimosso,
FALSO se l'elemento specificato non è presente nello stack.

Nota bene: non restituire un nuovo stack.Si indichi anche, utilizzando i commenti nel codice, la complessità asintotica della funzione implementata,
fornendo una breve giustificazione sulla risposta. ATTENZIONE: leggere le note sui commenti e la compilazione nella prima pagina della traccia.
Modificare esclusivamente i file main.c e makefile aggiungendo la/le funzioni necessarie e completando int main().
Utilizzare i soli operatori di base dello stack (non modificare stack.c e stack.h).ATTENZIONE: la funzione non deve fare stampe.
ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make o con compila.bat).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.
Testare la procedura sui seguenti elemento da rimuove/stack (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):

Elemento da rimuovere: "ciao";
Stack: stack_vuoto

Elemento da rimuovere: "ciao";
Stack: "ciao"

Elemento da rimuovere: "ciao";
Stack (ordine di inserimento): "ciao", "bella", "gente", "bella", "va"

Elemento da rimuovere: "bella";
Stack (ordine di inserimento): "bella", "gente", "bella", "va"

Elemento da rimuovere: item casuale;
Stack: 9 item causali(per generare gli item casuali usare randomitem() già fornita)

Esempio di output:
(NOTA: il vostro programma DEVE riprodurre questo output, eccetto per l'elemento casuale e lo stack causale che dovranno essere differenti ad ogni esecuzione del programma)
Stack originale:
Elemento da rimuovere: ciao
Elemento non presente
Stack dopo rim.:
*/

#define LIST_H "../../../../Data Structures/stack/list.h"
#define ITEM_H "../../../../Data Structures/stack/item.h"
#define STACK_H "../../../../Data Structures/stack/stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include ITEM_H
#include STACK_H
#include LIST_H

Item inputItemString(char *s);
int rmStackEl(Stack s, Item el_rm);
void evryOutput(Stack s, Item el_rm);
int main(){
	Stack s_1 = newStack();
	Item el_rm_1 = inputItemString("ciao");
	evryOutput(s_1, el_rm_1);
	printf("\n");

	Stack s_2 = newStack();
    push(s_2, inputItemString("ciao"));
	Item el_rm_2= inputItemString("ciao");
	evryOutput(s_2, el_rm_2);
	printf("\n");

    Stack s_3 = newStack();

    push(s_3, inputItemString("va"));
    push(s_3, inputItemString("bella"));
    push(s_3, inputItemString("gente"));
    push(s_3, inputItemString("bella"));
    push(s_3, inputItemString("ciao"));

	Item el_rm_3 = inputItemString("ciao");

	evryOutput(s_3, el_rm_3);
	printf("\n");

	Stack s_4 = newStack();
	push(s_4, inputItemString("va"));
	push(s_4, inputItemString("bella"));
	push(s_4, inputItemString("gente"));
	push(s_4, inputItemString("bella"));

	Item el_rm_4 = inputItemString("bella");

	evryOutput(s_4, el_rm_4);
	printf("\n");
	/*
	Stack s_5 = newStack();
	push(s_5, randomItem());
	push(s_5,randomItem());
	push(s_5,randomItem());
	push(s_5,randomItem());

	Item el_rm_5 = randomItem();

	evryOutput(s_5, el_rm_5);
	printf("\n");
	*/
	return 0;
}
void evryOutput(Stack s, Item el_rm) {
	printf("Stack originale: ");
	printStack(s);
	printf("\nElemento da rimuovere: ");
	outputItem(el_rm);
	printf("\n");
	if (rmStackEl(s,el_rm)<1)
		printf("Elemento non presente\n");
	printf("Stack dopo rim: ");
	printStack(s);
	printf("\n");

/*
	Stack originale:
Elemento da rimuovere: ciao
Elemento non presente
Stack dopo rim.:
*/

}

int rmStackEl(Stack s, Item el_rm) {
	if (isEmptyStack(s))
		return 0;

	Stack tmp_s = newStack();
	int flag = 0;
	Item el_cmp;
	while (!isEmptyStack(s)) {
		el_cmp = top(s);
		if (flag == 0) {
			if (cmpItem(el_cmp, el_rm) == 0) {
				flag++;
				pop(s);
				continue;
			}
		}
		push(tmp_s, el_cmp);
		pop(s);

	}

	while (!isEmptyStack(tmp_s)) {
		el_cmp = top(tmp_s)	;
		push(s, el_cmp);
		pop(tmp_s);


	}

	if (flag>0)
		return 1;
	return 0;

}
Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return s;
}
