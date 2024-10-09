#include <stdio.h>
#include "llist.h"

int main() {
    LList L0, L1, L2, L3, L4;
    int i;

    printf("\nADT List\n");

    L0 = MakeEmpty(NULL);
    L1 = MakeEmpty(NULL);
    L2 = MakeEmpty(NULL);

    // Вставка элементов
    printf("\nInsertBeg:\n");
    for(i = 0; i < 10; i++) {
        InsertBeg(i, L0);
        PrintList(L0);
        printf("\n");
    }

    printf("\nInsertEnd:\n");
    for(i = 0; i < 10; i++) {
        InsertEnd(i, L1);
        PrintList(L1);
        printf("\n");
    }

    // FastCat
    printf("\nFastCat:\n");
    FastCat(L1, L2);
    PrintList(L1);
    printf("\n");

    // FreshCat
    printf("\nFreshCat:\n");
    L3 = FreshCat(L0, L1);
    PrintList(L3);
    printf("\n");

    // Cut
    printf("\nCut:\n");
    PNode P = Member(3, L0);
    L4 = Cut(L0, P);
    PrintList(L0);
    printf("\n");
    PrintList(L4);
    printf("\n");

    // ListSize
    printf("\nListSize:\n");
    printf("Size of L0: %d\n", ListSize(L0));
    printf("Size of L1: %d\n", ListSize(L1));
    printf("Size of L3: %d\n", ListSize(L3));

    // InsertPos
    printf("\nInsertPos:\n");
    InsertPos(99, Member(2, L0), L0);
    PrintList(L0);
    printf("\n");

    RemoveList(&L0);
    RemoveList(&L1);
    RemoveList(&L2);
    RemoveList(&L3);
    RemoveList(&L4);

    return 0;
}