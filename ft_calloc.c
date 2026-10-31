/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 08:35:43 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/15 08:58:14 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (nitems == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (nitems > (((size_t) - 1) / size))
		return (NULL);
	ptr = malloc(size * nitems);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nitems);
	return (ptr);
}
