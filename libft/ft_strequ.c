/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:06:32 by evanha-p          #+#    #+#             */
/*   Updated: 2021/11/29 17:43:48 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *str1, char const *str2)
{
	if (!str1 || !str2)
		return (0);
	if (ft_strcmp(str1, str2) == 0)
		return (1);
	else
		return (0);
}
