#include <stdio.h>
#include "lstack.h"

int main( )
{
    LStack S0,S1;

    S0 = CreateStack();
    S1 = CreateStack();

    printf("\nADT Stack\n");

    printf("\nPush: ");
    for(int i=1; i<=5;i++)
    {
        Push(i,S0);
        Push(i,S1);
        printf("%d ", i);
    }

    printf("\nPrintStack: ");
    printf("\nS0: ");
    PrintStack(S0);
    printf("\nS1: ");
    PrintStack(S1);

    printf("\nMakeEmpty: [MakeEmptyStack(S1)]");
    MakeEmptyStack(S1);

    printf("\nIsEmpty: ");
    if(IsEmptyStack(S0)) printf("S0 empty "); else printf("S0 not empty ");
    if(IsEmptyStack(S1)) printf("S1 empty "); else printf("S1 not empty ");

    RemoveStack(&S0);
    RemoveStack(&S1);
    printf("\n");

    printf("\nTop of S0: %d", Top(S0));
    Pop(S0);
    printf("\nAfter Pop, S0: ");
    PrintStack(S0);

    int topAndPop = TopAndPop(S0);
    printf("\nTopAndPop result: %d", topAndPop);
    printf("\nAfter TopAndPop, S0: ");
    PrintStack(S0);

    return 0;
}
