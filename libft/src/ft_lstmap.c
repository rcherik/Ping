/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:39:07 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:54 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*s;
	t_list	*ret;

	if (!lst || !f)
		return (NULL);
	s = NULL;
	while (lst)
	{
		if (!s)
		{
			s = (*f)(lst);
			ret = s;
			lst = lst->next;
		}
		else
		{
			s->next = (*f)(lst);
			lst = lst->next;
			s = s->next;
		}
	}
	return (ret);
}
