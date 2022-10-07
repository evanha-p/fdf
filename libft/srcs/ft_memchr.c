/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:17:12 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/16 18:46:26 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int wanted, size_t length)
{
	const unsigned char	*string;

	string = str;
	while (length)
	{
		if (*string == (unsigned char)wanted)
			return ((void *)string);
		string++;
		length--;
	}
	return (NULL);
}
