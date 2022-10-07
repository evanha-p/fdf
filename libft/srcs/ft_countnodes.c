/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:17:41 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/09 19:27:54 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countnodes(t_list *list)
{
	int		count;
	t_list	*tmp;

	if (!list)
		return (0);
	tmp = list;
	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	list = tmp;
	return (count);
}
