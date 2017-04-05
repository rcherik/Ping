/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:39:57 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:55 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strdel(char **as)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!as || !(*as))
		return ;
	tmp = *as;
	while (tmp[i])
	{
		tmp[i] = '\0';
		i++;
	}
	tmp[i] = '\0';
	free(tmp);
	*as = NULL;
}
