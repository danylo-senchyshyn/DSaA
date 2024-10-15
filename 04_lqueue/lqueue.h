#ifndef LQUEUE_H
#define LQUEUE_H

typedef int TElem;

struct QueueNode {
    TElem data;
    struct QueueNode* next;
};

typedef struct {
    struct QueueNode* front;
    struct QueueNode* rear;
} LQueue;

int IsEmptyQueue(LQueue* Q);
LQueue* CreateQueue(void);
void RemoveQueue(LQueue* Q);
void MakeEmptyQueue(LQueue* Q);
void Enqueue(TElem X, LQueue* Q);
TElem Front(LQueue* Q);
void Dequeue(LQueue* Q);
TElem FrontAndDequeue(LQueue* Q);
void PrintQueue(LQueue* Q);

#endif