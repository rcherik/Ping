/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:39:48 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:54 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	f;

	f = (char)c;
	while (*s)
	{
		if (*s == f)
			return ((char *)s);
		s++;
	}
	if (*s == f)
		return ((char *)s);
	else
		return (NULL);
}
