/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:04:24 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/07 15:15:14 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Goes through the linked list and sets the pointer below to
point to the point which has the same x -value as the current
one. This information is needed when we draw the map.

Example:

1 0 0 5 0 0
0 0 0 2 0 0
9 9 9 9 9 9

Let's assume we are in the first row in a point, which height
value is 5. In the innermost while loop we go through the
points until we hit the point with height value of 2 since
it has the same x-value (the x-value is 3 in this example).
We set the current points (the 5) below -pointer to point
to the point with the height value of 2.

In the last row (all the height values are 9 in this example)
we obviously don't have points below so
the while loop loops until we hit the end of the list
and so next->next will be NULL. When this is detected
we set the below -pointer to also be NULL.
*/

t_point	*set_points_below(t_point *point)
{
	t_point	*head;
	t_point	*next;

	head = point;
	while (point->next)
	{
		next = point->next;
		while (point->cart_x != next->cart_x && next->next)
			next = next->next;
		if (!next->next)
			point->below = NULL;
		else
			point->below = next;
		point = point->next;
	}
	point = head;
	return (point);
}

/*Sets all variables in struct t_var to 0*/

void	initialize_variables(t_var *var)
{
	var->x_coord = 0;
	var->y_coord = 0;
	var->ret = 0;
	var->delta_x = 0;
	var->delta_y = 0;
	var->bresenham = 0;
	var->slope = 0;
	var->fd = 0;
	var->multiplier = 0;
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

/*
Function returns a color value based on the value stored
in start->color. If the value stored in color is
set to HIGHLIGHT the function returns magenta color
if either the starting or ending point is positive.
It returns white if the either one is 0. Otherwise
it returns blue.
*/

int	get_color(t_point *start, t_point *end)
{
	if (start->color == WHITE)
		return (WHITE_COL);
	else if (start->color == RED)
		return (RED_COL);
	else if (start->color == GREEN)
		return (GREEN_COL);
	else if (start->color == HIGHLIGHT)
	{
		if (start->z > 0 || end->z > 0)
			return (MAGENTA_COL);
		else if (start->z == 0 || end->z == 0)
			return (WHITE_COL);
		else
			return (BLUE_COL);
	}
	else
		return (WHITE_COL);
}
