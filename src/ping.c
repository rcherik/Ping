/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 15:11:53 by rcherik           #+#    #+#             */
/*   Updated: 2016/01/06 16:51:11 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

static void	set_icmp(struct icmp *icmp, int seq, int pid)
{
	icmp->icmp_type = ICMP_ECHO;
	icmp->icmp_code = 0; /* Same */
	icmp->icmp_id = pid; /* ID */
	icmp->icmp_seq = seq; /* sequence number */
	icmp->icmp_cksum = 0;
}

static void	set_msg(struct msghdr *msg, struct iovec *iov, struct sockaddr_in *from)
{
	char			*data;
	char			data2[4096];

	data = malloc(BUFF_SIZE);
	msg->msg_name = from;
	msg->msg_namelen = sizeof(struct sockaddr_in);
	iov->iov_base = data;
	iov->iov_len = 1024;
	msg->msg_iov = iov;
	msg->msg_iovlen = 1;
	msg->msg_control = data2;
	msg->msg_controllen = 4096;
	msg->msg_flags = 0;
}

struct timeval	*rtt(struct timeval *time)
{
	struct timeval	*now;

	now = (struct timeval *)malloc(sizeof(struct timeval));
	ft_bzero(now, sizeof(struct timeval));
	gettimeofday(now, NULL);
	if((now->tv_usec -= time->tv_usec) < 0)
	{       
		--now->tv_sec;
		now->tv_usec += 1000000;
	}
	now->tv_sec -= time->tv_sec;
	return (now);
}

void		print_rtt(long triptime)
{
	if (triptime >= 100000)
		printf("%ld ms", triptime/1000);
	else if (triptime >= 10000)
		printf("%ld.%01ld ms", triptime/1000, (triptime%1000)/100);
	else if (triptime >= 1000)
		printf("%ld.%02ld ms", triptime/1000, (triptime%1000)/10);
	else
		printf("%ld.%03ld ms", triptime/1000, triptime%1000);
}

static void	print_verbose(struct icmp *icmp, int c, struct sockaddr_in from)
{
	char	buf[BUFF_SIZE];

	ft_bzero(buf, BUFF_SIZE);
	printf("%d bytes from %s : type = %d, code = %d\n",
	c,
	inet_ntop(AF_INET, &from.sin_addr, buf, BUFF_SIZE),
	icmp->icmp_type,
	icmp->icmp_code);
}

static int	print_packet(char *s, int c, t_ping *p, struct sockaddr_in from)
{
	struct ip		*ip;
	struct icmp		*icmp;
	int			iphdr_len;
	struct timeval		*time;
	struct timeval		*new;
	long			triptime;
	char			a;

	a = 0x07;
	ip = (struct ip *)s;
	iphdr_len = ip->ip_hl << 2;
	icmp = (struct icmp *)(s + iphdr_len);
	c -= iphdr_len;
	if (c < 8)
	{
		printf("Packet too small\n");
		return (1);
	}
	if (icmp->icmp_type == ICMP_ECHOREPLY && icmp->icmp_id == p->pid)
	{
		p->n_rcv++;
		time = (struct timeval *)icmp->icmp_data;
		new = rtt(time);
		triptime = new->tv_sec * 1000000 + new->tv_usec;
		if (p->host_flag)
		{
			if (!p->q)
			{
				printf("%d bytes from %s (%s): icmp_seq=%d ttl=%d time=",
				c,
				p->target,
				p->host,
				icmp->icmp_seq,
				ip->ip_ttl);
				print_rtt(triptime);
			}
		}
		else
		{
			if (!p->q)
			{
				printf("%d bytes from %s: icmp_seq=%d ttl=%d time=",
				c,
				p->host,
				icmp->icmp_seq,
				ip->ip_ttl);
				print_rtt(triptime);
			}
		}
		p->min = (!p->min || p->min > triptime) ? triptime : p->min;
		p->max = (p->max > triptime) ? p->max : triptime;
		p->sum += triptime;
		p->sum2 += (long long)triptime * (long long)triptime;
		gettimeofday(&(p->last_trip), NULL);
		if (!p->q)
			printf("\n");
		if (p->a)
			write(1, &a, 1);
		return (0);
	}
	if (icmp->icmp_type == ICMP_ECHOREPLY && icmp->icmp_id != p->pid)
		return (2);
	if (icmp->icmp_type == ICMP_ECHO && icmp->icmp_id == p->pid)
		return (2);
		if (p->v)
		print_verbose(icmp, c, from);
	return (1);

}

static void	recv_reply(int icmp_sock, t_ping *p)
{
	struct msghdr		msg;
	struct iovec		iov;
	struct sockaddr_in	from;
	int			count;
	int			ret;

	ret = 1;
	ft_bzero(&from, sizeof(from));
	ft_bzero(&msg, sizeof(msg));
	ft_bzero(&iov, sizeof(iov));
	set_msg(&msg, &iov, &from);
	ft_bzero(iov.iov_base, 1024);
	count = recvmsg(icmp_sock, &msg, 0);
	ret = print_packet(iov.iov_base, count, p, from);
	if (ret == 2)
		recv_reply(icmp_sock, p);
	else
		p->seq++;
}

static unsigned short	cksum(unsigned short *addr, int len)
{
	int		nleft;
	int		sum;
	unsigned short	*w;
	unsigned short	answer;

	w = addr;
	answer = 0;
	nleft = len;
	sum = 0;
	while (nleft > 1) 
	{
		sum += *w++;
		nleft -= 2;
	}
	if (nleft == 1)
	{
		*(unsigned char *)(&answer) = *(unsigned char *)w;
		sum += answer;
	}
	sum = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	answer = ~sum;	
	return (answer);
}

static int		set_packet(t_ping *p)
{
	int			packet_len;
	struct timeval		*time;

	packet_len = 0;
	set_icmp(p->icmp, p->seq, p->pid);
	packet_len = ICMP_MINLEN + DEFDATALEN;
	time = (struct timeval *)p->icmp->icmp_data;
	gettimeofday(time, NULL);
	p->icmp->icmp_cksum = cksum((unsigned short *)p->icmp, packet_len);
	return (packet_len);
}

void		pinger(void)
{
	struct sockaddr_in	co;
	int			packet_len;

	co.sin_family = AF_INET;
	inet_pton(AF_INET, p->host, &co.sin_addr);
	packet_len = set_packet(p);
	if (sendto(p->icmp_sock, p->icmp, packet_len, 0,
		(struct sockaddr *)&co, sizeof(struct sockaddr)) == -1)
		ft_error("Error: sendto.");
	p->n_sent++;
	recv_reply(p->icmp_sock, p);
	if (p->c && p->n_sent == p->c + 1)
	{
		statistic();
		exit(0);
	}
}

void			ping(t_ping *p)
{
	if (getuid())
		ft_error("Error: Root privelidges needed");
	if ((p->icmp_sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1)
		ft_error("Error: socket1");
	if (setsockopt(p->icmp_sock, SOL_IP, IP_TTL, &p->ttl, sizeof(p->ttl)) == -1)
		ft_error("Error: setsockopt");
	gettimeofday(&p->start, NULL);
	p->pid = getpid();
	printf("PING %s (%s): 56(84) bytes of data.\n", p->target, p->host);
	p->n_rcv = 1;
	p->n_sent = 1;
	p->seq = 1;
	pinger();
	alarm(p->i);
	while (42)
		;
}
