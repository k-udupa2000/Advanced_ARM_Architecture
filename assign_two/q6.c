// Circular Queue Implementation

#include<stdio.h>
#include<stdlib.h>

/* 
    Global Variables to used in stack operations.
    Since push and pop occurs at different ends, we 
    need 2 iterators.

*/

// Global variables.
int *queue_ptr;
int queue_front; // Where elements are popped.
int queue_back; // Where elements are pushed.
int queue_size;


// Function declaration
int *create_queue(int);
int Pop();
void Print();
void Push(int);


// Function definition Section
int *create_queue(int stack_size)
{
    int *ptr = (int *)malloc(stack_size*sizeof(int));
    return ptr;
}

void add_to_queue(int data)
{
    if(queue_back == queue_size - 1 && queue_front == 0)
    {
        printf("Queue is full. Element cannot be pushed to the queue.\n");
    }
    else if(queue_front == queue_back + 1)
    {
        printf("Queue is full. Element cannot be pushed to the queue.\n");
    }
    else
    {
        if(queue_back == -1 && queue_front == -1)
        {
            queue_back = 0;
            queue_front = 0;
        }
        else if(queue_back == queue_size - 1)
        {
            queue_back = 0; // property of circular queue.
        }
        else
        {
            queue_back++;
        }
        queue_ptr[queue_back] = data;
    }
}

int remove_from_queue()
{
    if(queue_front == -1)
    {
        printf("The queue is empty. Element cannot be popped.\n");
        return -1;
    }
    else
    {
        int front_element = queue_ptr[queue_front];
        // queue_front++;
        if(queue_front == queue_size - 1)
        {
            queue_front = 0;
        }
        if(queue_front == queue_back)
        {
            // Reinitialising to empty stack configuration.
            queue_front = -1;
            queue_back = -1;
        }
        else
        {
            queue_front++;
        }
        return front_element;
    }
    
}

void print()
{
    // There are mainly 2 conditions to check.
    if(queue_back >= queue_front)
    {
        int start_iterator = 0;
        if(queue_front > start_iterator)
            start_iterator = queue_front;
        for(int i = start_iterator; i <= queue_back; i++)
        {
            printf("%d ", queue_ptr[i]);
        }
        printf("\n");
    }
    else
    {
        for(int i = queue_front; i < queue_size; i++)
        {
            printf("%d ", queue_ptr[i]);
        }
        for(int i = 0; i <= queue_back; i++)
        {
            printf("%d ", queue_ptr[i]);
        }
        printf("\n");
    }
    
}
int main()
{
    int size_of_queue;
    printf("Enter the size of the queue.\n");
    scanf("%d", &size_of_queue);
    queue_ptr = create_queue(size_of_queue);
    queue_size = size_of_queue;
    queue_front = -1;
    queue_back = -1;
    while(1)
    {
        printf("Option 1: Push element.\nOption 2: Pop element.\nOption 3: Print queue elements.\n");
        int option;
        scanf("%d", &option);
        if(option == 1)
        {
            int ele;
            printf("Enter element to push to queue.\n");
            scanf("%d", &ele);
            add_to_queue(ele);
        }
        else if(option == 2)
        {
            int popped_element = remove_from_queue();
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

