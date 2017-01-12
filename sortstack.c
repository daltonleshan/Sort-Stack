#include <stdio.h>
#include <stdlib.h>
 
// We implement stack using a linked list
struct stack
{
    int data;
    struct stack *next;
};
  
//checks if stack is empty
int isEmpty(struct stack *s)
{
    if (s == NULL)
        return 1;
    return 0;
}

//initializes a stack
void initStack(struct stack **s)
{
    *s = NULL;
}

//pushes an item into a stack
void push(struct stack **s, int x)
{
    struct stack *pointer = (struct stack *) malloc(sizeof(*pointer));
 
    if (pointer == NULL)
    {
        perror("malloc:");
        return;
    }
 
    pointer->data = x;
    pointer->next = *s;
    *s = pointer;
}
 
// removes an item from stack
int pop(struct stack **s)
{
    struct stack *temp;
 
    int x = (*s)->data;
    temp = *s;
    (*s) = (*s)->next;
    free(temp);
 
    return x;
}
 
//finds top item
int peek(struct stack *s)
{
    return (s->data);
}

//sorts stack recursively
void sortStack(struct stack **s)
{
    // If stack not empty
    if (!isEmpty(*s))
    {
        // Remove top item
        int x = pop(s);
 
        // Sort remaining stack
        sortStack(s);
 
        // Push the top item back in sorted stack
        sortedInsert(s, x);
 }
    
// inserts x in sorted way recursively
void sortedInsert(struct stack **s, int x)
{
    // Base case: stack is empty or new insert
    // item is greater than all existing
    if (isEmpty(*s) || x > top(*s))
    {
        push(s, x);
        return;
    }
 
    // If top is greater, remove the top item and recur
    int temp = pop(s);
    sortedInsert(s, x);
 
    // Put back the top item
    push(s, temp);
}
 
}
