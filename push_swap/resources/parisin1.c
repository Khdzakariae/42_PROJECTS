#include "../includes/push_swap.h"

void cheack_sort(t_stack *head)
{
    t_stack *tmp = head;
    while(tmp->next)
    {
        if(!((tmp->cont) < (tmp->next->cont)))
            break;
        tmp = tmp->next;
    }
    if(tmp->next == NULL)
        print_error(5);
    return;
}

void cheack_repet(t_stack *head)
{
    t_stack *tmp = head;
    while(head->next)
    {
        tmp = head;
        while(tmp->next)
        {
            if((head->cont) == (tmp->next->cont))
                print_error(3);
            tmp = tmp->next;
        }
        head = head->next;
    }
    return;
}


void len(t_stack *head)
{
    int temp = 0;
    t_stack *tmp = head;
    while(tmp)
    {
        tmp = tmp->next;
        temp++;
    }
    (head)->len = temp;
}

void is_top(t_stack *head)
{
    t_stack *tmp = head;
    len(head);
    int middle = head->len / 2;
    int i = 0;
    while (tmp)
    {
        tmp->index = i;
        if (i <= middle)
            tmp->top = 1;
        else if (i > middle)
            tmp->top = 1;
        tmp = tmp->next;
        i++;
    }
}