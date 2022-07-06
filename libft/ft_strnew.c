/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:21:14 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/09 17:59:04 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	size = size + 1;
	ptr = (char *)malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', size);
	return (ptr);
}
