/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 11:56:57 by rcherik           #+#    #+#             */
/*   Updated: 2015/02/28 11:09:11 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_newtab(size_t len)
{
	char		**tmp;

	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	ft_bzero(tmp, sizeof(char *) * (len + 1));
	return (tmp);
}
