#include <stdlib.h>
#include "item.h"
#include "list.h"

struct list
{
    int size;
    struct node *head;
};

struct node 
{
    Item value;
    struct node *next;
};

List newList(){
    List l=malloc(sizeof(struct list));
    l->size=0;
    l->head=NULL;

    return l;
}

int isEmpty(List l){
    if(l->head==NULL)
        return 1;

    return 0;
}

void addHead(List l, Item e){
    struct node *p=malloc(sizeof(struct node));
     
    p->value=e;
    p->next=l->head;
    l->head=p;
    l->size++;
}

Item removeHead(List l){
    if (isEmpty(l))
        return NULL;
    struct node *t=l->head;
    l->head=t->next;
    Item e=t->value;
    free(t);
    l->size--;

    return e;
}

Item getHead(List l){
    if (isEmpty(l))
        return NULL;

    return l->head->value;
}

int sizeList(List l){  
    return l->size;
}

void printList(List l){
    struct node *p;
    for (p=l->head ; p != NULL ; p=p->next )
        outputItem(p->value);
}

Item searchListItem(List l, Item item, int *pos){
    struct node *p;
    *pos = 0;
    
    for (p=l->head ; p != NULL ; p=p->next, (*pos)++)
        if(cmpItem(item, p->value) == 0)
            return p->value;
    
    (*pos) = -1;
    return NULL;
}

Item removeListItem(List l, Item item){
    if(isEmpty(l))
        return NULL;

    struct node *p;
    struct node *prev;

    for (p=l->head ; p != NULL ; prev = p, p=p->next)
        if(cmpItem(item, p->value) == 0){
            if(p == l->head)
                return removeHead(l);
            else{
                prev->next = p->next;
                Item el = p->value;
                free(p);
                l->size--;

                return el;
            }
        }

    return NULL;
}

Item removeListPos(List l, int pos){
    if(isEmpty(l) || pos < 0 || pos >= l->size)
        return NULL;

    struct node *p;
    struct node *prev;
    
    int i = 0;

    for (p=l->head; p != NULL ; prev = p, p=p->next, i++)
        if(i == pos){
            if(p == l->head)
                return removeHead(l);
            else{
                prev->next = p->next;
                Item el = p->value;
                free(p);
                l->size--;

                return el;
            }
        }

    return NULL;
}

int addListPos(List l, Item e, int pos){
    if(pos < 0 || pos > l->size)
        return 0;
    struct node *p;
    int i=0;
    for (p=l->head; p != NULL, i<pos-1; p=p->next, i++);
    if(pos==0){
        addHead(l, e);
        return 1;
    }
    struct node *t = malloc(sizeof(struct node));
    t->next = p->next;
    t->value = e;
    l->size++;
    p->next = t;
    return 1;
}

int addListTail(List l, Item e){
    return addListPos(l, e, l->size);
}

void reverseList(List l){
    struct node *p, *prev = NULL, *temp;
    for (p=l->head; p != NULL ; prev = p, p=temp){
        temp = p->next;
        p->next = prev;
    }
    l->head = prev;
}

List cloneList(List l){
    List cl = newList();
    struct node *p;
    for (p=l->head; p != NULL; p=p->next){
        addListTail(cl, p->value);
    }
    return cl;
}