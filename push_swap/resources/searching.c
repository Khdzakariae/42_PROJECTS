#include "../includes/push_swap.h"

t_stack *searching_biggest(t_stack *a)
{
    int ind = 1;
    t_stack *big = a;
    t_stack *tmp = a;

    while(tmp)
    {
        if(tmp->cont > big->cont)
            big = tmp;
        tmp = tmp->next;
    }
    return(big);
}
t_stack *searching_minimum(t_stack *a)
{
    t_stack *min = a;
    t_stack *tmp = a;

    while(tmp)
    {
        if(tmp->cont < min->cont)
            min = tmp;
        tmp = tmp->next;
    }
    return(min);
}
