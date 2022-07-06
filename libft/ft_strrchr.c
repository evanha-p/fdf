/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:03:41 by evanha-p          #+#    #+#             */
/*   Updated: 2021/11/23 16:30:01 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int wanted)
{
	int	len;

	if (ft_strlen(str) == 0)
	{
		if (str[0] == wanted)
			return ((char *)str);
		else
			return (NULL);
	}
	else
		len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == wanted)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}
