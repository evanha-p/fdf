/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:53:43 by evanha-p          #+#    #+#             */
/*   Updated: 2022/08/02 15:07:17 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
This function gets called if the slope = 0.
So the function only draws "straight" lines where the
value of y stays the same.
*/

void	draw_straight(t_mlx *mlx, t_point *start, t_point *end)
{
	t_var	v;

	initialize_variables(&v);
	v.x_coord = start->x;
	while (v.x_coord <= end->x)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, v.x_coord, \
				start->y, get_color(end->z));
		v.x_coord++;
	}
}
/*
This function uses bresenham's algorithm to decide whether to increment the
value of y or not.

We need variables for the change of x (here v.delta_x)
and for the change of y (here v.delta_y).
We also use a variable (here v.bresenham) which decides whether we
increment the y or not.

First we calculate the initial v.bresenham and, draw a pixel and
then check if the v.bresenham was positive or negative and react accordingly.

The derivation process for the algorithms is relatively simple albeit a long
one so I don't have space to show it here.

In general bresenham's algorithm deals with situations where
the actual line goes through two pixels (so basically every case where
the slope is other than 1). Since we can only choose
one of the pixels we have to decide which one to choose.
The algorithm checks if we are closer to the pixel
below or above and reacts accordingly. You have to imagine a "space"
between the pixels for this to make sense.
Example:

	.---.
	|   | <- pixel 2 (x, y + 1)
	'---'
	  |  <- distance 2
	  x  <- actual location for the point according to line equation y = mx + c
	  |
	  |  <- distance 1
	.---.
	|   | <- pixel 1 (x, y)
	'---'
We choose the pixel which is closest to the actual location (the x).
To do this we can calcutale distance 1 - distance 2. If the result
is negative, we know distance 1 is shorter so we choose pixel below the other
and don't inceremnt the y value.
If the result is positive distance 2 is shorter and we choose the pixel above
the other (check the else statement below where we increment the v.y_coord).

The variable v.bresenham = distance 1 - distance 2. So that's why
if v.bresenham is negative, we don't increment the y and if it is positive
we do incerement the y.

!!Note!!:
the function below only works for lines where 0 < slope(=m) < 1.
*/

void	gentle_slope(t_mlx *mlx, t_point *end, t_var v)
{
	v.bresenham = 2 * v.delta_y - v.delta_x;
	while (v.x_coord <= end->y)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, v.x_coord, \
				v.y_coord, get_color(end->z));
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

/*
Function below uses same princible as mentioned above.
However in this case the slope is greater than 1 so
instead of always increasing x coordinate by one and checking
whether we should increase the y coordinate or not we do the opposite.
(That is we always increase y and check if we should also increase x or not)

In this case we also measure a distance between the point and pixel
like mentioned above but we measure the distance in x value, not in y
so the variables are flipped.

Example:

			  actual location for the point according to line equation y = mx + c
			 /
	.---.	  |	  .---.
	|   | --x---|   | <- pixel 2 ( x + 1, y)
	'---' \   \ '---'
	  ^    \   distance 2
	  |	  \
	  |	   distance 1
	pixel 1 (x, y)
*/

void	steep_slope(t_mlx *mlx, t_point *end, t_var v)
{
	v.bresenham = 2 * v.delta_x - v.delta_y;
	while (v.y_coord <= end->y)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, v.x_coord, \
				v.y_coord, get_color(end->z));
		if (v.bresenham < 0)
			v.bresenham = v.bresenham + 2 * v.delta_x;
		else
		{
			v.bresenham = v.bresenham + 2 * v.delta_x - 2 * v.delta_y;
			v.x_coord++;
		}
		v.y_coord++;
	}
}
/*
The main function that gets called when drawing a line.
Calculates all necessary variables we need EXCEPT the
decision parameter v.bresenham since it is calculated
differently depengin if the slope is greater or less than 1.

In function below we calculate the slope and depending if
it is greater or less than one we call either function
steep_slope(if slope > 1) or gentle_slope(if 0 < slope < 1)
*/

void	draw_bresenham(t_mlx *mlx, t_point *start, t_point *end)
{
	double	slope;
	t_var	v;

	initialize_variables(&v);
	v.delta_x = end->x - start->x;
	v.delta_y = end->y - start->y;
	v.x_coord = start->x;
	v.y_coord = start->y;
	if (v.delta_x == 0)
		slope = 1;
	else
		slope = v.delta_y / v.delta_x;
	if (slope < 1 && slope > 0)
		gentle_slope(mlx, end, v);
	else if (slope >= 1)
		steep_slope(mlx, end, v);
	else
		draw_straight(mlx, start, end);
}

/*
The main function that gets called when we draw a map.
Function goes through the linked list which contains all the
points we've read from the file.

First we draw the line from point to the next
(note! if the point is at the end of the row and the
next point is on another row no line is drawn because
the draw_bresenham function only works with slopes <= 0.
This is intentional).

Next we draw the line from the point to the point "below".
To do this we go through the list until we find a point
with the same x value.
*/

void	draw_map(t_mlx *mlx, t_point *point)
{
	t_point	*next;

	next = point->next;
	while (point->next)
	{
		next = point->next;
		draw_bresenham(mlx, point, next);
		while (point->x != next->x && next->next)
			next = next->next;
		draw_bresenham(mlx, point, next);
		point = point->next;
	}
}
