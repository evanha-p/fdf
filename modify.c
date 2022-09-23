/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:48:35 by evanha-p          #+#    #+#             */
/*   Updated: 2022/09/23 19:59:38 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*zoom_points(t_point *point, float zoom)
{
	t_point	*head;

	head = point;
	while (point)
	{
		point->x *= zoom;
		point->y *= zoom;
		point = point->next;
	}
	return (head);
}

t_point *move_points(t_point *point, int x, int y)
{
	t_point	*head;

	head = point;
	while (point)
	{
		point->x += x;
		point->y += y;
		point = point->next;
	}
	return (head);
}

t_point	*scope(t_point *point, t_var *v)
{
	t_point	*tmp;

	tmp = point;
	if (v->y_coord >= v->x_coord)
		v->multiplier = 500 / v->y_coord;
	else
		v->multiplier = 500 / v->x_coord;
	while (point)
	{
		point->x *= v->multiplier;
		point->y *= v->multiplier;
		point = point->next;
	}
	return (tmp);
}

t_point *center(t_point *point, t_var *v)
{
	t_point	*head;
	float	mid_x;
	float	mid_y;

	head = point;
	mid_x = v->x_coord / 2;
	mid_y = v->y_coord / 2;
	while (point)
	{
		point->x = point->x + 500 - mid_x;
		point->y = point->y + 500 - mid_y;
		point = point->next;
	}
	return (head);
}

t_point	*cartesian_to_isometric(t_point *points)
{
	t_point	*temp;
	float	x;
	float	y;

	temp = points;
	while(points)
	{
		x = points->x;
		y = points->y;
		points->x = x - y;
		points->y = (x + y) / 2 - points->z;
		points = points->next;
	}
	points = temp;
	return (points);
}
