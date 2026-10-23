/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:57:09 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/15 11:50:30 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_stringcounter(char const *s, char c)
{
	int	counter;
	int	i;
	int	inaword;

	i = 0;
	counter = 0;
	inaword = 0;
	while(s[i])
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

char	**ft_split(char const *s, char c)
{
	int	strcount;
	int	start;
	char	**ptr;
	int	i;
	int	j;

	strcount = ft_stringcounter(s, c);
	i = 0;
	j = 0;
	ptr = malloc(sizeof(char *) * (strcount + 1));
	if (!ptr)
		return (NULL);
	while(i < strcount)
	{
		while (s[j] && (s[j] == c))
			j++;
		start = j;
		while(s[j] && (s[j] != c))
			j++;
		ptr[i] = ft_substr(s, start, j - start);
		if (!ptr[i])
			return (NULL);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
