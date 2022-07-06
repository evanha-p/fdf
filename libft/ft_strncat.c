/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:45:28 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/16 20:03:09 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *source, size_t len)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (j < len && source[j])
	{
		dest[i + j] = source[j];
		j++;
	}
	dest[j + i] = '\0';
	return (dest);
}
