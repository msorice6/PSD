#include <stdlib.h>
#include "list.h"
#include "item.h"

struct list{
    int size;
    struct node *head;
};

struct node{
    Item value;
    struct node *next;
};


List newList(){
    List l;
    l = malloc(sizeof(struct list));
    l->size = 0;
    l->head = NULL;

    return l;
}

int isEmpty(List l){
    if(l->head == NULL)
        return 1;
    return 0;
}

void addHead(List l, Item e){
    struct node *p = malloc(sizeof(struct node));
    p->value = e;
    p->next = l->head;

    l->head = p;
    l->size++;
}

Item removeHead(List l){
    if(isEmpty(l))
        return NULL;

    struct node *t;
    t = l->head;
    l->head = t->next;
    
    Item value = t->value;
    free(t);
    l->size--;
    return value;
}

Item getHead(List l){
    if(isEmpty(l))
        return NULL;
    else
        return l->head->value;
}

int sizeList(List l){
    return l->size;
}

void printList(List l){
    struct node *p;
    for(p = l->head; p != NULL; p = p->next)
        outputItem(p->value);
} 

Item searchListItem(List l, Item e, int *pos){
    struct node *p;
    *pos=0;
    for(p = l->head; p != NULL; p = p->next,(*pos)++)
        if(cmpItem(e,p->value)==0)
            return p->value;
    *pos=-1;
    return NULL;
}


Item removeListItem(List l, Item e){
    if(isEmpty(l))
        return NULL;
    struct node *p,*prev;
    for(p = l->head; p != NULL;prev=p,p = p->next){
        if(cmpItem(e,p->value)==0){
            if(p==l->head)
                return removeHead(l);
            prev->next=p->next;
            Item e1=p->value;
            free(p);
            l->size--;
            return e1;
        }
    }
}

Item removeListPos(List l, int pos){
    struct node *p,*prev;
    int i=0;
    if(isEmpty(l) || pos<0 || pos>=l->size)
        return NULL;
    for(p = l->head; p != NULL;prev=p,p = p->next,i++){
        if(pos==i){
            if(p==l->head)
                return removeHead(l);
            prev->next=p->next;
            Item e1=p->value;
            free(p);
            l->size--;
            return e1;
        }
    }
}

int addListPos(List l, Item e, int pos){
	if(pos<0 || pos>sizeList(l)){
		return 0;
	}
	struct node *p;
	int i=0;
	for(p=l->head;p!=NULL,i<pos-1;p=p->next,i++);
	if(pos==0){
		addHead(l,e);
		return 1;
	}
	struct node *t=malloc(sizeof(struct node));
	t->value=e;
	t->next=p->next;
	p->next=t;
	l->size++;
	return 1;
}

int addListTail(List l, Item e){
	return addListPos(l,e,sizeList(l));
}

void reverseList(List l){
	struct node *p,*t,*prev;
	prev=NULL;
	for(p=l->head;p!=NULL;prev=p,p=t){
		t=p->next;
		p->next=prev;
	}
	l->head=prev;
}

List cloneList(List l){
	List clone=newList();
	struct node *p;
	for(p=l->head;p!=NULL;p=p->next){
		addListTail(clone,p->value);
	}
	return clone;
}