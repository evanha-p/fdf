/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:53:13 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/16 19:57:25 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *string, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!string)
		return (NULL);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	while (len)
	{
		ret[i] = string[start];
		start++;
		i++;
		len--;
	}
	return (ret);
}
