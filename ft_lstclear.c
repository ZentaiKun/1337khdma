/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 10:59:13 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/18 11:48:16 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*currentptr;
	t_list		*nextptr;

	if (!lst || !del)
		return ;
	if (*lst == NULL)
		return ;
	currentptr = *lst;
	while (currentptr)
	{
		nextptr = currentptr->next;
		del(currentptr->content);
		free(currentptr);
		currentptr = nextptr;
	}
	*lst = NULL;
}
