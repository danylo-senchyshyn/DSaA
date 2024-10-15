#include "lstack.h"
#include "err.h"

// Проверка, пуст ли стек
int IsEmptyStack(LStack S) {
    return S == NULL;
}

// Создание нового стека
LStack CreateStack(void) {
    return NULL; // Пустой стек
}

// Удаление стека и освобождение памяти
void RemoveStack(LStack *PS) {
    MakeEmptyStack(*PS);
    *PS = NULL;
}

// Очистка стека
void MakeEmptyStack(LStack S) {
    while (!IsEmptyStack(S)) {
        Pop(S);
    }
}

// Вставка элемента в стек (Push)
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

// Извлечение элемента из стека (Pop)
void Pop(LStack *PS) {
    if (IsEmptyStack(*PS)) {
        ERROR("Stack is empty");
    }
    LStack temp = *PS;
    *PS = (*PS)->next;
    free(temp);
}

// Получение и удаление элемента с вершины стека
TElem TopAndPop(LStack *PS) {
    TElem topElem = Top(*PS);
    Pop(PS);
    return topElem;
}

// Печать содержимого стека
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