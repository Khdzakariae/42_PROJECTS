#include "../push_swap.h"


void print_error(int i)
{
    if (i == 1)
        ft_putstr_fd(RED"ERROR !! : ENTRER LES ARGUMANT QUE TU PEUX SORTE !!", 2);
    else if (i == 2)
        ft_putstr_fd(RED"ERROR !! :  NEMBER (enter des nembers valide)", 2);
    else if (i == 3)
        ft_putstr_fd(RED"ERROR !! : LARGUMANT CENTIEN DUN alphabet", 2);
    else if (i == 4)
        ft_putstr_fd(RED"ERROR !! : LARGUMANT VIDE !!", 2);
    else if (i == 5)
        ft_putstr_fd(RED"ERROR !! : LARGUMANT EST REPETTE !!", 2);

}