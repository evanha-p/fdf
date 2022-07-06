/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:39:01 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/09 19:43:06 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	ret = ft_strnew(ft_strlen(str1) + ft_strlen(str2));
	if (!ret)
		return (NULL);
	while (str1[i])
	{
		ret[j] = str1[i];
		i++;
		j++;
	}
	i = 0;
	while (str2[i])
	{
		ret[j] = str2[i];
		i++;
		j++;
	}
	return (ret);
}
