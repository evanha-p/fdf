/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:04:24 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/29 19:32:26 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Sets all variables in struct t_var to 0*/

void	initialize_variables(t_var *var)
{
	var->i = 0;
	var->x_coord = 0;
	var->y_coord = 0;
	var->ret = 0;
	var->length = 0;
	var->start = 0;
	var->delta_x = 0;
	var->delta_y = 0;
	var->bresenham = 0;
}

/*Creates a new point and sets the old point to point to the new point.*/

t_point	*new_point(t_point *point)
{
	t_point	*next;

	next = (t_point *)malloc(sizeof(t_point));
	if (!next)
		errors("null pointer");
	point->next = next;
	return (next);
}

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
		point->x += nudge;
		point->y += nudge;
		point = point->next;
	}
	return (tmp);
}
