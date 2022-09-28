/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:04:24 by evanha-p          #+#    #+#             */
/*   Updated: 2022/09/28 15:49:51 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			if (end->x * end->zoom > 1000 || end->x * end->zoom < 0)
				break;
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, v.x_coord, \
					(end->y * end->zoom), get_color(end->z));
			v.x_coord++;
		}
	}
	else
	{
		while (v.y_coord <= (int)(end->y * end->zoom))
		{
			if (end->y * end->zoom > 1000 || end->y * end->zoom < 0)
				break;
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (end->x * end->zoom), \
					v.y_coord, get_color(end->z));
			v.y_coord++;
		}
	}
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

void	draw_dot(t_mlx *mlx, t_point *points)
{
	t_point	*temp;

	temp = points;
	while (points)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, points->x, \
				points->y, get_color(points->z));
		points = points->next;
	}
	points = temp;
}
