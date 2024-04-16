#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
    int cont;
    struct s_data *next;
}           t_data;

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
            newlist(&head, nbr);
            i++;
        }
        puts("la position qui te peut delete est : ");
        scanf("%d",&del);
        puts("[ ok ]");
        // add_list(&head, 100, 3);
        _free( del,&head);
        // _print(head);
        // puts("==========  appres reversse ===========\n");
        // _reversse(&head);
        _print(head);
    }
}