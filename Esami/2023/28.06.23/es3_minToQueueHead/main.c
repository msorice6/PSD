/*
Esercizio 3. Si implementi, completando il progetto fornito (Esercizio3), una procedura che, dato una coda, cerca l'elemento più piccolo e lo sposta alla testa della coda.
Nel caso in cui siano presenti più elementi minimi uguali, individua e sposta soltanto il primo. Modificare esclusivamente il file main.c aggiungendo la/le funzioni necessarie
e completando int main(). Utilizzare i soli operatori di base della coda (non modificare queue.c e queue.h). Non restituire una nuova coda.
Non usare funzioni di ordinamento (ad es. MergeSort).   Testare la procedura sui seguenti parametro/coda (NON chiedere input all'utente da tastiera,
inserire tutto nel codice C):
Coda: coda_vuota
Coda: "ciao"
Coda: "ciao", "bella", "casa"
Coda: "ciao", "bella", "gente", "bella", "va"
Coda: 5 item causali
(per generare gli item casuali usare randomItem () già fornita))
ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.
Esempio di output: (NOTA: il vostro programma DEVE riprodurre questo output, eccetto per la coda causale che dovrà essere differente ad ogni esecuzione del programma)    :
Coda modificata:

Coda originale : ciao
Coda modificata: ciao

Coda originale : ciao   bella casa
Coda modificata: bella  ciao  casa

Coda originale : ciao   bella gente bella va
Coda modificata: bella  ciao  gente bella va

Coda originale : ffw    vla    cnf    pqd    i
Coda modificata: cnf    ffw    vla    pqd    i
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
void minToQueueHead(Queue q);


int main(){
    Queue q = newQueue();

    enqueue(q, inputItemString("ffw"));
    enqueue(q, inputItemString("vla"));
    enqueue(q, inputItemString("cnf"));
    enqueue(q, inputItemString("pqd"));
    enqueue(q, inputItemString("i"));

    minToQueueHead(q);
	return 0;
}

void minToQueueHead(Queue q) {
    if (isEmptyQueue(q))
        return;
    Queue tmp_q = newQueue();
    Item q_min;
    Item q_cmp;
    int flag = 0;


    q_min = dequeue(q) ;
    enqueue(tmp_q, q_min);
    if (isEmptyQueue(q))
        return;

    while (!isEmptyQueue(q)) {
        q_cmp = dequeue(q);

        if (cmpItem(q_cmp,q_min )<0)
            q_min = q_cmp;

        enqueue(tmp_q, q_cmp);


    }
    enqueue(q, q_min);
    while (!isEmptyQueue(tmp_q)) {
       q_cmp = dequeue(tmp_q);
        if (flag == 0) {
            if (cmpItem(q_cmp, q_min) == 0) {
                flag++;
                continue;

            }
        }
        enqueue(q, q_cmp);

    }
    printQueue(q);

}
Item inputItemString(char *s){
    char *pString=malloc(21*sizeof(char));
    strcpy(pString, s);
    return pString;
}
