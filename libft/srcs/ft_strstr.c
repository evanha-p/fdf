/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:06:23 by evanha-p          #+#    #+#             */
/*   Updated: 2021/11/22 20:16:58 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *picture, const char *waldo)
{
	int		i;
	size_t	j;
	int		copy;

	i = 0;
	j = 0;
	copy = 0;
	if (ft_strlen(waldo) == 0)
		return ((char *)picture);
	while (picture[i])
	{
		copy = i;
		while ((picture[i] == waldo[j]) && picture[i])
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
