// list.c

// SS 2019, KPI FEI TUKE

#include "llist.h"
#include "err.h"
#include <stdlib.h>

struct Node {
    PNode Next;
    TElem Elem;
};

struct LnkList {
    PNode First;
    PNode Last;
};

LList MakeEmpty(LList L) {
    LList PL;
    if (L != NULL) RemoveList(&L);
    PL = malloc(sizeof(struct LnkList));
    if (PL == NULL) Error("MakeEmpty: out of memory!");
    PL->First = NULL;
    PL->Last = NULL;
    return PL;
}

void RemoveList(LList *PL) {
    PNode T, P;
    if (PL == NULL) Error("RemoveList: incorrect pointer!");
    LList L = *PL;
    if (L == NULL) return;
    P = L->First;
    while (P != NULL) {
        T = P->Next;
        free(P);
        P = T;
    }
    free(L);
    *PL = NULL;
}

void Delete(TElem X, LList L) {
    PNode P, C;
    if (L == NULL) Error("Delete: incorrect list!");
    if (Member(X, L)) {
        P = L->First;
        C = L->First;
        while (C != NULL) {
            if (C->Elem == X) {
                if (C->Next == NULL) L->Last = P;
                if (C->Next == NULL && P == C) L->Last = NULL;
                if (P == C) L->First = C->Next;
                else P->Next = C->Next;
                free(C);
                break;
            }
            P = C;
            C = C->Next;
        }
    }
}

int IsEmpty(LList L) {
    if (L == NULL) Error("IsEmpty: incorrect list!");
    return L->First == NULL;
}

int IsLast(PNode P) {
    if (P == NULL) Error("IsLast: incorrect pointer on input!");
    return P->Next == NULL;
}

PNode Member(TElem X, LList L) {
    PNode P;
    if (L == NULL) Error("Member: incorrect list!");
    P = L->First;
    while (P != NULL) {
        if (P->Elem == X) break;
        P = P->Next;
    }
    return P;
}

void InsertBeg(TElem X, LList L) {
    PNode T;
    if (L == NULL) Error("InsertBeg: incorrect list!");
    T = malloc(sizeof(struct Node));
    if (T == NULL) Error("InsertBeg: out of memory!");
    T->Elem = X;
    T->Next = L->First;
    if (IsEmpty(L)) L->Last = T;
    L->First = T;
}

void InsertEnd(TElem X, LList L) {
    PNode T;
    if (L == NULL) Error("InsertEnd: incorrect list!");
    T = malloc(sizeof(struct Node));
    if (T == NULL) Error("InsertEnd: out of memory!");
    T->Elem = X;
    T->Next = NULL;
    if (IsEmpty(L)) {
        L->First = T;
        L->Last = T;
    } else {
        L->Last->Next = T;
        L->Last = T;
    }
}

PNode First(LList L) {
    if (L == NULL) Error("First: incorrect list!");
    return L->First;
}

PNode Next(PNode P) {
    if (P == NULL) Error("Next: incorrect pointer on input!");
    return P->Next;
}

LList Head(LList L) {
    return L;
}

TElem Get(PNode P) {
    if (P == NULL) Error("Get: incorrect pointer on input!");
    return P->Elem;
}

void PrintList(LList L) {
    if (L == NULL) {
        printf("PrintList: incorrect list!\n");
        return;
    }
    PNode P = First(L);
    if (IsEmpty(L)) printf("Empty list");
    else {
        while (P != NULL) {
            printf("%d ", Get(P));
            P = Next(P);
        }
    }
}

void FastCat(LList L1, LList L2) {
    if (L1 == NULL || L2 == NULL) {
        Error("One of the list doesn`t exist");
        return;
    }

    if (IsEmpty(L2)) return;

    if (IsEmpty(L1)) {
        L1->First = L2->First;
        L1->Last = L2->Last;
    } else {
        L1->Last->Next = L2->First;
        L1->Last = L2->Last;
    }

    L2->First = NULL;
    L2->Last = NULL;
}

LList FreshCat(LList L1, LList L2) {
    if (L1 == NULL || L2 == NULL) {
        Error("One of the list doesn`t exist");
        return NULL;
    }

    LList NewList = MakeEmpty(NULL);
    PNode P = L1->First;

    while (P != NULL) {
        InsertEnd(P->Elem, NewList);
        P = P->Next;
    }

    P = L2->First;
    while (P != NULL) {
        InsertEnd(P->Elem, NewList);
        P = P->Next;
    }

    return NewList;
}

LList Cut(LList L, PNode P) {
    if (L == NULL || P == NULL) {
        Error("One of the list doesn`t exist");
        return NULL;
    }

    LList L2 = malloc(sizeof(struct LnkList));
    L2->First = NULL;
    L2->Last = NULL;

    PNode tmp = L->First;
    if (!IsEmpty(L)) {
        do {
            if (tmp == P) {
                L2->First = tmp->Next;
                L2->Last = L->Last;
                L->Last = tmp;
                L->Last->Next = NULL;
                break;
            }
            tmp = tmp->Next;
        } while (tmp != NULL);
    }

    return L2;
}

int ListSize(LList L) {
    if (L == NULL) Error("ListSize: incorrect list!");

    int size = 0;
    PNode P = L->First;
    while (P != NULL) {
        size++;
        P = P->Next;
    }
    return size;
}

void InsertPos(TElem X, PNode P, LList L) {
    if (L == NULL || P == NULL) Error("InsertPos: incorrect list or pointer!");

    PNode T = malloc(sizeof(struct Node));
    if (T == NULL) Error("InsertPos: out of memory!");

    T->Elem = X;
    T->Next = P->Next;
    P->Next = T;

    if (P == L->Last) {
        L->Last = T;
    }
}