/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonuc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:31:45 by zel-khad          #+#    #+#             */
/*   Updated: 2024/03/18 16:28:26 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	tmp1 = 0;
	static char	tmp = 0;
	int			g_sender_pid;

	tmp = tmp << 1 | (sig == SIGUSR1);
	g_sender_pid = info->si_pid;
	tmp1++;
	if (tmp1 == 8)
	{
		if (tmp == '\0')
			kill(g_sender_pid, SIGUSR2);
		write(1, &tmp, 1);
		tmp1 = 0;
		tmp = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Le PID du serveur est %d\n", getpid());
	while (1)
	{
	}
	return (0);
}
