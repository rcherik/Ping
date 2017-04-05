/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:40:14 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:56 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	int				i;
	unsigned int	n;

	if (!s || !(*f))
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	n = 0;
	while (*s)
		str[i++] = (*f)(n++, *(s++));
	str[i] = '\0';
	return (str);
}
