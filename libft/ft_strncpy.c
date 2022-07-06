/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:38:28 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/15 15:31:01 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *source, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(source) < len)
	{
		while (source[i])
		{
			dest[i] = source[i];
			i++;
		}
		while (i < len)
		{
			dest[i] = '\0';
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dest);
}
