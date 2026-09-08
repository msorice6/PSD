/*
    si implementi la funzione elementiUnivoci che ricevuto in input una lista,
    restituisce il numero di elementi univoci presenti nella lisa
*/
#define LIST_H "../../Data Structures/list/list.h"
#define ITEM_H "../../Data Structures/list/item.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include LIST_H
#include ITEM_H

int elementiUnivoci(List l);
Item inputItemString(char *s);
Item *listToArray(List l);
void input1(List l);
void input2(List l);
void input3(List l);
void input4(List l);
void input5(List l);
void input6(List l);
void everyoutput(List l);

int main(){
	List l = newList();
    input1(l);
    everyoutput(l);

    l = newList();
    input2(l);
    everyoutput(l);

    l = newList();
    input1(l);
    everyoutput(l);

    l = newList();
    input2(l);
    everyoutput(l);

    l = newList();
    input3(l);
    everyoutput(l);

    l = newList();
    input4(l);
    everyoutput(l);

    l = newList();
    input5(l);
    everyoutput(l);

    l = newList();
    input6(l);
    everyoutput(l);

	return 0;
}

void everyoutput(List l){
    printf("Lista prima: ");
    printList(l);
    printf("\n");
    printf("Elementi: %d\n", sizeList(l));
    printf("Elementi univoci: %d\n",elementiUnivoci(l));
    printf("\n");

}

void input1(List l){
}
void input2(List l){
    addListTail(l, inputItemString("ciao"))  ;
}

void input3(List l){
    addListTail(l, inputItemString("ciao"))  ;
    addListTail(l, inputItemString("casa"))  ;
}
void input4(List l){
    addListTail(l, inputItemString("ciao"))  ;
    addListTail(l, inputItemString("ciao"))  ;
    addListTail(l, inputItemString("ciao"))  ;
    addListTail(l, inputItemString("ciao"))  ;
}
void input5(List l){
    addListTail(l, inputItemString("bella"))  ;
    addListTail(l, inputItemString("gente"))  ;
    addListTail(l, inputItemString("bella"))  ;
    addListTail(l, inputItemString("ciao"))  ;
    addListTail(l, inputItemString("va"))  ;
    addListTail(l, inputItemString("ciao"))  ;
    addListTail(l, inputItemString("ciao"))  ;
}
void input6(List l){
    addListTail(l, inputItemString("z"))  ;
    addListTail(l, inputItemString("i"))  ;
    addListTail(l, inputItemString("z"))  ;
    addListTail(l, inputItemString("t"))  ;
    addListTail(l, inputItemString("x"))  ;
    addListTail(l, inputItemString("m"))  ;
    addListTail(l, inputItemString("i"))  ;
    addListTail(l, inputItemString("f"))  ;
    addListTail(l, inputItemString("r"))  ;
}

int elementiUnivoci(List l){
//     if(sizeList(l) <= 0 )
//         return 0;
    int n = sizeList(l);
    List tmp_l = cloneList(l);
    Item *array_list = listToArray(tmp_l);
//    free(tmp_l);
    int flag = 0;
    int conta_elementi_univoci = 0;
    for(int i = 0; i< n; i++){
        for(int j = i+1; j< n; j++){
            if(cmpItem(array_list[i], array_list[j]) == 0 ){
                flag++;
            }
        }
        if(flag<1)
            conta_elementi_univoci++;
        flag = 0;
    }

    return conta_elementi_univoci;
}

Item *listToArray(List l){
    int n = sizeList(l);
    Item *array_list = malloc(sizeList(l) * sizeof(Item));
    for(int i = 0; i < n; i++){
        array_list[i] = getHead(l) ;
        removeHead(l);
    }


    return array_list;

}
Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}

