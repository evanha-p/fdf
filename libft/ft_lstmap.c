/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:43:26 by evanha-p          #+#    #+#             */
/*   Updated: 2021/12/17 16:13:43 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list	*ret;

	if (!list || !f)
		return (NULL);
	ret = f(list);
	ret->next = ft_lstmap(list->next, f);
	return (ret);
}
