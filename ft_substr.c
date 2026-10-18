/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 09:11:41 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/15 09:51:12 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	strlength;
	size_t	i;
	size_t	allocationsize;
	char	*ptr;

	i = 0;
	strlength = ft_strlen(s);
	allocationsize = len;
	if (start > strlength)
		allocationsize = 0;
	else if (len > (strlength - start))
		allocationsize = strlength - start;
	ptr = malloc(allocationsize + 1);
	if (!ptr)
		return (NULL);
	while (i < allocationsize && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
