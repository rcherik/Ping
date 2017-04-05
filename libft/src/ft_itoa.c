/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:38:58 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:54 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

static int	ft_numsize(int n)
{
	int		i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static void	ft_fillnbr(char *s, int n, int size)
{
	s[size] = '\0';
	while (size > 0)
	{
		s[size - 1] = (n % 10) + 48;
		size--;
		n /= 10;
	}
}

char		*ft_itoa(int n)
{
	char	*s;
	char	*ptr;
	int		is_neg;
	int		size;

	if (n == -2147483648)
		return ("-2147483648");
	is_neg = 0;
	if (n < 0)
	{
		n = n * -1;
		is_neg = 1;
	}
	size = ft_numsize(n);
	s = (char *)malloc(size + 1);
	if (!s)
		return (NULL);
	ptr = s;
	if (is_neg)
		*(s++) = '-';
	ft_fillnbr(s, n, size);
	return (ptr);
}
