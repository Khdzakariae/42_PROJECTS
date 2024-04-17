
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
    int cont;
    struct s_data *next;
}           t_data;



typedef struct s_list
{
    int data;
    struct s_list *next;
    struct s_list *prev;
}               t_list;



// void _add_double(t_list **data, int data)
// {
//     t_list *temp = malloc(sizeof(t_data));
//     temp->data = data;
//     temp->next = NULL;
//     temp->prev = NULL;
//     if(*head == NULL)
//     {
//         *head = temp;
//         return;
//     }
// }
void _print(t_data *data)
{
    int tmp = 0;
    while(data)
    {
        printf("%i\n", data->cont);
        data = data->next;
        tmp++;
    }
    printf("the size of list is |%d|\n", tmp);
}
void newlist(t_data **head, int nbr)
{
    t_data *temp  = malloc(sizeof(t_data));
    temp->cont = nbr;
    temp->next = NULL;
    if (*head != NULL)
        temp->next = *head;
    *head = temp;

}

void _free(int pos, t_data **head)
{
    int i = 0;
    t_data *temp = *head;
    if (pos == 1)
    {
        *head = temp->next;
        free(temp);
    }
    while(i < pos - 2)
    {
        temp = temp->next;
        i++;
    }
    t_data *temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
}
void add_list(t_data **head, int dada, int nb)
{
    int i = 1;
    t_data *temp = malloc(sizeof(t_data));
    temp->cont = dada;
    temp->next = NULL;
    if(nb == 1)
    {
        temp->next = *head;
        *head = temp;
        return;
    }
    t_data *temp2 = *head;
    while(i < nb -1)
    {
        temp2 = temp2->next;
        i++;
    }
    temp->next = temp2->next;
    temp2->next = temp;
}

void rev_print(t_data *head)
{
    if (!head)
        return;
    rev_print(head->next);
    printf("%d\n", head->cont);
}
//this fonction print rev the list with recurjen
void r_print(t_data *head)
{
    if (!head)
        return;
    printf("%d\n", head->cont);
    r_print(head->next);
}



void rev_ol(t_data **head)
{
    t_data *p;
    if (p == NULL)
    {
        puts("==========\n");
        *head = p;
        return;
    }
    rev_ol(&p->next);
    t_data *q = p->next;
    q->next = p;
    p->next = NULL;
}

void _reversse(t_data **head)
{
    t_data *curren, *prev ,*next;
    curren = *head;
    prev = NULL;
    while(curren != NULL)
    {
        next = curren->next;
        curren->next = prev;
        prev = curren;
        curren  = next;
    }
    *head = prev;
}
//this fonction print list with recurjen


void add_node(t_data **head, int data)
{
    t_data *tmp = malloc(sizeof(t_data));
    tmp->cont = data;
    tmp->next = NULL;
    if (*head == NULL)
        *head = tmp;
    else
    {
        t_data *temp1  = *head;
        while(temp1->next != NULL)
            temp1  = temp1->next;
        temp1->next = tmp;
    }
}


int main (int ac , char **av)
{
    int del;
    if (ac > 1)
    {
        t_data *head;
 
        int i = 1;
        while(av[i])
        {
            int nbr = atoi(av[i]);
            // newlist(&head, nbr);
            add_node(&head, nbr);
            i++;
        }
        // puts("la position qui te peut delete est : ");
        // scanf("%d",&del);
        // puts("[ ok ]");
        // add_list(&head, 100, 49);
        // _free( del,&head);
        // _print(head);
        // puts("==========  appres reversse ===========\n");
        // _reversse(&head);
        _print(head);
        puts("==============\n");
        rev_ol(&head);
        _print(head);
        // r_print(head);
    }
}
