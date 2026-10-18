/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:25:12 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/15 10:49:31 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isinset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	start = 0;
	end = ft_strlen(s1);
	end--;
	while (s1[start] && ft_isinset(s1[start], set))
		start++;
	while (end > 0 && ft_isinset(s1[end], set))
		end--;
	if (start > end)
		ptr = ft_substr(s1, 0, 0);
	else
		ptr = ft_substr(s1, start, end - start + 1);
	return (ptr);
}
