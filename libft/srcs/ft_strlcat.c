/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:03:26 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/02 12:35:13 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t dest_size)
{
	size_t	i;
	size_t	j;
	int		dest_len;
	int		int_size;
	size_t	ret;

	i = ft_strlen(dest);
	j = 0;
	dest_len = i;
	int_size = dest_size;
	if (dest_size > ft_strlen(dest))
		ret = ft_strlen(dest) + ft_strlen(source);
	else
		ret = dest_size + ft_strlen(source);
	while (int_size - (dest_len + 1) > 0 && source[j])
	{
		dest[i] = source[j];
		i++;
		j++;
		int_size--;
	}
	dest[i] = '\0';
	return (ret);
}
