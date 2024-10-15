#include "lqueue.h"
#include "err.h"
#include <stdlib.h>

int IsEmptyQueue(LQueue* Q) {
    return Q->front == NULL;
}

LQueue* CreateQueue(void) {
    LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
    if (Q == NULL) {
        ERROR("Out of memory");
    }
    Q->front = Q->rear = NULL;
    return Q;
}

void RemoveQueue(LQueue* Q) {
    MakeEmptyQueue(Q);
    free(Q);
}

void MakeEmptyQueue(LQueue* Q) {
    while (!IsEmptyQueue(Q)) {
        Dequeue(Q);
    }
}

void Enqueue(TElem X, LQueue* Q) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        ERROR("Out of memory");
    }
    newNode->data = X;
    newNode->next = NULL;

    if (IsEmptyQueue(Q)) {
        Q->front = Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

TElem Front(LQueue* Q) {
    if (IsEmptyQueue(Q)) {
        ERROR("Queue is empty");
    }
    return Q->front->data;
}

void Dequeue(LQueue* Q) {
    if (IsEmptyQueue(Q)) {
        ERROR("Queue is empty");
    }
    struct QueueNode* temp = Q->front;
    Q->front = Q->front->next;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    free(temp);
}

TElem FrontAndDequeue(LQueue* Q) {
    TElem frontElem = Front(Q);
    Dequeue(Q);
    return frontElem;
}

void PrintQueue(LQueue* Q) {
    if (IsEmptyQueue(Q)) {
        printf("Queue is empty\n");
        return;
    }
    struct QueueNode* temp = Q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}