#include "lstack.h"
#include "err.h"

int IsEmptyStack(LStack S) {
    return S == NULL;
}

LStack CreateStack(void) {
    return NULL; 
}

void RemoveStack(LStack *PS) {
    MakeEmptyStack(*PS);
    *PS = NULL;
}

void MakeEmptyStack(LStack S) {
    while (!IsEmptyStack(S)) {
        Pop(S);
    }
}

void Push(TElem X, LStack *PS) {
    LStack newNode = (LStack)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        ERROR("Out of memory");
    }
    newNode->data = X;
    newNode->next = *PS;
    *PS = newNode;
}

// Получение элемента с вершины стека (Top)
TElem Top(LStack S) {
    if (IsEmptyStack(S)) {
        ERROR("Stack is empty");
    }
    return S->data;
}

void Pop(LStack *PS) {
    if (IsEmptyStack(*PS)) {
        ERROR("Stack is empty");
    }
    LStack temp = *PS;
    *PS = (*PS)->next;
    free(temp);
}

TElem TopAndPop(LStack *PS) {
    TElem topElem = Top(*PS);
    Pop(PS);
    return topElem;
}

void PrintStack(LStack S) {
    if (IsEmptyStack(S)) {
        printf("Stack is empty\n");
        return;
    }
    while (S != NULL) {
        printf("%d ", S->data);
        S = S->next;
    }
    printf("\n");
}