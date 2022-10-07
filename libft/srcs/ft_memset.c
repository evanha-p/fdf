/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:33:02 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/16 19:02:24 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *source, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)source)[i] = (unsigned char)c;
		i++;
	}
	return (source);
}
