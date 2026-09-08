/*
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
Stack rvStack(Stack s);
int getStackSize(Stack s);
void rmFirstItem(Stack s, Item ins_item, Item rif_item);
int findStackRifPos(Stack s, Item rif_item);
Stack addStackIns(Stack s,Item ins_item, int ins_pos );

int main(){
    Stack s = newStack();
    push(s, inputItemString("gente"));
    push(s, inputItemString("bella"));
    push(s, inputItemString("gente"));
    push(s, inputItemString("gentes"));
    push(s, inputItemString("di"));

    s = rvStack(s) ;
    printStack(s);
    getStackSize(s);
    rmFirstItem(s,inputItemString("sado") ,inputItemString("gente"));
    s = rvStack(s);
    printf("guarda lo stack finale: \n");
    printStack(s);

	return 0;
}
int findStackRifPos(Stack s, Item rif_item){
    Stack tmp_s = newStack();

    while(!isEmptyStack(s)) {
        push(tmp_s, top(s)) ;
        pop(s);

    }
    int ins_flag=0;
    int ins_pos = -1;
    int c =0;
    tmp_s = rvStack(tmp_s);

    while(!isEmptyStack(tmp_s)) {
        push(s, top(tmp_s)) ;
        if ( cmpItem( top(s), rif_item ) == 0 && ins_flag <= 2 ){
            ins_flag++;
            ins_pos = c;
            printf("\n uguale! \n");
        }
        pop(tmp_s);
        c++;
    }

    return ins_pos;
}

Stack addStackIns(Stack s,Item ins_item, int ins_pos ){
    Stack tmp_s = newStack();

    while(!isEmptyStack(s)) {
        push(tmp_s, top(s)) ;
        pop(s);
    }

    int c=0;
    while(!isEmptyStack(tmp_s)) {
        push(s, top(tmp_s));
        if(c == ins_pos){
            push(s, ins_item) ;
        }
        pop(tmp_s);
        c++;
    }

    return s;

}
void rmFirstItem(Stack s, Item ins_item, Item rif_item){
    int ins_pos;
    ins_pos = findStackRifPos(s, rif_item);

       Stack tmp_s = newStack();
       while(!isEmptyStack(s)) {
           push(tmp_s, top(s)) ;
           pop(s);
       }

    tmp_s = addStackIns(tmp_s, ins_item,  ins_pos );
    while(!isEmptyStack(tmp_s)) {
        push(s, top(tmp_s)) ;
        pop(tmp_s);
    }


}
int getStackSize(Stack s){
    Stack tmp_s = newStack();
    int c = 0;
    while(!isEmptyStack(s)) {
        push(tmp_s, top(s)) ;
        pop(s);
        c++;
    }

    while(!isEmptyStack(tmp_s)) {
        push(s, top(tmp_s)) ;
        pop(tmp_s);
    }
    return c;
}

Item inputItemString(char *s){
	char *pString=malloc(21*sizeof(char));
	strcpy(pString, s);
	return pString;
}

Stack rvStack(Stack s){
    Stack tmp_s = newStack();
    while(!isEmptyStack(s)){
        push(tmp_s,top(s) );
        pop(s);
    }
    return tmp_s;
}
