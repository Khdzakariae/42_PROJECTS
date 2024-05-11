/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:25:06 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/02 10:18:05 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

size_t	ft_strlen1(const char *s);
void	cpy(char *s1, char *s2, char *ptr);
char	*ft_read(char *str, int fd);
char	*get_next_line(int fd);
char	*ft_strdup1(const char *s);
char	*ft_line(char *line);
char	*ft_return(char *str);
char	*ft_substr1(char const *s, unsigned int start, size_t len);
char	*ft_strchr1(const char *s, int c);
char	*ft_strjoin1(char *s1, char *s2);

#endif
