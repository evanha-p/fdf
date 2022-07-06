/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:33:09 by evanha-p          #+#    #+#             */
/*   Updated: 2021/11/25 09:55:58 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *picture, const char *waldo, size_t length)
{
	size_t	i;
	size_t	j;
	size_t	copy;

	i = 0;
	j = 0;
	copy = 0;
	if (ft_strlen(waldo) == 0)
		return ((char *)picture);
	while (i < length && picture[i])
	{
		copy = i;
		while ((picture[i] == waldo[j]) && picture[i] && i < length)
		{
			i++;
			j++;
		}
		if (j == ft_strlen(waldo))
			return ((char *)&picture[i - j]);
		i = copy;
		j = 0;
		i++;
	}
	return (NULL);
}
