/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:53:43 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/20 19:16:39 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

/*
 *This function uses bresenham's algorithm to decide whether to increment the
 *value of y or not.
 *
 *We need variables for the change of x (here v.delta_x)
 *and for the change of y (here v.delta_y).
 *We also use a variable (here v.bresenham) which decides whether we
 *increment the y or not.
 *
 *First we calculate the initial v.bresenham and, draw a pixel and
 *then check if the v.bresenham was positive or negative and react accordingly.
 *
 *The derivation process for the algorithms is relatively simple albeit a long
 *one so I don't have space to show it here.
 *
 *In general bresenham's algorithm checks if we are closer to the pixel
 *below or above and reacts accordingly. You have to imagine a "space"
 *between the pixels for this to make sense.
 *Example:
 *
 *    .---.
 *    |   | <- pixel 2 (x, y + 1)
 *    '---'
 *      |  <- distance 2
 *      x  <- actual location for the point according to line equation y = mx + c
 *      |
 *      |  <- distance 1
 *    .---.
 *    |   | <- pixel 1 (x, y)
 *    '---'
 *We choose the pixel which is closest to the actual location (the x).
 *To do this we can calcutale distance 1 - distance 2. If the result
 *is negative, we know distance 1 is shorter so we choose pixel below the other
 *and don't inceremnt the y value.
 *If the result is positive distance 2 is shorter and we choose the pixel above
 *the other (check the else statement below where we increment the v.y_coord).
 *
 *The variable v.bresenham = distance 1 - distance 2. So that's why
 *if v.bresenham is negative, we don't increment the y and if it is positive
 *we do incerement the y.
 *
 *!!Note!!:
 *the function below only works for lines where m (=the slope) < 1.
 */

void	draw_bresenham(t_mlx *mlx, t_line *line)
{
	t_var	v;

	initialize_variables(&v);
	v.delta_x = line->end_x - line->start_x;
	v.delta_y = line->end_y - line->start_y;
	v.x_coord = line->start_x;
	v.y_coord = line->start_y;
	v.bresenham = 2 * v.delta_y - v.delta_x;
	while (v.x_coord <= line->end_x)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, v.x_coord, v.y_coord, 0xFFFFFF);
		if (v.bresenham < 0)
			v.bresenham = v.bresenham + 2 * v.delta_y;
		else
		{
			v.bresenham = v.bresenham + 2 * v.delta_y - 2 * v.delta_x;
			v.y_coord++;
		}
		v.x_coord++;
	}
}
