/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:57:09 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/23 12:15:35 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_stringcounter(char const *s, char c)
{
	int	counter;
	int	i;
	int	inaword;

	i = 0;
	counter = 0;
	inaword = 0;
	while (s[i])
	{
		if ((s[i] != c) && inaword == 0)
		{
			inaword = 1;
			counter++;
		}
		if ((s[i] == c) && inaword == 1)
			inaword = 0;
		i++;
	}
	return (counter);
}

static char	**ft_freeall(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (NULL);
}

static char	**ft_allocate_words(char const *s, char c, int strcount, char **ptr)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (i < strcount)
	{
		while (s[j] && (s[j] == c))
			j++;
		start = j;
		while (s[j] && (s[j] != c))
			j++;
		ptr[i] = ft_substr(s, start, j - start);
		if (!ptr[i])
			return (ft_freeall(ptr, i));
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		strcount;
	char	**ptr;

	if (!s)
		return (NULL);
	strcount = ft_stringcounter(s, c);
	ptr = malloc(sizeof(char *) * (strcount + 1));
	if (!ptr)
		return (NULL);
	ptr = ft_allocate_words(s, c, strcount, ptr);
	return (ptr);
}
