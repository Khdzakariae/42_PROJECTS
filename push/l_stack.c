#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


// void sa(t_stack **a)
// {
//     t_stack *temp;
//     temp = *a->next;
//     *a->next = a->next->next;

// }


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
    t_stack *a = NULL;
    t_stack *b = NULL;

    push_b(&b, 5);
    push_b(&b, 4);
    push_b(&b, 7);
    push_b(&b, 10);
    push_b(&b, 20);
    push_b(&b, 30);

    pop_b(&b);
    print(b);
}