#include <stdio.h>
#include "lqueue.h"

int main( )
{
    printf("\nADT Queue\n");

    LQueue Q1,Q2;
    Q1 = CreateQueue();
    Q2 = CreateQueue();

    printf("\nEnqueue: ");
    for(int i = 1; i <= 5; i++){
        Enqueue(i,Q1);
        printf("Enqueue %d ", i);
        Enqueue(i,Q2);
    }

    if(IsEmptyQueue(Q1)) printf("\nQ1 empty "); else printf("\nQ1 not empty ");

    printf("\nMakeEmptyQueue: ");
    if(IsEmptyQueue(Q2)) printf("\nQ2 empty "); else printf("\nQ2 not empty ");
    PrintQueue(Q2);
    MakeEmptyQueue(Q2);
    if(IsEmptyQueue(Q2)) printf("\nQ2 empty "); else printf("\nQ2 not empty ");
    PrintQueue(Q2);

    RemoveQueue(&Q1);
    RemoveQueue(&Q2);
    printf("\n");

    return 0;
}
