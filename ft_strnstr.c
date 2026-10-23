/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:43:27 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/23 12:06:54 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (i + j < len && big[i + j] && little[j])
		{
			if (big[i + j] == little[j])
				j++;
			else
				break ;
		}
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
