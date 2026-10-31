/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 09:22:19 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/31 09:55:52 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_intlen(long ln)
{
	int	len;

	len = 0;
	if (ln == 0)
		return (1);
	if (ln < 0)
		len++;
	while (ln != 0)
	{
		ln = ln / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	long		ln;
	char		*ptr;

	ln = n;
	len = ft_intlen(ln);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (ln == 0)
		ptr[0] = 0 + '0';
	if (ln < 0)
	{
		ptr[0] = '-';
		ln = ln * (-1);
	}
	while (ln > 0)
	{
		ptr[--len] = ln % 10 + '0';
		ln = ln / 10;
	}
	return (ptr);
}
