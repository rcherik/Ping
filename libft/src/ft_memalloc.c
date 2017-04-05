/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:39:10 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:54 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*s;
	char	*tmp;

	s = malloc(size);
	if (!s)
		return (NULL);
	tmp = s;
	while (size--)
		*tmp++ = 0;
	return (s);
}
