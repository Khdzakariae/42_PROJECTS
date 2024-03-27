#include "../push_swap.h"


int cheack_repet(int *valuea, int sise)
{
    int i = 0;
    int j;
    while(i < sise)
    {
        j = i + 1;
        while(j < sise)
        {
            if (valuea[i] == valuea[j])
                return(0);
            j++;
        }
        i++;
    }
    return(1);
}


int cheack(int *values, int sise, char **av)
{
    int i;
    long temp;
    i = 0;
    while ( i < sise)
    {
        temp = ft_atoi(av[i]);
        if (temp > INT_MAX || temp < INT_MIN)
        {
            print_error(2);
            free(values);
            exit(1);
        }
        values[i] = temp;
        i++;
    }
    return(1);
}
