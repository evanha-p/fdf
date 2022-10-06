/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:39:56 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/06 17:03:43 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_pointers(t_ptrs *pointers)
{
	t_point	*prev;

	while (pointers->point)
	{
		prev = pointers->point;
		ft_bzero(prev, sizeof(t_point *));
		free(prev);
		pointers->point = pointers->point->next;
	}
	ft_bzero(pointers->mlx, sizeof(t_mlx *));
	free(pointers->mlx);
	free(pointers->v);
	free(pointers);
}
