/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 09:39:06 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/12 13:58:57 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_isalpha(int c)
{
	int	alphachecker;

	alphachecker = 1;
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
		alphachecker = 0;
	return (alphachecker);
}
