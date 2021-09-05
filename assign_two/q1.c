
// Full Descending Stack Implementation.
/*
A descending stack grows downwards. It starts from higher memory 
address and proceeds to lower memory address as elements are pushed into it.


In a full stack, the stack pointer points to the top most item of the stack.
*/
#include<stdio.h>
#include<stdlib.h>
// Function Declaration Section
int *create_a_stack(int);
void print();
void Push(int);
int Pop();


// Global Variables to used in stack operations.
int *stack_ptr;
int stack_top;
int stack_size;



// Function definition Section
int *create_a_stack(int stack_size)
{
    int *stack_ptr = (int *)malloc(stack_size*sizeof(int));
    return stack_ptr;
}

void print()
{
    // Since this is full descending stack, the elements in the stack 
    // will be in the location of stack[size - 1 - stack_top:size - 1]
    for(int i = stack_top; i < stack_size; i++)
    {
        printf("%d ", stack_ptr[i]);
    }
    printf("\n");
}
int Pop()
{
    if(stack_top == stack_size)
    {
        // Means that the stack is empty and element cannot be popped.
        printf("Stack is empty, element cannot be popped.\n");
        return -1;
    }
    int ele = stack_ptr[stack_top];
    stack_top++;
    return ele;
}
void Push(int ele)
{
    if(stack_top == 0)
    {
        // Means that stack is full and new element cannot be pushed.
        printf("Stack is full, element cannot be pushed into the stack.\n");
    }
    else
    {
        stack_top = stack_top - 1;
        stack_ptr[stack_top] = ele;
    }
}
int main()
{
    int size_of_stack;
    printf("Enter the size of the stack.\n");
    scanf("%d", &size_of_stack);
    stack_ptr = create_a_stack(size_of_stack);
    stack_size = size_of_stack;
    stack_top = size_of_stack;
    while(1)
    {
        printf("Option 1: Push element.\nOption 2: Pop element.\nOption 3: Print stack elements.\n");
        int option;
        scanf("%d", &option);
        if(option == 1)
        {
            int ele;
            printf("Enter element to push to stack.\n");
            scanf("%d", &ele);
            Push(ele);
        }
        else if(option == 2)
        {
            int popped_element = Pop();
            if(popped_element != -1)
            {
                printf("Popped element = %d.\n", popped_element);
            }
        }
        else if(option == 3)
        {
            print();
        }
        else
        {
            break;
        }
    }
}
