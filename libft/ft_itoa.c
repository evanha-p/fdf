/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:52:24 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/09 18:39:32 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_intlen(int nb)
{
	int	len;

	len = 0;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		len++;
	}
	len++;
	if (nb < 0)
		len++;
	return (len);
}

static	void	ft_writeposint(char *str, int nb)
{
	int		len;

	len = ft_intlen(nb) - 1;
	while (nb >= 10)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	str[len] = nb + '0';
}

static	void	ft_writenegint(char *str, int nb)
{
	int		len;

	nb = nb * -1;
	len = ft_intlen(nb);
	while (nb >= 10)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	str[len] = nb + '0';
	str[0] = '-';
}

char	*ft_itoa(int nb)
{
	char	*ret;

	ret = ft_strnew(ft_intlen(nb));
	if (!ret)
		return (NULL);
	if (nb == -2147483648)
	{
		ret = ft_strcpy(ret, "-2147483648");
	}
	else if (nb >= 0)
		ft_writeposint(ret, nb);
	else
		ft_writenegint(ret, nb);
	return (ret);
}
