#include "minitalk.h"

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
	if (ac != 3)
	{
		ft_putstr_fd(ANSI_COLOR_RED"PID | STRING !!", 2);
		return (1);
	}
	pid = atoi(av[1]);
    if (pid <= 0)
    {
		ft_putstr_fd(ANSI_COLOR_RED"ERROR", 2);
        exit(1);
    }
	while (av[2][i])
		ft_bits(pid, av[2][i++]);
}