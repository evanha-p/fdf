/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:51:39 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/09 19:35:49 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **node, void (*del)(void *, size_t))
{
	if (!node || !del)
		return ;
	del((*node)->content, (*node)->content_size);
	free(*node);
	*node = NULL;
}
