#include "includes/push_swap.h"


void add_node(t_stack **head, int data)
{
    t_stack *tmp = malloc(sizeof(t_stack));
    tmp->cont = data;
    tmp->next = NULL;
    if (*head == NULL)
        *head = tmp;
    else
    {
        t_stack *temp1  = *head;
        while(temp1->next != NULL)
            temp1  = temp1->next;
        temp1->next = tmp;
    }
}

void print_list(t_stack *lst) {
    while (lst != NULL) {
        printf("the list is : %ld \n", lst->cont);
        lst = lst->next;
    }
    printf("\n");
}

void _push(t_stack **a, t_stack **b, int ac, char **av)
{
    char **numbers;
    int i;
    int k = 1;
    long number;

    i = 0;
    while (k <= ac - 1)
    {
        numbers = ft_split(av[k], ' ');
        if (!*numbers)
            print_error(4);
        i = 0;
        while (numbers[i] != NULL)
        {
            number = ft_atoi(numbers[i]);
            if ((number > INT_MAX) || (number < INT_MIN))
                print_error(2);
            add_node(&(*a), number);
            i++;
        }
        k++;
    }

}

void parrss(t_stack *a)
{
    cheack_repet(a);
    cheack_sort(a);
}

int *convert(t_stack *a)
{
    int i = 0;
    t_stack *tmp = a;
    len(a);
    int *tab = malloc((a->len) * sizeof(int));

    while(tmp)
    {
        tab[i] = tmp->cont;
        tmp = tmp->next;
        i++;
    }
    return(tab);
}

void t_swap(int *a, int *b)
{
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void _printt(int *tab, int len)
{
    int i = 0;
    while(i < len)
    {
        printf("%i\n", tab[i]);
        i++;
    }
    
}
int sort(int *tab , int len)
{
    int j ;
    int i = 0;
    
    while(len != 0)
    {
        i = 0;
        j = i + 1;;
        while(j < len)
        {
            if(tab[i] > tab[j])
                t_swap(&(tab[i]), &(tab[j]));
            i++;
            j++;
        }
        len--;
    }
    return(*tab);
}

int main (int ac , char **av)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;

    if (ac > 2)
    {
        _push(&a, &b, ac, av);
        parrss(a);
       int *tab = convert(a);
       sort(tab, a->len);
        // _printt(tab, a->len);
        sort_numer(tab,  &a, &b);
        // puts("==== stack a =====\n");
        // print_list(a);
        // if (ac == 3)
        //     sort_numer_2(&a);
        // if (ac == 4)
        //     sort_numer_3(&a);
        // if (ac == 6)
        //     sort_numer_5(&a, &b);
        puts("==== stack a =====\n");
        print_list(a);
        puts("==== stack b =====\n");
        print_list(b);
    }
    else
        print_error(1);
}