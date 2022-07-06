/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:01:08 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/17 15:52:45 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrclean(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		ft_bzero(arr[i], ft_strlen(arr[i]));
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}
