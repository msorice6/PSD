/*
Esercizio 3. Si completi il progetto fornito (Esercizio 3).

Scrivere una funzione "testMaxMin" che calcoli il valore massimo contenuto in uno stack e il valore minimo contenuto in una coda e restituisca
1 se questi sono uguali
0 altrimenti. Se entrambe le strutture sono vuote allora il risultato è 1.

ATTENZIONE: Non alterare il contenuto dello stack e della coda.

ATTENZIONE: Modificare esclusivamente il makefile e il file main.c ma non la funzione main(). Non aggiungere o modificare altri file.
NON toccate Stack, List o Queue. Soluzioni non realizzate in main.c non verranno prese in considerazione.

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Esempio di output: (NOTA: il vostro programma DEVE riprodurre questo output, eccetto il caso 5) che deve essere differente ad ogni esecuzione del programma)

1) Caso strutture vuote:
*** I valori sono uguali ***

2) Caso stack pieno, coda vuota:
Stack: 8 9 9 10 10 Queue:
*** I valori NON sono uguali ***

3) Caso strutture piene:
Contenuto originale:
Stack: 8 9 9 10 10 Queue: 10 9 8 7 6
*** I valori NON sono uguali ***

Verificare che il contenuto non sia stato alterato:
Stack: 8 9 9 10 10 Queue: 10 9 8 7 6
*/

#define LIST_H "../../../../Data Structures/list/list.h"
#define ITEM_H "../../../../Data Structures/queue/item.h"
#define QUEUE_H "../../../../Data Structures/queue/queue.h"
#define STACK_H "../../../../Data Structures/stack/stack.h"

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include LIST_H
#include ITEM_H
#include QUEUE_H
#include STACK_H

Item inputItemString(char *s);
Item chk_s_min(Stack s);
Item chk_q_min(Queue q);


int testMaxMin(Queue q, Stack s);
Item find_q_min(Queue q);
Item find_s_min(Stack s);
void evryOutput(Queue q, Stack s);
int main(){
	Stack s_1=newStack();
	Queue q_1 = newQueue();
	evryOutput(q_1,s_1);
	printf("\n");


    Stack s_2=newStack();
    Queue q_2 = newQueue();

	push(s_2, inputItemString("8"));
	push(s_2, inputItemString("9"));
    push(s_2, inputItemString("9"));
    push(s_2, inputItemString("10"));
    push(s_2, inputItemString("10"));

	enqueue(q_2, inputItemString("10")) ;
	enqueue(q_2, inputItemString("9")) ;
	enqueue(q_2, inputItemString("8")) ;
	enqueue(q_2, inputItemString("7")) ;
	enqueue(q_2, inputItemString("6")) ;



	evryOutput(q_2,s_2);
	printf("\n");


	Stack s_3=newStack();
	Queue q_3 = newQueue();

	push(s_3, inputItemString("8"));
	push(s_3, inputItemString("9"));
	push(s_3, inputItemString("9"));
	push(s_3, inputItemString("10"));
	push(s_3, inputItemString("10"));

	enqueue(q_3, inputItemString("6")) ;
	enqueue(q_3, inputItemString("1")) ;
	enqueue(q_3, inputItemString("2")) ;


	evryOutput(q_3,s_3);
	printf("\n");


    return 0;
}
void evryOutput(Queue q, Stack s) {
	printf("Contenuto originale: \n");
	printf("Stack: ");
	printStack(s);
	printf(" Queue: ");
	printQueue(q);
	printf("\n");
	if(testMaxMin(q,s) > 0)
		printf("*** I valori sono uguali ***");
	else
		printf("*** I valori non sono uguali ***");
	printf("\n");

}

Item find_s_min(Stack s) {
	Stack tmp_s = newStack();
	Item s_min = top(s);
	Item s_cmp;


	while (!isEmptyStack(s)) {
		s_cmp = top(s);

		if (cmpItem(s_cmp,s_min) < 0)
			s_min = s_cmp;

		push(tmp_s, top(s));
		pop(s);

	}

	while (!isEmptyStack(tmp_s)) {

		push(s, top(tmp_s));
		pop(tmp_s);

	}


	return s_min;



}

Item find_q_min(Queue q) {

	if (isEmptyQueue(q))
		return NULL;

	Queue tmp_q = newQueue();
	Item q_min=dequeue(q);
	enqueue(tmp_q, q_min);
	Item q_cmp;
	while (!isEmptyQueue(q)) {
		q_cmp = dequeue(q);
		if (cmpItem(q_cmp, q_min) < 0)
			q_min = q_cmp;

		enqueue(tmp_q,q_cmp);
	}

	while (!isEmptyQueue(tmp_q)) {
		q_cmp = dequeue(tmp_q);
		enqueue(q,q_cmp);

	}



	return q_min;

}
//Item find_s_min(Stack s);


int testMaxMin(Queue q, Stack s) {
	Item q_min;
	q_min = find_q_min(q);

	Item s_min;
	s_min = find_s_min(s);

	if (s_min == NULL && q_min == NULL)
		return 1;
	if (s_min == NULL || q_min == NULL)
		return 0;

	if (cmpItem(s_min, q_min) == 0)
		return 1;

	return 0;
}

Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;


}