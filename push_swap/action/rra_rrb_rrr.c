#include "../includes/push_swap.h"


void newlist(t_stack **head, int nbr)
{
    t_stack *temp  = malloc(sizeof(t_stack));
    temp->cont = nbr;
    temp->next = NULL;
    if (*head != NULL)
        temp->next = *head;
    *head = temp;
}

void _free(t_stack **head)
{
    t_stack *tmp = *head;
    while(tmp->next->next != NULL)
        tmp  = tmp->next;
    t_stack *temp1 = tmp->next;
    tmp->next = temp1->next;
    free(temp1);
}

void rra(t_stack **a)
{
    ft_printf("rra\n");
    t_stack *tmp = *a;
    while(tmp->next != NULL)
        tmp  = tmp->next;
    newlist(&(*a), tmp->cont);
    _free(&(*a));

}

void rrb(t_stack **b)
{
    if(!(*b))
        return;
    t_stack *tmp = *b;
    while(tmp->next != NULL)
        tmp  = tmp->next;
    newlist(&(*b), tmp->cont);
    _free(&(*b));
    ft_printf("rrb\n");

}

void rrr(t_stack **b, t_stack **a)
{
    ft_printf("rrr\n");
    rra(&(*a));
    rrb(&(*b));
}