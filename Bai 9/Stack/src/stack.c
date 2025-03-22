#include "../inc/stack.h"

// hàm khởi tạo stack
void stack_init(Stack *stack, int newSize)
{
    stack->size = newSize;
    stack->item = (int *)malloc(newSize * sizeof(int));
    stack->top = -1;
}

bool is_stack_empty(Stack stack)
{
    if(stack.top == -1)
    return true;
    else 
    return false;
}

bool is_stack_full(Stack stack)
{
    if(stack.top == stack.size -1)
    return true;
    else 
    return false;
}

void push_elements(Stack *stack, int new_element)
{
    if(is_stack_full(*stack))
    {
        printf("Can not push more elememnts into this stack\n");
        return;
    }
    stack->item[++stack->top]= new_element;
}


void pop_elements(Stack *stack)
{
    if(is_stack_empty(*stack))
    {
        printf("Stack is currently empty\n");
        return ;
    }
  
    stack->item[stack->top--]=0;
    return;
}

void peek_element(Stack stack)
{
    if(is_stack_empty(stack))
    {
        printf("Can not take out the peek element\n");
        return;
    }
    printf("Peek element: %d\n", stack.item[stack.top--]);

}

void display_stack(Stack stack)
{
    for(int i = 0; i<stack.size; i++)
    {
        printf("Element %d: %d  ",i, stack.item[i]);
    }
}


void stack_free(Stack *stack)
{
    if(stack->item!=NULL)
    {
        free(stack->item);
        stack->item = NULL;
    }
}