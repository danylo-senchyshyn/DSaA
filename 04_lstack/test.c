#include "lstack.h"
#include "err.h"
#include <stdio.h>

int main() {
    LStack stack = CreateStack();

    // Тестирование вставки элементов в стек
    Push(10, &stack);
    Push(20, &stack);
    Push(30, &stack);
    
    printf("Содержимое стека: ");
    PrintStack(stack); // Ожидаемый вывод: 30 20 10

    // Тестирование операций Top и Pop
    printf("Верхний элемент: %d\n", Top(stack)); // Ожидаемый вывод: 30
    Pop(&stack);
    printf("Содержимое стека после Pop: ");
    PrintStack(stack); // Ожидаемый вывод: 20 10

    // Тестирование TopAndPop
    printf("Верхний элемент и его удаление: %d\n", TopAndPop(&stack)); // Ожидаемый вывод: 20
    PrintStack(stack); // Ожидаемый вывод: 10

    // Очистка стека
    RemoveStack(&stack);
    printf("Содержимое стека после удаления: ");
    PrintStack(stack); // Ожидаемый вывод: Stack is empty

    return 0;
}