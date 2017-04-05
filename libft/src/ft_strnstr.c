/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:40:27 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:56 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

static int	ft_is_str(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n-- != 0)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
		if (s2[i] == '\0')
			return (1);
	}
	return (0);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	if (n >= ft_strlen(s1))
		n = ft_strlen(s1);
	while (i < n)
	{
		if (*s1 == *s2)
		{
			if (ft_is_str(s1, s2, (n - i)))
				return ((char *)s1);
		}
		i++;
		s1++;
	}
	return (NULL);
}
