/*
    Esercizio 2. Si implementi, completando il progetto fornito (Esercizio2), una funzione che rimuove un elemento dallo stack.
    Nel caso in cui l'elemento sia presente più volte nello stack, individua ed elimina soltanto il primo. Se l'elemento specificato non è presente,
    il programma stampa un messaggio informativo per l'utente.
    Modificare esclusivamente i file main.c e makefile aggiungendo la/le funzioni necessarie e completando int main().
    Utilizzare i soli operatori di base dello stack (non modificare stack.c e stack.h). Non restituire un nuovo stack.

Testare la procedura sui seguenti elemento da rimuove/stack (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):

Elemento da rimuovere: "ciao"; Stack: stack_vuoto

Elemento da rimuovere: "ciao"; Stack: "ciao"

Elemento da rimuovere: "ciao"; Stack (ordine di inserimento): "ciao", "bella", "gente", "bella", "va"

Elemento da rimuovere: "dado"; Stack (ordine di inserimento): "bella", "gente", "bella", "va"

Elemento da rimuovere: item_casuale; Stack: 9 item causali

(per generare gli item casuali usare randomItem() già fornita)

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make). La valutazione è fortemente influenzata
dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Esempio di output: (NOTA: il vostro programma DEVE riprodurre questo output, eccetto per l'elemento casuale e lo stack causale che dovranno essere differenti ad
ogni esecuzione del programma)


Stack originale:
Elemento da rimuovere: ciao
Elemento non presente
Stack dopo rim.:

Stack originale: ciao
Elemento da rimuovere: ciao
Elemento rimosso
Stack dopo rim.:

Stack originale: va       bella gente bella ciao
Elemento da rimuovere: ciao
Elemento rimosso
Stack dopo rim.: va       bella gente bella

Stack originale: va       bella gente bella
Elemento da rimuovere: bella
Elemento rimosso
Stack dopo rim.: va       gente bella

Stack originale: s        hz     g       v       g       c       k       z       m
Elemento da rimuovere: g
Elemento rimosso
Stack dopo rim.: s        hz     v       g       c       k       z       m
*/

#define LIST_H "../../../../Data Structures/stack/list.h"
#define ITEM_H "../../../../Data Structures/stack/item.h"
#define STACK_H "../../../../Data Structures/stack/stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include ITEM_H
#include STACK_H
#include LIST_H

Item inputItemString(char *s);
int firstStackRm(Stack s, Item itm_rm);
void evryOutput(Stack s, Item itm_rm);
int main(){

    Stack s_1 = newStack();
    Item itm_rm_1 = inputItemString("ciao");
    evryOutput(s_1, itm_rm_1);
    printf("\n");

    Stack s_2 = newStack();
    push(s_2,inputItemString("ciao"));
    Item itm_rm_2 = inputItemString("ciao");
    evryOutput(s_2, itm_rm_2);
    printf("\n");


    Stack s_3 = newStack();

    push(s_3,inputItemString("ciao"));
    push(s_3,inputItemString("bella"));
    push(s_3,inputItemString("gente"));
    push(s_3,inputItemString("bella"));
    push(s_3,inputItemString("va"));

    Item itm_rm_3 = inputItemString("ciao");
    evryOutput(s_3,itm_rm_3);
    printf("\n");

    Stack s_4 = newStack();

    push(s_4,inputItemString("ciao"));
    push(s_4,inputItemString("bella"));
    push(s_4,inputItemString("gente"));
    push(s_4,inputItemString("bella"));
    push(s_4,inputItemString("va"));

    Item itm_rm_4 = inputItemString("bella");
    evryOutput(s_4,itm_rm_4);
    printf("\n");



/*
    Stack s_5 = newStack();

    push(s_5,randomItem());
    push(s_5,randomItem());
    push(s_5,randomItem());
    push(s_5,randomItem());

    Item itm_rm_5 = randomItem();


    evryOutput(s,itm_rm_5);
*/

	return 0;

}

void evryOutput(Stack s, Item itm_rm) {

    printf("Stack originale: ");
    printStack(s);
    printf("\nElemento da rimuovere: ");
    outputItem(itm_rm);

    if (firstStackRm(s,itm_rm) > 0 )
        printf("\nElemento rimosso");
    else
        printf("\n");

    printf("Stack dopo rim.: ");
    printStack(s);
    printf("\n");


}


int firstStackRm(Stack s, Item itm_rm){

    if (isEmptyStack(s))
        return 0;

    Stack tmp_s = newStack();
    Item itm_cmp;
    int flag = 0;
    while (!isEmptyStack(s)) {

        itm_cmp = top(s);
        if (flag == 0) {
            if (cmpItem(itm_cmp, itm_rm) == 0) {
                flag++;
                pop(s);
                continue;
            }
        }
        push(tmp_s, itm_cmp);
        pop(s);

    }

    while (!isEmptyStack(tmp_s)) {
        itm_cmp = top(tmp_s) ;
        push(s, itm_cmp);
        pop(tmp_s);


    }

    return flag;

}

Item inputItemString(char *s){
    char *pString=malloc(21*sizeof(char));
    strcpy(pString, s);
    return pString;
}