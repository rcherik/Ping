/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:39:24 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:54 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*str1;
	const char	*str2;

	str1 = s1;
	str2 = s2;
	if (str2 < str1)
	{
		while (n--)
			*(str1 + n) = *(str2 + n);
	}
	else
		ft_memcpy(str1, str2, n);
	return (s1);
}
