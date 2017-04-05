/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:40:22 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:56 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		rest;

	i = 0;
	rest = 0;
	if (n >= ft_strlen(s2))
	{
		rest = n - ft_strlen(s2);
		n = ft_strlen(s2);
	}
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	if (rest > 0)
	{
		while (rest-- >= 0)
		{
			s1[i++] = '\0';
		}
	}
	return (s1);
}
