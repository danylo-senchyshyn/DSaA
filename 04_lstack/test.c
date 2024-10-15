#include "lstack.h"
#include "err.h"
#include <stdio.h>

int main() {
    LStack stack = CreateStack();

    Push(10, &stack);
    Push(20, &stack);
    Push(30, &stack);
    
    printf("Содержимое стека: ");
    PrintStack(stack);

    printf("Верхний элемент: %d\n", Top(stack)); 
    Pop(&stack);
    printf("Содержимое стека после Pop: ");
    PrintStack(stack);

    printf("Верхний элемент и его удаление: %d\n", TopAndPop(&stack));
    PrintStack(stack); 

    RemoveStack(&stack);
    printf("Содержимое стека после удаления: ");
    PrintStack(stack);

    return 0;
}