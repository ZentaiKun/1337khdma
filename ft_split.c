/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzouhri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:57:09 by zzouhri           #+#    #+#             */
/*   Updated: 2026/10/15 11:50:30 by zzouhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.c"

int	ft_isdelimiter(char com, char c)
{
	if (com == c)
		return (1);
	else
		return (0);
}
int	ft_stringcounter(char const *s, char c)
{
	int	counter;
	int	i;
	int	inaword;

	i = 0;
	counter = 0;
	inaword = 0;
	while(s[i])
	{
		if (!ft_isdelimiter(s[i], c) && inaword == 0)
		{
			inaword = 1;
			counter++;
		}
		if (ft_isdelimiter(s[i], c) && inaword == 1)
			inaword = 0;
		i++;
	}
	return (counter);
}
int	ft_strlendelim(char const *s,char c)
{
	int	i;

	i = 0;
	while (s[i] && !ft_isdelimiter(s[i], c))
		i++;
	return (i);
}
char	*ft_strmaker(char const *s,char c,int length)
{
	char	*ptr;
	int	i;

	i = 0;
	ptr = malloc(length + 1);
	if (!ptr)
		return (NULL);
	while (s[i] && !ft_isdelimiter(s[i], c))
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
char	**ft_split(char const *s, char c)
{
	int	strcount;
	char	**ptr;
	int	i;
	int	j;

	strcount = ft_stringcounter(s, c);
	i = 0;
	j = 0;
	ptr = malloc(sizeof(char *) * (strcount + 1));
	if (!ptr)
		return (NULL);
	while(i < strcount)
	{
		while (s[j] && ft_isdelimiter(s[j], c))
			j++;
		ptr[i] = ft_strmaker(&s[j], c, ft_strlendelim(&s[j], c));
		while(s[j] && !ft_isdelimiter(s[j], c))
			j++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
	
	
