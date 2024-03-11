#include "minitalk.h"

void	handler(int sig)
{
	static int	tmp1 = 0;
	char		tmp;

	tmp = tmp << 1 | (sig == SIGUSR1);
	tmp1++;
	if (tmp1 == 8)
	{
		write(1, &tmp, 1);
		tmp1 = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	printf("THE PID THE SERVER IS %d\n", getpid());
	while (1)
	{
	}
}
