/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:53:43 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/06 16:10:47 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
 * Draw_line function uses tan a to calculate the location for y.
 * Since we can form a right triangle from one point to next
 * we can use trigonometric functions to calculate value of y
 * everytime we increase the value of x by 1.
 * The right triangle is formed with:
 * - line between start and finish being the hypotenuse
 * - Difference from x at start to finish and from y at start to finish
 *   being the cathetuses
 * 
 * Example:
 *                    finish
 *                       x
 *                   .   |
 *                .      |
 *            .          | y
 *         .             |
 *     .                 |
 *   x - - - - - - - - - /
 * start        x
 *
 * First we calcute the length of x and y (the sides of the triangle) by
 * substracting the x and y values at the end by the x and y values at the start.
 *
 * length of x = x coordinate  at end - x coordinate  at beginning (same for the y value)
 *
 * With that we calculate tan a.
 *
 * tan a = y/x
 *
 * When we have solved tan a we can use it to calculate the values of y
 * when value of x changes.
 *
 * y = tan a * x
 *
 * Note: function above gives the amount the y value has increased.
 * So we need to add the value of y at the beginning to get the correct
 * value for the y coordinate.
 */

int	draw_line(t_mlx *mlx, t_line *line)
{
	double	distance_x;
	double	distance_y;
	double	tan_a;
	double	location_y;

	distance_x = line->end_x - line->start_x;
	distance_y = line->end_y - line->start_y;
	tan_a = distance_y / distance_x;
	distance_x = 0;
	while (line->start_x <= line->end_x)
	{
		location_y = line->start_y + (tan_a * distance_x);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, \
		line->start_x, location_y, 0xFFFFFF);
		line->start_x++;
		distance_x++;
	}
	return (0);
}
