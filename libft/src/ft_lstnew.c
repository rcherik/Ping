/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:39:08 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:54 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (content_size >= 65535)
		return (NULL);
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	else
	{
		if (content_size > 0)
		{
			new->content = (void *)malloc(content_size);
			new->content = ft_memcpy(new->content, content, content_size);
		}
		else
			new->content = NULL;
		new->content_size = content_size;
		new->next = NULL;
	}
	return (new);
}
