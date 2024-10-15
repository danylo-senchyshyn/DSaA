#ifndef LSTACK_H
#define LSTACK_H

typedef int TElem;

struct StackNode {
    TElem data;
    struct StackNode* next;
};

typedef struct StackNode* LStack;

// Прототипы операций
int IsEmptyStack(LStack S);
LStack CreateStack(void);
void RemoveStack(LStack *PS);
void MakeEmptyStack(LStack S);
void Push(TElem X, LStack S);
TElem Top(LStack S);
void Pop(LStack S);
TElem TopAndPop(LStack S);
void PrintStack(LStack S);

#endif