#include "../includes/push_swap.h"

void ra(t_stack **a)
{
    t_stack *tmp = *a;
    t_stack *tr = *a;
    *a = (*a)->next;
    while(tmp->next != NULL)
        tmp  = tmp->next;
    add_node(&(*a),tr->cont);
    ft_printf("ra\n");
}

void rb(t_stack **b)
{
    t_stack *tmp = *b;
    t_stack *tr = *b;
    *b = (*b)->next;
    while(tmp->next != NULL)
        tmp  = tmp->next;
    add_node(&(*b),tr->cont);
    ft_printf("rb\n");

}

void rr(t_stack **b, t_stack **a)
{
    ra(&(*a));
    rb(&(*b));
    ft_printf("rr\n");
}

