/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:38:37 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:54 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	is_ng;
	int	val;

	val = 0;
	is_ng = 0;
	if (!ft_strcmp(str, "-2147483648"))
		return (-2147483648);
	while (*str && (*str == ' ' || *str == '\t' || *str == '\v' ||
				*str == '\r' || *str == '\f' || *str == '\n'))
		str++;
	is_ng = (*str == '-') ? 1 : 0;
	if (*str && (*str == '-' || *str == '+'))
		str++;
	while (*str && ft_isdigit(*str))
	{
		val = (val * 10) + ((*str - 48) % 10);
		str++;
	}
	if (is_ng)
		val = val * -1;
	return (val);
}
