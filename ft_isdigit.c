/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 09:54:12 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/12 14:03:19 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	int	digitchecker;

	digitchecker = 1;
	if (c < '0' || c > '9')
		digitchecker = 0;
	return (digitchecker);
}
