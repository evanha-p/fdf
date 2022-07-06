/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:10:20 by evanha-p          #+#    #+#             */
/*   Updated: 2021/11/26 16:23:01 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *str1, char const *str2, size_t len)
{
	if (!str1 || !str2)
		return (0);
	if (ft_strncmp(str1, str2, len) == 0)
		return (1);
	else
		return (0);
}
