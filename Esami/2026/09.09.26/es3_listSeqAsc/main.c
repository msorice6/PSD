/*
Esercizio 3. Si implementi, completando il progetto fornito (Esercizio3), la funzione sottosequenzaCrescenteMassima che ricevuta in input una lista,
restituisce una nuova lista contenente la sottosequenza consecutiva crescente più lunga trovata nella lista originale.
Nel caso ci siano più sottosequenze più lunghe della stessa lunghezza, restituisce quella che comincia prima nella lista
(guardare l'esempio di output se si hanno dubbi).
Si indichi anche, utilizzando i commenti nel codice, la complessità asintotica della funzione implementata,
fornendo una breve giustificazione sulla risposta. ATTENZIONE: leggere le note sui commenti e la compilazione nella prima pagina della traccia.
Modificare esclusivamente i file main.c e makefile aggiungendo le funzioni necessarie e completando int main().
ATTENZIONE: la funzione non deve fare stampe.   ATTENZIONE: affinché l'esercizio venga valutato
è necessario che il progetto modificato compili (con il comando make o con compila.bat).
La valutazione è fortemente influenzata dal fatto che il progetto modificato esegua senza errori (ad es. segmentation fault) e produca un output.
Testare la procedura sui seguenti esempi di lista (NON chiedere input all'utente da tastiera, inserire tutto nel codice C):
[lista vuota]
a
a b c a b
a c e b d f
k z a bb cc dd aa
9 item casuali (per generare gli item casuali usare randomItem() già fornita)

Esempio di output: (NOTA: il vostro programma DEVE riprodurre questo output, eccetto per l'ultimo caso che dovrà essere differente ad ogni esecuzione del programma):
Sottosequenza crescente più lunga:
Lista dopo :

Lista prima:    q
Sottosequenza crescente più lunga: q
Lista dopo :    q

Lista prima:    a    b    c    a    b
Sottosequenza crescente più lunga: a    b    c
Lista dopo :    a    b    c    a    b

Lista prima:    a    c    e    b    d    f
Sottosequenza crescente più lunga: a    c    e
Lista dopo :    a    c    e    b    d    f

Lista prima:    k    z    a    bb   cc   dd   aa
Sottosequenza crescente più lunga: a    bb   cc   dd
Lista dopo :    k    z    a    bb   cc   dd   aa

Lista prima:    i    e    g    j    ku   s    h    r    y
Sottosequenza crescente più lunga: e    g    j    ku
Lista dopo :    i    e    g    j    ku   s    h    r    y






*/
#define LIST_H "../../../../Data Structures/list/list.h"
#define ITEM_H "../../../../Data Structures/list/item.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include LIST_H
#include ITEM_H

List listSeqAsc(List l);
List chk_seq(List l, Item c_l);
Item inputItemString(char *s);
void input2(List l);
void input3(List l);
void input4(List l);
void input5(List l);

void allOutput(List l);
List maxList(List chk_list, List max_list_chk);

int main(){
    List l1 = newList();
    allOutput(l1);
    printf("\n");

    List l2 = newList();
    input2(l2);
    allOutput(l2);
    printf("\n");

	List l3 = newList();
    input3(l3);
    allOutput(l3);
    printf("\n");

	List l4 = newList();
    input4(l4);
    allOutput(l4);
    printf("\n");

	List l5 = newList();
    input5(l5);
    allOutput(l5);
    printf("\n");

    /*
    List l6 = newList();
    l6 = newRandomList();
    allOutput(l6);
    printf("\n");
    */

	return 0;

}
void allOutput(List l){
    List seq_Asc = newList();
    printf("List prima: ");
    printList(l);
    printf("\n");

    printf("Sottosequenza crescente piu' lunga: ");
    seq_Asc = listSeqAsc(l);
    printList(seq_Asc);
    printf("\n");

    printf("List dopo: ");
    printList(l);
    printf("\n");

}
void input2(List l){
    addListTail(l, inputItemString("q"))  ;
}


void input3(List l){
    addListTail(l, inputItemString("a"))  ;
    addListTail(l, inputItemString("b"))  ;
    addListTail(l, inputItemString("c"))  ;
    addListTail(l, inputItemString("a"))  ;
    addListTail(l, inputItemString("b"))  ;
}

void input4(List l){
    addListTail(l, inputItemString("a"))  ;
    addListTail(l, inputItemString("c"))  ;
    addListTail(l, inputItemString("e"))  ;
    addListTail(l, inputItemString("b"))  ;
    addListTail(l, inputItemString("d"))  ;
    addListTail(l, inputItemString("f"))  ;
}

void input5(List l)
{
    addListTail(l, inputItemString("k"))  ;
    addListTail(l, inputItemString("z"))  ;
    addListTail(l, inputItemString("a"))  ;
    addListTail(l, inputItemString("bb"))  ;
    addListTail(l, inputItemString("cc"))  ;
    addListTail(l, inputItemString("dd"))  ;
    addListTail(l, inputItemString("aa"))  ;
}

Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}

List listSeqAsc(List l) {
    List tmp_l = newList();
    List max_list_chk = newList();
    List list_chk = newList();
    Item c_l;

    while(!isEmpty(l)){
        c_l = removeHead(l);
        list_chk = chk_seq(l, c_l);
        max_list_chk = maxList(list_chk, max_list_chk);
        addHead(tmp_l , c_l);
    }


    while(!isEmpty(tmp_l)){
        addHead(l,removeHead(tmp_l));
    }

    return max_list_chk;

}

List maxList(List chk_list, List max_list_chk){
    if(isEmpty(max_list_chk)){
        return chk_list;
    }

    if(sizeList(chk_list) > sizeList(max_list_chk) ){
        return chk_list;
    }

    return max_list_chk;

}

List chk_seq(List l,Item c_l) {

    int flag = 0;
    Item asc_itm;
    Item el_to_cmp;
    List list_chk = newList();
    List tmp_l = newList();

    addListTail(list_chk, c_l);

    while(!isEmpty(l)){
        el_to_cmp = removeHead(l) ;

//        printf("confronto: ");
//        outputItem(c_l);
//        printf("         con: ");
//        outputItem(el_to_cmp);
//        printf("\n");

        if(cmpItem(asc_itm,el_to_cmp) > 0 ){
            flag++;
        }

        if(cmpItem(asc_itm,el_to_cmp) <= 0 ){
            if(flag==0){
                addListTail(list_chk, el_to_cmp);
                asc_itm = el_to_cmp;
            }
        }

        addHead(tmp_l, el_to_cmp);
    }

    while(!isEmpty(tmp_l)){
        el_to_cmp = removeHead(tmp_l) ;
        addHead(l, el_to_cmp);
    }

    return list_chk;

}
