/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:11:45 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/06 19:49:41 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **node, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (!node || !del)
		return ;
	temp = *node;
	while (temp)
	{
		*node = temp;
		ft_lstdelone(node, del);
		temp = temp->next;
	}
}
