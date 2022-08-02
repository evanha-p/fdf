/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:04:24 by evanha-p          #+#    #+#             */
/*   Updated: 2022/08/02 15:35:41 by evanha-p         ###   ########.fr       */
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

int	get_color(int height)
{
	if (height > 0)
		height = 0xFFFFFF - (1000 *  0xFF - height) - (0xFF - height);
	else
		height = 0xFFFFFF;
	return (height);
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

/*
 *Draw_line function uses tan a to calculate the location for y.
 *Since we can form a right triangle from one point to next
 *
 *we can use trigonometric functions to calculate value of y
 *everytime we increase the value of x by 1.
 *The right triangle is formed with:
 *- line between start and finish being the hypotenuse
 *- Difference from x at start to finish and from y at start to finish
 *  being the cathetuses
 *
 *Example:
 *                      finish
 *                         x
 *                     .   |
 *                  .      |
 *              .          | y
 *    	     .             |
 * 	     .                 |
 *     x - - - - - - - - - /
 *   start        x
 *
 *First we calcute the length of x and y (the sides of the triangle) by
 *substracting the x and y values at the end by the x and y values 
 *at the start.
 *
 *length of x = x coordinate at end - x coordinate at beginning
 *(same for the y value)
 *
 *With that we calculate tan a.
 *
 *tan a = y/x
 *
 *When we have solved tan a we can use it to calculate the values of y
 *when value of x changes.
 *
 *y = tan a * x
 *
 *Note: function above gives the amount the y value has increased.
 *So we need to add the value of y at the beginning to get the correct
 *value for the y coordinate.
 */
int	draw_line(t_mlx *mlx, t_point start, t_point end)
{
	double	distance_x;
	double	distance_y;
	double	tan_a;
	double	location_y;

	distance_x = end.x - start.x;
	distance_y = end.y - start.y;
	tan_a = distance_y / distance_x;
	distance_x = 0;
	while (start.x <= end.x)
	{
		location_y = start.y + (tan_a * distance_x);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, \
		start.x, location_y, 0xFFFFFF);
		start.x++;
		distance_x++;
	}
	return (0);
}
