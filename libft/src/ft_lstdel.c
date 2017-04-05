/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:39:01 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:54 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**list_ptr;
	t_list	*lst;

	list_ptr = alst;
	if (!alst || !del)
		return ;
	while (*alst && del)
	{
		lst = *alst;
		*alst = (*alst)->next;
		(*del)(lst->content, lst->content_size);
		free(lst);
		lst = NULL;
	}
	(void)list_ptr;
	list_ptr = NULL;
}
