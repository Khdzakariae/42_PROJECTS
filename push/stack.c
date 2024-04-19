//stack implemantation with array

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

bool  top(int *top)
{
    if (*top == -1)
        return(true);
    else
        return(false);
}
void pup(int *top )
{
    *top = *top - 1;
}
void push(int *p, int x, int *top)
{
    //handle over
    *top = *top + 1;
    p[*top] = x;  
}

int main (int ac , char **av)
{
    int top = -1;
    int i = 1;
    int p[10];
    if (ac != 1)
    {
        while(av[i])
        {
            int num = atoi(av[i]);
            push(p, num, &top);
            i++;
        }
    }
    printf("the top is ========== > %i \n",top);
    pup(&top);
    printf("the top is ========== > %i \n",top);

    i = -1;
    while(i++ < top)
        printf("%i\n", p[i]);
}