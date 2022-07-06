/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:07:50 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/02 12:37:51 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_word_count(char const *str, char deli)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != deli && i == 0)
			words++;
		else if (str[i] == deli && str[i + 1] && str[i + 1] != deli)
		{
			words++;
			i++;
			while (str[i] != deli && str[i])
				i++;
			i--;
		}
		i++;
	}
	return (words);
}

static	char	*ft_write_string(char const *str, char deli, int i)
{
	int		temp;
	int		j;
	size_t	len;
	char	*ret;

	temp = i;
	j = 0;
	len = 0;
	while (str[i] != deli && str[i])
	{
		len++;
		i++;
	}
	ret = ft_strnew(len);
	i = temp;
	while (str[i] != deli && str[i] && ret != NULL)
	{
		ret[j] = str[i];
		j++;
		i++;
	}
	return (ret);
}

static	int	ft_skipper(char const *str, char deli, int i)
{
	while (str[i] != deli && str[i])
		i++;
	return (i);
}

static	char	**ft_splitter(char const *str, char deli,
		int *i_count, char **ret)
{
	while (str[i_count[0]])
	{
		if (str[i_count[0]] != deli && i_count[0] == 0)
		{
			ret[i_count[1]] = ft_write_string(str, deli, i_count[0]);
			if (!ret[i_count[1]++])
				return (ft_arrclean(ret));
		}
		else if (str[i_count[0]] == deli && str[i_count[0] + 1]
			&& str[i_count[0] + 1] != deli)
		{
			ret[i_count[1]] = ft_write_string(str, deli, i_count[0] + 1);
			if (!ret[i_count[1]++])
				return (ft_arrclean(ret));
			i_count[0] = ft_skipper(str, deli, i_count[0] + 1) - 1;
		}
		i_count[0]++;
	}
	ret[i_count[1]] = NULL;
	return (ret);
}

char	**ft_strsplit(char const *str, char deli)
{
	int		i_count[2];
	char	**ret;

	ft_memset(i_count, 0, sizeof(i_count));
	if (!str)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * ft_word_count(str, deli) + 1);
	if (!ret)
		return (NULL);
	ret = ft_splitter(str, deli, i_count, ret);
	return (ret);
}
