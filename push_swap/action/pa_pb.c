#include "../includes/push_swap.h"

void pop_b(t_stack **b)
{
    if(!b)
        return;
    t_stack *temp;
    temp = *b;
    *b = (*b)->next;
    free(temp);
}

void pb(t_stack **b ,t_stack **a)
{
    //rotection
    if (!*a)
        return;
    t_stack *temp = malloc(sizeof(t_stack));

    temp->cont = (*a)->cont;
    temp->next = *b ;
    *b = temp;
    pop_b(&(*a));
    ft_printf("pb\n");
}

void pa(t_stack **b ,t_stack **a)
{
    if (!*b)
        return;
    t_stack *temp = malloc(sizeof(t_stack));

    temp->cont = (*b)->cont;
    temp->next = *a ;
    *a = temp;
    pop_b(&(*b));
    ft_printf("pa\n");
}



