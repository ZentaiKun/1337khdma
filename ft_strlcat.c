/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:52:49 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/12 15:41:30 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	destlen;

	i = 0;
	destlen = 0;
	srclen = ft_strlen(src);
	while (dest[destlen] && destlen < size)
		destlen++;
	if (size <= destlen)
		return (size + srclen);
	while ((destlen + i) < (size - 1) && src[i])
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
