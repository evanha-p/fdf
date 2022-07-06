/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:51:31 by evanha-p          #+#    #+#             */
/*   Updated: 2021/11/23 14:34:17 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int wanted)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == wanted)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == wanted)
		return ((char *)&str[i]);
	return (NULL);
}
