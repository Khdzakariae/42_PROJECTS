#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list	*lastnode;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst != NULL)
	{
		lastnode = ft_lstlast(*lst);
		lastnode->next = new;
		return ;
	}
	*lst = new;
}