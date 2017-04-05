/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcherik <rcherik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:40:30 by rcherik           #+#    #+#             */
/*   Updated: 2015/01/20 15:40:56 by rcherik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static char	*ft_strsub_len(char const *s, int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	i = 0;
	sub = (char *)malloc(sizeof(*sub) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

static int	ft_count(const char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			j = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[k++] = ft_strsub_len(s, j, i - j);
		}
	}
	tab[k] = NULL;
	return (tab);
}
