/*

 Esercizio 3. Si implementi, completando il progetto fornito (Esercizio3), una funzione inserisciElemento che ricevuti in input uno stack, un elemento da inserire e
 un elemento di riferimento (in quest'ordine), inserisca l'elemento da inserire subito dopo la prima occorrenza dell'elemento di riferimento partendo
 dalla base (fondo) dello stack (si intende quindi che l'elemento inserito sarà più vicino alla cima dello stack rispetto all'elemento di riferimento;
 visionare l'esempio di output e prestare attenzione all'ordine).
 La funzione restituisce vero se l'inserimento è avvenuto con successo;
 falso se l'elemento di riferimento non è presente nello stack, e quindi nessun inserimento viene eseguito.

Si indichi anche, utilizzando i commenti nel codice, la complessità asintotica della funzione implementata, fornendo una breve giustificazione sulla risposta.
ATTENZIONE: leggere le note sui commenti e la compilazione nella prima pagina della traccia.

Modificare esclusivamente i file main.c e makefile aggiungendo la/le funzioni necessarie e completando int main().
Utilizzare i soli operatori di base dello stack (non modificare stack.c e stack.h).

ATTENZIONE: la funzione non deve fare stampe.

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make o con compila.bat).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Testare la procedura sui seguenti esempi (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):

Stack: stack_vuoto; elemento da inserire: "AAA"; riferimento: "mare"

Stack: "ciao"; elemento da inserire: "AAA"; riferimento: "bella"

Stack: "ciao", "bella", "gente", "vai"; elemento da inserire: "AAA"; riferimento: "bella"

Stack: "ciao", "bella", "gente", "vai"; elemento da inserire: "X"; riferimento: "b"

Stack: "b", "a", "b", "c"; elemento da inserire: "AAA"; elemento da inserire: "cinque"; riferimento: "sei"

Stack: "uno", "due", "tre", "quattro"; elemento da inserire: "AAA"; riferimento: "b"

Stack: 10 item casuali; elemento da inserire: "AAA"; riferimento: "b"

(per generare gli item casuali usare randomItem() già fornita)

NOTA: negli esempi l'elemento più a sinistra è quello in cima allo stack, l'elemento più a destra è quello alla base (fondo) dello stack. La stessa cosa vale negli esempi di output.

Esempio di output: (NOTA: Il vostro programma DEVE riprodurre questo output, eccetto per lo stack casuale che dovrà essere differente ad ogni esecuzione del programma)

Stack originale:
Elemento da inserire: AAA        (NON inserito)
Elemento riferimento: mare
Stack dopo ins.:

Stack originale: ciao
Elemento da inserire: AAA        (NON inserito)
Elemento riferimento: bella
Stack dopo ins.: ciao

---

Stack originale: ciao    bella    gente    va
Elemento da inserire: AAA        (inserito)
Elemento riferimento: bella
Stack dopo ins.: ciao    AAA    bella    gente    va

Stack originale: b    a    b    c
Elemento da inserire: X (inserito)
Elemento riferimento: b
Stack dopo ins.: b    a    X    b    c

Stack originale: uno    due    tre    quattro
Elemento da inserire: cinque (NON inserito)
Elemento riferimento: sei
Stack dopo ins.: uno    due    tre    quattro

Stack originale: b    x    j    v    i    s    p    j    i    u
Elemento da inserire: AAA        (inserito)
Elemento riferimento: b
Stack dopo ins.: AAA    b    x    j    v    i    s    p    j    i    u

*/

#define LIST_H "../../../../Data Structures/stack/list.h"
#define ITEM_H "../../../../Data Structures/stack/item.h"
#define STACK_H "../../../../Data Structures/stack/stack.h"

#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include ITEM_H
#include STACK_H
#include LIST_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include ITEM_H
#include STACK_H
#include LIST_H

Item inputItemString(char *s);
int in/*


Esercizio 2: Si implementi, completando il progetto fornito (Esercizio2) una funzione sommaFoglieDestre che, dato in input un albero binario,
restituisce la somma dei valori contenuti nei nodi foglia che sono figli destri.

Un nodo n si considera foglia destra se:

n non ha figli;

n è il figlio destro del suo genitore.

Usare la ricorsione per implementare l'algoritmo. Si indichi anche, utilizzando i commenti nel codice, la complessità asintotica della funzione implementata,
fornendo una breve giustificazione sulla risposta. ATTENZIONE: leggere le note sui commenti e la compilazione nella prima pagina della traccia.

Modificare esclusivamente i file main.c e makefile, senza aggiungere o modificare gli operatori disponibili negli ADT forniti.

ATTENZIONE: la funzione non deve fare stampe.

ATTENZIONE: affinché l'esercizio venga valutato è necessario che il progetto modificato compili (con il comando make).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.

Testare nel main la procedura sui seguenti alberi (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):

Un albero vuoto;

Un albero consistente della sola radice contenente il numero 2;

Un albero instanziato come di seguito:

      7
     / \
    3   6
   / \
  1   5
Un primo albero casuale (richiamare newRandomTree(3) per creare l'albero casuale);

Un secondo albero casuale (richiamare newRandomTree(4) per creare l'albero casuale).

Utilizzare la funzione printTree(BTree) per stampare gli alberi e la funzione newRandomTree(int) per creare l'albero casuale (fornite dall'ADT).

*/

#define BTREE_H "../../../../Data Structures/btree/btree.h"
#define ITEM_H "../../../../Data Structures/btree/item.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include BTREE_H
#include ITEM_H
int sumTreeFL(BTree t);
int sumLeaf(BTree t);

int sommaFoglieDestre(BTree t);

int *outputItemInt(Item itm);
void evryOutput(BTree t);
int main(){
    BTree t_5 = newTree();
    t_5 = newRandomTree(4) ;
    printTree(t_5);
    printf("somma nodi: %d\n", sommaFoglieDestre(t_5));
//    int *sa =outputItemInt(inputItem()) ;
//    int da = *sa;
//    printf("salve salvino: %d", da);



    return 0;
}

int *outputItemInt(Item itm){
	int *pt = itm;
    return pt;
}


int sommaFoglieDestre(BTree t){
//    Item c;
    Item c_itm;
    int *c=0;
    int n=0;
    if(isEmptyTree(t))
        return 0;

    BTree l = getLeft(t);
    BTree r = getRight(t);

    if(!isEmptyTree(getRight(t))){
        if(isEmptyTree(getRight(r)) && isEmptyTree(getRight(l))  ) {
            c = outputItemInt(getBTreeRoot(t)) ;

//             printf("questo albero ha la foglia destra: ") ;
//             outputItem( getBTreeRoot (t) );
//             printf("\n") ;
            n = *c;
//            printf("guarda n: %d\n", n);
        }


    }
    return n + sommaFoglieDestre(getLeft(t)) + sommaFoglieDestre(getRight(t));
}

BTree input1(BTree t){

    BTree l = newTree();
    BTree r = newTree();

    BTree ll = newTree();
    BTree lr = newTree();

    ll = buildTree(NULL,NULL,inputItemInt(1));
    lr = buildTree(NULL,NULL, inputItemInt(5));



    r = buildTree(NULL, NULL, inputItemInt(6));
    l = buildTree(ll,lr,inputItemInt(3));


    t = buildTree(l, r, inputItemInt(7));
    return t;

}
serisciElemento(Stack s, Item ins_el, Item rif_el);
void evryOutput(Stack s, Item ins_el, Item rif_el);
int main(){
	Stack s_1 = newStack();
	Item ins_el_1 = inputItemString("AAA");
	Item rif_el_1 = inputItemString("bella");
	evryOutput(s_1, ins_el_1, rif_el_1);
	printf("\n");


	Stack s_2 = newStack();
	push(s_2, inputItemString("ciao"));
	Item ins_el_2 = inputItemString("AAA");
	Item rif_el_2 = inputItemString("bella");
	evryOutput(s_2, ins_el_2, rif_el_2);
	printf("\n");



    Stack s_3 = newStack();
    push(s_3, inputItemString("vai"));
    push(s_3, inputItemString("gente"));
    push(s_3, inputItemString("bella"));
    push(s_3, inputItemString("ciao"));

	Item ins_el_3 = inputItemString("AAA")	;
	Item rif_el_3 = inputItemString("bella");
	evryOutput(s_3, ins_el_3, rif_el_3);
	printf("\n");
	return 0;
}

void evryOutput(Stack s, Item ins_el, Item rif_el) {
	int is_ins = 0;
	printf("Stack originale: ");
	printStack(s);
	is_ins = inserisciElemento(s,ins_el,rif_el);
	printf("\nElemeno da inserire: ");
	outputItem(ins_el);
	if (is_ins > 0)
		printf("         (inserito)");
	printf("\nElemento riferimento: ");
	outputItem(rif_el);
	printf("\nStack dopo ins.: ");
	printStack(s)	;
	printf("\n");

}
int inserisciElemento(Stack s, Item ins_el, Item rif_el) {
	if (isEmptyStack(s))
		return 0;
	Stack tmp_s = newStack();
	int flag = 0;
	Item cmp_el;

	while (!isEmptyStack(s)) {
		cmp_el = top(s);
		if (flag == 0) {
			if (cmpItem(rif_el, cmp_el) == 0) {
				flag++;
				push(tmp_s, ins_el);
			}
		}
		push(tmp_s, cmp_el);
		pop(s);
	}

	while (!isEmptyStack(tmp_s)) {

		cmp_el = top(tmp_s);
		push(s, cmp_el);
		pop(tmp_s);

	}

	if (flag>0)
		return 1;

	return 0;
}

Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}
