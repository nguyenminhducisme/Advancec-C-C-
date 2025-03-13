#include<stdio.h>
#include "../inc/stack.h"

int main()
{
    Stack stack;
    stack_init(&stack, 3);
    push_elements(&stack, 3);
    push_elements(&stack, 5);
    push_elements(&stack, 10);
    peek_element(stack);
    pop_elements(&stack);
    pop_elements(&stack);
    display_stack(stack);
    stack_free(&stack);
    return 0;
}