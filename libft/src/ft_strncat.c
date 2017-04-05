/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:40:16 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:56 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if (n < ft_strlen(s2))
	{
		while (n--)
		{
			s1[i++] = *s2;
			s2++;
		}
	}
	else
	{
		while (*s2 != '\0')
		{
			s1[i++] = *s2;
			s2++;
		}
	}
	s1[i] = '\0';
	return (s1);
}
