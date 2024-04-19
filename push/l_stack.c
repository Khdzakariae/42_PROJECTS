#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct s_stack
{
    int data;
    struct s_stack *next;
}               t_stack;

void push_b(t_stack **b, int data)
{
    t_stack *temp = malloc(sizeof(t_stack));
    temp->data = data;
    temp->next = *b ;
    *b = temp;
}

void pop_b(t_stack **b)
{
    if(!b)
        return;
    t_stack *temp;
    temp = *b;
    *b = (*b)->next;
    free(temp);
}
void print(t_stack *b)
{
    if(!b)
        return;
    printf("the stack is --> |%d|\n", b->data);
    print(b->next);
}

int main ()
{
    t_stack *b = NULL;
    push_b(&b, 5);
    push_b(&b, 4);
    pop_b(&b);
    print(b);
}