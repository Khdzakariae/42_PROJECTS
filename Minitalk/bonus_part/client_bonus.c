/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:31:03 by zel-khad          #+#    #+#             */
/*   Updated: 2024/03/17 14:38:50 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_envoyan(int sig)
{
	if (sig == SIGUSR2)
		ft_putstr_fd(ANSI_BACKGROUND_GREEN "message envoyer ✅.\n",
			1);
}

void	ft_bits(int pid, char c)
{
	int		i;
	char	tmp;

	i = 7;
	while (i >= 0)
	{
		tmp = c >> i & 1;
		if (tmp == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3)
	{
		pid = atoi(av[1]);
		if (pid <= 0)
		{
			ft_putstr_fd(ANSI_COLOR_RED "ERROR", 2);
			exit(1);
		}
		signal(SIGUSR2, ft_envoyan);
		while (av[2][i])
			ft_bits(pid, av[2][i++]);
		ft_bits(pid, '\0');
		return (0);
	}
	else
		ft_putstr_fd(ANSI_COLOR_RED "PID | STRING !!", 2);
	return (1);
}
