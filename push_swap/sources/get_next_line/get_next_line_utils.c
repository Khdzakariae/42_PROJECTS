/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:24:56 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/02 10:20:48 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup1(const char *s)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(ft_strlen1(s) + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr1(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen1(s))
		return (ft_strdup1(""));
	if (len > ft_strlen1(s) - start)
		len = ft_strlen1(s) - start;
	ptr = (char *)malloc(len + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len && s + start)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	cpy(char *s1, char *s2, char *ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*ptr;
	int		len;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	len = ft_strlen1(s1) + ft_strlen1(s2);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	cpy(s1, s2, ptr);
	free(s1);
	return (ptr);
}
