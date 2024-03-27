#include "push_swap.h"


int main (int ac , char **av)
{
    int *values;
    char *s;
    char **retur;
    int i;

    i = 1;
    if (ac != 1)
    {
        values = (int *)malloc(sizeof(int) * ac - 1);
        if (!values)
            exit (1);
        

        s = ft_strdup("");
        while(i <= ac -1)
        {
            s = ft_strjoin(s, av[i]);
            s = ft_strjoin(s, " ");
            i++;
        }
        retur = ft_split(s, ' ');
        cheack(values, ac - 1, retur);
            
        if(cheack_repet(values, ac -1) == 0)
        {
            print_error(2);
            exit(1);
        }
        int j = 0;
        while (retur[j])
            printf("%s\n", retur[j++]);
        exit(1);
    }
    else 
        print_error(1);
}