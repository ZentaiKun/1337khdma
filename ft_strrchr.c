/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 16:46:02 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/12 16:55:12 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	index;

	i = 0;
	index = -1;
	while (str[i])
	{
		if (str[i] == (char)c)
			index = i;
		i++;
	}
	if (str[i] == (char)c)
	{
		index = i;
		return ((char *)(str + index));
	}
	if (index == -1)
		return (NULL);
	return ((char *)(str + index));
}
