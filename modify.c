/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:48:35 by evanha-p          #+#    #+#             */
/*   Updated: 2022/08/04 16:33:49 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*scope(int scope, t_point *point)
{
	t_point	*tmp;

	tmp = point;
	while (point)
	{
		point->x *= scope;
		point->y *= scope;
		point = point->next;
	}
	return (tmp);
}

t_point	*nudge(int nudge, t_point *point)
{
	t_point	*tmp;

	tmp = point;
	while (point)
	{
		point->x = point->x + point->x + 1.5 * nudge;
		point->y += point->y;
		point = point->next;
	}
	return (tmp);
}

t_point	*cartesian_to_isometric(t_point *points)
{
	t_point	*temp;
	int		x;
	int		y;

	temp = points;
	while(points)
	{
		x = points->x;
		y = points->y;
		points->x = x - y;
		points->y = (x + y) / 2;
		/*points->x = (x - points->z) / sqrt(2);*/
		/*points->y = (x + y + y + points->z) / sqrt(6);*/
		points = points->next;
	}
	points = temp;
	return (points);
}
