/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:39:12 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:54 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*str1;
	const char	*str2;

	str1 = s1;
	str2 = s2;
	while (n-- != 0)
	{
		if (*str2 != c)
		{
			*str1 = *str2;
			str1++;
			str2++;
		}
		else
		{
			*(str1++) = *str2;
			return (str1);
		}
	}
	return (NULL);
}
