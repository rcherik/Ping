/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:40:32 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:56 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;

	if (*s2 == '\0')
		return ((char *)s1);
	i = ft_strlen(s2);
	while (*s1 != '\0')
	{
		if (ft_strncmp(s2, s1, i) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
