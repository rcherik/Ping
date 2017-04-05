/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 13:34:17 by rcherik           #+#    #+#             */
/*   Updated: 2015/11/20 15:29:47 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PING_H
# define PING_H

# include "libft.h"
# include <unistd.h>
# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdio.h>
# include <netinet/ip.h>
# include <netinet/ip_icmp.h>
# include <sys/time.h>
# include <stdlib.h>
# include <netdb.h>
# include <signal.h>

# define DEFDATALEN 56
# define BUFF_SIZE 1024

typedef struct		s_ping
{
	int		v;
	int		h;
	int		a;
	int		c;
	int		q;
	int		i;
	int		ttl;
	int		seq;
	int		pid;
	char		*target;
	char		*host;
	struct icmp	*icmp;
	int		host_flag;
	int		icmp_sock;
	int		n_sent;
	int		n_rcv;
	long		min;
	long		max;
	long long	sum;
	long long	sum2;
	struct timeval	start;
	struct timeval	last_trip;
}			t_ping;

t_ping			*p;

void			ft_error(char *s);
void			ping(t_ping *p);
void			ft_sig_handler(int sig);
void			pinger(void);
void			statistic(void);
void			print_rtt(long triptime);
void			error_message(struct msghdr msg);
struct timeval		*rtt(struct timeval *time);

#endif
