/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:39:33 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/09 18:00:43 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*ret;
	char			temp;
	unsigned int	i;

	i = 0;
	if (!str || !f)
		return (NULL);
	ret = ft_strnew(ft_strlen(str));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		temp = str[i];
		ret[i] = f(i, temp);
		i++;
	}
	return (ret);
}
