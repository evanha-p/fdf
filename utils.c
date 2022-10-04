/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:04:24 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/04 19:38:03 by evanha-p         ###   ########.fr       */
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
	return (head);
}

/*
Sets point->x and point->y values to the original
values they were after sent to the function scope.
Also sets the zoom back to its original value of 1.
*/

t_point	*reset_values(t_point *point)
{
	t_point	*head;

	head = point;
	while (point)
	{
		point->x = point->cart_x;
		point->y = point->cart_y;
		point->zoom = 1;
		point = point->next;
	}
	return (head);
}

/*Sets all variables in struct t_var to 0*/

void	initialize_variables(t_var *var)
{
	var->x_coord = 0;
	var->y_coord = 0;
	var->ret = 0;
	var->start = 0;
	var->delta_x = 0;
	var->delta_y = 0;
	var->bresenham = 0;
	var->slope = 0;
	var->fd = 0;
	var->multiplier = 0;
	var->max_x = 0;
	var->min_x = 0;
	var->max_y = 0;
	var->min_y = 0;
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

int	get_color(int height)
{
	if (height)
		return (0xFFFFFF);
	else
		return (0xFFFFFF);
}

/*Helper function for draw_straight. Does the drawing.*/

void	drawing_loop(t_point *start, t_point *end, t_mlx *mlx, char *str)
{
	t_var	v;

	initialize_variables(&v);
	v.x_coord = start->x * start->zoom;
	v.y_coord = start->y * start->zoom;
	if (!(ft_strcmp("horizontal", str)))
	{
		while (v.x_coord <= (int)(end->x * end->zoom))
		{
			if (!(v.x_coord > 1000 || v.x_coord < 0))
				mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, v.x_coord, \
						(end->y * end->zoom), get_color(end->z));
			v.x_coord++;
		}
	}
	else
	{
		while (v.y_coord <= (int)(end->y * end->zoom))
		{
			if (!(v.y_coord > 1000 || v.y_coord < 0))
				mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (end->x * end->zoom), \
						v.y_coord, get_color(end->z));
			v.y_coord++;
		}
	}
}
