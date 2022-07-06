/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:32:31 by evanha-p          #+#    #+#             */
/*   Updated: 2022/03/02 12:33:13 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	value;
	int	pre_value;
	int	sign;

	i = 0;
	value = 0;
	pre_value = 0;
	sign = 0;
	while (ft_iswspace(str[i]) != 0)
		i++;
	sign = ft_check_sign(str[i]);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		pre_value = value;
		value = value * 10 + sign * (str[i] - '0');
		if ((sign == 1 && value < pre_value)
			|| (sign == -1 && value > pre_value))
			return (-1);
		i++;
	}
	return (value);
}
