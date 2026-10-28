/*
Esercizio 3. Si implementi, completando il progetto fornito (Esercizio3), una funzione che ricevuta in input una coda,
rimuova gli elementi duplicati dalla coda stessa (ad esempio se un elemento compare due volte, va rimossa la sua seconda occorrenza;
visionare gli esempi e prestare attenzione all'ordine). La funzione restituisce un intero positivo che
rappresenta il numero degli elementi rimossi, e ZERO se non è stato rimosso alcun elemento.
Nota bene: non restituire una nuova coda.

Si indichi anche, utilizzando i commenti nel codice, la complessità asintotica della funzione implementata, fornendo una breve giustificazione sulla risposta.
ATTENZIONE: leggere le note sui commenti e la compilazione nella prima pagina della traccia.

Modificare esclusivamente i file main.c e makefile aggiungendo la/le funzioni necessarie e completando int main().
Utilizzare i soli operatori di base della coda k (non modificare queue.c e queue.h).

ATTENZIONE: la funzione non deve fare stampe.

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make o con compila.bat).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Testare la procedura sui seguenti esempi (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):

Coda: coda_vuota

Coda: "ciao"

Coda: "ciao", "bella", "gente", "bella", "va"

Coda: 11 item causali

(per generare gli item casuali usare randomitem() già fornita)

Esempio di output: (NOTA: il vostro programma DEVE riprodurre questo output, eccetto per l'elemento casuale e la coda casuale
che dovranno essere differenti ad ogni esecuzione del programma)

Plaintext
Coda originale:
Sono stati rimossi 0 elementi
Coda dopo rim.:

Coda originale: "ciao"
Sono stati rimossi 0 elementi
Coda dopo rim.: "ciao"

Coda originale: ciao    bella    gente    bella    va
Sono stati rimossi 1 elementi
Coda dopo rim.: ciao    bella    gente    va

Coda originale:  o    f    i    zk    d    e    e    t    e    k    f
Sono stati rimossi 3 elementi
Coda dopo rim.:  o    f    i    zk    d    e    t    k
*/
#define LIST_H "../../../../Data Structures/queue/list.h"
#define ITEM_H "../../../../Data Structures/queue/item.h"
#define QUEUE_H "../../../../Data Structures/queue/queue.h"


#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include LIST_H
#include ITEM_H
#include QUEUE_H

Item inputItemString(char *s);
int trovaDoppioni(Queue q);
int chk_trovaDoppioni(Queue q, Item q_chk);
void every_output(Queue q);
void output(Queue q);
int main(){

    Queue q_1 = newQueue();
    every_output(q_1);
    printf("\n");
//
    Queue q_2 = newQueue();
    enqueue(q_2, inputItemString("ciao")) ;
    every_output(q_2);
    printf("\n");

    Queue q_3 = newQueue();
    enqueue(q_3, inputItemString("ciao")) ;
    enqueue(q_3, inputItemString("bella")) ;
    enqueue(q_3, inputItemString("gente")) ;
    enqueue(q_3, inputItemString("bella")) ;
    enqueue(q_3, inputItemString("va")) ;

    every_output(q_3);
    printf("\n");

    Queue q_4 = newQueue();

    enqueue(q_4, inputItemString("o")) ;
    enqueue(q_4, inputItemString("f")) ;
    enqueue(q_4, inputItemString("i")) ;
    enqueue(q_4, inputItemString("zk")) ;
    enqueue(q_4, inputItemString("d")) ;
    enqueue(q_4, inputItemString("e")) ;
    enqueue(q_4, inputItemString("e")) ;
    enqueue(q_4, inputItemString("t")) ;
    enqueue(q_4, inputItemString("e")) ;
    enqueue(q_4, inputItemString("k")) ;
    enqueue(q_4, inputItemString("f")) ;

    every_output(q_4);
    printf("\n");

    return 0;
}
void every_output(Queue q){
    printf("Coda originale: ");
    printQueue(q);
    printf("\nsono stati rimossi %d elementi\n", trovaDoppioni(q));
    printf("coda dopo rim.: ");
    printQueue(q);
    printf("\n");
    printf("\n");
}

int chk_trovaDoppioni(Queue q, Item q_chk) {
    int chk_doppioni=0;
    Queue tmp_q = newQueue();
    Item q_cmp;
    while (!isEmptyQueue(q)) {
        q_cmp = dequeue(q);
        if (cmpItem(q_cmp, q_chk) == 0) {
            chk_doppioni++;
            continue;
        }

        enqueue(tmp_q, q_cmp);
    }

    while (!isEmptyQueue(tmp_q)) {
        q_cmp = dequeue(tmp_q);
        enqueue(q, q_cmp);
    }

    return chk_doppioni;

}

int trovaDoppioni(Queue q){
    int doppioni=0;
    if(isEmptyQueue(q))
        return 0;

    Queue tmp_q = newQueue();
    Item q_cmp;
    while (!isEmptyQueue(q)) {
        q_cmp = dequeue(q);
        doppioni+=chk_trovaDoppioni(q,q_cmp);
        enqueue(tmp_q, q_cmp);
    }

    while (!isEmptyQueue(tmp_q)) {
        q_cmp = dequeue(tmp_q);
        enqueue(q, q_cmp);
    }

    return doppioni;
}


Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString,s);
	return pString;
}
