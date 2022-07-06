/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:39:30 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/09 19:13:14 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t len)
{
	int	i;

	i = 0;
	if (!dest && !source && len > 0)
		return (NULL);
	while (len)
	{
		((char *)dest)[i] = ((char *)source)[i];
		i++;
		len--;
	}
	return (dest);
}
