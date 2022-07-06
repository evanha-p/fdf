/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:51:57 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/15 15:06:06 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t length)
{
	size_t		i;

	i = 0;
	if (!destination && !source && length > 0)
		return (NULL);
	if (source > destination)
	{
		while (i < length)
		{
			((char *)destination)[i] = ((char *)source)[i];
			i++;
		}
	}
	else
	{
		while (length)
		{
			((char *)destination)[length - 1] = ((char *)source)[length - 1];
			length--;
		}
	}
	return (destination);
}
