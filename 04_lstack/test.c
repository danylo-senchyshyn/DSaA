#include "lstack.h"
#include "err.h"
#include <stdio.h>

int main() {
    LStack stack = CreateStack();

    Push(10, &stack);
    Push(20, &stack);
    Push(30, &stack);
    
    printf("Stack contents: ");
    PrintStack(stack); 

    printf("Top element: %d\n", Top(stack)); 
    Pop(&stack);
    printf("Stack contents after Pop: ");
    PrintStack(stack); 

    printf("Top element and removing it: %d\n", TopAndPop(&stack)); 
    PrintStack(stack); 

    RemoveStack(&stack);
    printf("Stack contents after removing: ");
    PrintStack(stack); 

    return 0;
}