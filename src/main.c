/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 13:33:28 by rcherik           #+#    #+#             */
/*   Updated: 2015/11/20 16:28:39 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ping.h"

static void	ft_usage(void)
{
	printf("Usage: ./ft_ping [-ahqv] [-c count] [-i interval] [-t Time To Live] destination\n");
	exit(2);
}

static void		get_opt(t_ping *p, char **argv, int *i)
{
	if (!ft_strcmp(argv[*i], "-v"))
		p->v = 1;
	else if (!ft_strcmp(argv[*i], "-h"))
		p->h = 1;
	else if (!ft_strcmp(argv[*i], "-a"))
		p->a = 1;
	else if (!ft_strcmp(argv[*i], "-q"))
		p->q = 1;
	else if (!ft_strcmp(argv[*i], "-c") && argv[*i + 1] && !ft_str_is_number(argv[*i + 1]))
	{
		p->c = ft_atoi(argv[*i + 1]);
		*i += 1;
	}
	else if (!ft_strcmp(argv[*i], "-t") && argv[*i + 1] && !ft_str_is_number(argv[*i + 1]))
	{
		p->ttl = ft_atoi(argv[*i + 1]);
		*i += 1;
	}
	else if (!ft_strcmp(argv[*i], "-i") && argv[*i + 1] && !ft_str_is_number(argv[*i + 1])
		&& ft_strcmp(argv[*i + 1], "0"))
	{
		p->i = ft_atoi(argv[*i + 1]);
		*i += 1;
	}
	else
		ft_usage();
}

static void		set_hints(struct addrinfo *hints)
{
	ft_bzero(hints, sizeof(struct addrinfo));
	hints->ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
	hints->ai_socktype = SOCK_DGRAM; /* Datagram socket */
	hints->ai_protocol = 0;          /* Any protocol */
	hints->ai_canonname = NULL;
	hints->ai_addr = NULL;
	hints->ai_next = NULL;
	hints->ai_flags = AI_CANONNAME;
}

static char		*get_host(char *target, int *host_flag)
{
	struct addrinfo		hints;
	struct addrinfo		*ret;
	char			buf[BUFF_SIZE];
	int			s;

	set_hints(&hints);
	*host_flag = 1;
	if ((s = getaddrinfo(target, NULL, &hints, &ret)))
		ft_error(ft_strjoin("ft_ping: unknown host ", target));
	while (ret)
	{
		if (ret->ai_family == AF_INET)
		{
			return ft_strdup(inet_ntop(ret->ai_family,
				&((struct sockaddr_in *)ret->ai_addr)->sin_addr, buf, BUFF_SIZE));
		}
		if (ret->ai_family == AF_INET6)
		{
			printf("hostname: %s\n", ret->ai_canonname);
			printf("Addr6 = %s\n", inet_ntop(ret->ai_family,
				&((struct sockaddr_in6 *)ret->ai_addr)->sin6_addr, buf, BUFF_SIZE));
		}
		ret = ret->ai_next;
	}
	return (NULL);
}

static void		check_opt(t_ping *p, int argc, char **argv)
{
	int		i;
	struct in_addr	tmp;

	i = 1;
	while (argv[i] && argv[i][0] == '-' && i < argc)
	{
		if (!ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "-h")
			|| !ft_strcmp(argv[i], "-a") || !ft_strcmp(argv[i], "-c")
			|| !ft_strcmp(argv[i], "-q")
			|| !ft_strcmp(argv[i], "-t")
			|| !ft_strcmp(argv[i], "-i"))
			get_opt(p, argv, &i);
		else
			ft_usage();
		i++;
	}
	if (i + 1 != argc)
		ft_usage();
	p->target = ft_strdup(argv[i]);
	if (!(inet_pton(AF_INET, p->target, &tmp)))
		p->host = get_host(p->target, &p->host_flag);
	else
		p->host = p->target;
}

int				main(int argc, char **argv)
{
	signal(SIGALRM, ft_sig_handler);
	signal(SIGINT, ft_sig_handler);
	if (argc < 2)
		ft_usage();
	p = (t_ping *)malloc(sizeof(t_ping));
	ft_bzero(p, sizeof(t_ping));
	p->icmp = (struct icmp *)malloc(sizeof(struct icmp));
	p->i = 1;
	p->ttl = 64;
	check_opt(p, argc, argv);
	if (p->h)
		ft_usage();
	ping(p);
	return (0);
}
