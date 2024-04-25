#include "../includes/push_swap.h"

void sort_numer_2(t_stack **a)
{
    if((*a)->cont > (*a)->next->cont)
        sa(&(*a));
}
void sort_numer_3(t_stack **a)
{
    t_stack *big = searching_biggest(*a);
    if(*a == big)
        ra(&(*a));
    else if((*a)->next == big)
        rra(&(*a));
    if((*a)->cont > (*a)->next->cont)
        sa(&(*a));
}

void sort_numer_5(t_stack **a, t_stack **b)
{
    is_top(*a);
    t_stack *min = searching_minimum(*a);
    int i = 0;
    t_stack *tmp = *a;
    while(i < 2)
    {
        min = searching_minimum(*a);
        while ((*a) != min)
        {
            if (tmp->top == 0)
                rra(a);
            else
                ra(a);
        }
        pb(b, a);
        tmp = tmp->next;  
        i++;
    }
    sort_numer_3(a);
    while (*b != NULL)
        pa(b, a);
}

void sort_numer(int *tab, t_stack **a, t_stack**b)
{
    t_stack *tmp;
    t_stack *small = searching_minimum(*a);
    int i = 0;
    is_top(*a);
    tmp = *a;
    while(tmp)
    {
        if(small->top)
            rra(a);
        else
            ra(a);
        pb(b, a);
        small = searching_minimum(*a);
        tmp = tmp->next;
    }
}
