/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:58:23 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/02 12:38:31 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	unsigned int	start;
	size_t			len;
	size_t			len_check;
	char			*ret;

	if (!str)
		return (NULL);
	start = 0;
	len = ft_strlen(str) - 1;
	len_check = len;
	while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
		start++;
	while (str[len] == ' ' || str[len] == '\t' || str[len] == '\n')
		len--;
	if (len > len_check)
		ret = ft_strnew(0);
	else
	{
		len = len - start + 1;
		ret = ft_strsub(str, start, len);
		if (!ret)
			return (NULL);
		ret[len] = '\0';
	}
	return (ret);
}
