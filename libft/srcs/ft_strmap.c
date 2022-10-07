/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:28:32 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/09 18:00:27 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	char	*ret;
	char	temp;
	int		i;

	i = 0;
	if (!str || !f)
		return (NULL);
	ret = ft_strnew(ft_strlen(str));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		temp = str[i];
		ret[i] = f(temp);
		i++;
	}
	return (ret);
}
