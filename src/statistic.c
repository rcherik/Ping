#include "ping.h"

static long	ft_llsqrt(unsigned long long a)
{
	long long	prev;
	long long	x;
	
	prev = ~((unsigned long long) 1 << 63);
	x = a;
	if (x > 0)
	{
		while (x < prev)
		{
			prev = x;
			x = (x + (a / x)) / 2;
		}
	}
	return ((long)x);
}

void		statistic(void)
{
	struct timeval		*new;
	long			triptime;
	long long		dev;
	int			loss;

	new = rtt(&p->start);
	p->sum /= p->n_rcv;
	p->sum2 /= p->n_rcv;
	dev = ft_llsqrt(p->sum2 - p->sum * p->sum);
	triptime = new->tv_sec * 1000000 + new->tv_usec;
	printf("\n--- %s ft_ping statistics ---\n", p->target);
	loss = p->n_rcv == 1 ? 100 : (p->n_rcv * 100 / p->n_sent) - 100;
	printf("%d packets transmitted, %d received, ", p->n_sent - 1, p->n_rcv - 1);
	if (p->n_sent != p->n_rcv)
		printf("%d errors, ", (p->n_sent - 1) - (p->n_rcv - 1));
	printf("%d%% packet loss, time ", loss);
	print_rtt(triptime);
	if (p->n_rcv > 1)
	{
		printf("\nrtt min/avg/max/mdev = %ld.%03ld/%lu.%03ld/%ld.%03ld/%ld.%03ld ms",
		(long)p->min / 1000,
		(long)p->min % 1000,
		(unsigned long)(p->sum / 1000),
		(long)(p->sum % 1000),
		(long)p->max/1000,
		(long)p->max%1000,
		(long)dev / 1000,
		(long)dev % 1000);
	}
	printf("\n");
}
