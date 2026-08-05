#include <stdlib.h>
#include "item.h"
#include "queue.h"
#define MAXQUEUE 10

struct queue{
    Item elements[MAXQUEUE];
    int head;
    int tail;
};

Queue newQueue()
{
    Queue q;
    q=malloc(sizeof(struct queue));
    q->head = q->tail = 0;
    return q;
}

int isEmptyQueue(Queue q)
{
    if(q->tail == q->head)
        return 1;
    return 0;
}

int enqueue(Queue q, Item e)
{
    if((q->tail+1)%MAXQUEUE == q->head)
        return 0;

    q->elements[q->tail] = e;
    q->tail=(q->tail+1)%MAXQUEUE;
    return 1;
}

Item dequeue(Queue q)
{
    if(isEmptyQueue(q))
        return NULL;

    Item e=q->elements[q->head];
    q->head=(q->head+1)%MAXQUEUE;
    return e;
}

void printQueue(Queue q)
{
    int i;
    for(i=q->head; i!=q->tail; i=(i+1)%MAXQUEUE)
        outputItem(q->elements[i]);
}