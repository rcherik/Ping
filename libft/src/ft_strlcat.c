/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:40:09 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:56 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (ft_strlen(dst) >= size)
	{
		i = size + ft_strlen(src);
		return (i);
	}
	else
		i = ft_strlen(dst) + ft_strlen(src);
	if (i >= size)
	{
		ft_strncat(dst, src, (size - ft_strlen(dst) - 1));
		return (i);
	}
	else
	{
		ft_strcat(dst, src);
		return (i);
	}
}
