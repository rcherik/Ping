#include "ping.h"

void		ft_sig_handler(int sig)
{
	if (sig == SIGALRM)
	{
		pinger();
		alarm(p->i);
	}
	if (sig == SIGINT)
	{
		statistic();
		exit(0);
	}
}
