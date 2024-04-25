/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useraccount <useraccount@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:42:49 by zel-khad          #+#    #+#             */
/*   Updated: 2024/03/25 00:50:56 by useraccount      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy(char const *s1, char const *s2, char *ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((!s1 || !s2))
	{
		return;
	}
	while (s1[j] != '\0')
	{
		ptr[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len;

	// printf("----------|%s|\n",s1);
	// printf("----------|%s|\n",s2);
	// exit(20);
	if ((!s1 || !s2))
	{
		return (NULL);
	}

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	cpy(s1, s2, ptr);
	return (ptr);
}
