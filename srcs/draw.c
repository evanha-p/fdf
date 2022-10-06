/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:53:43 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/05 19:42:45 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
This function gets called if the slope = 0.
Note!: The slope might not actually be 0 (for example if the
delta x = 0) but for simplicity we set the slope to 0
in the draw_bresenham function whenever either delta x or
delta y is 0 and react accordingly in this function.

The function only draws "straight" lines where the
value of y  or x stays the same.

If the other value is 0 and the other is negative
we need to flip the points so we can draw the line.

For example:
v.delta_y = 0 and v.delta_x > 0
The starting point will be on the left and the end on the right.
If v.delta_x < 0 the end will be on the left and the start
will be on the right so we need to draw the line from right to left.
In that case we simply flip the points we send to function
drawing_loop so it will consider the true starting point
as the end and vice versa.

The drawing_loop function is located in utils.c
*/

void	draw_straight(t_mlx *mlx, t_point *start, t_point *end, t_var v)
{
	if (v.delta_y == 0 && v.delta_x > 0)
		drawing_loop(start, end, mlx, "horizontal");
	else if (v.delta_y == 0 && v.delta_x < 0)
		drawing_loop(end, start, mlx, "horizontal");
	else if (v.delta_x == 0 && v.delta_y > 0)
		drawing_loop(start, end, mlx, "vertical");
	else
		drawing_loop(end, start, mlx, "vertical");
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
Note 2:
The if statement on rows 111-112 prevents map being drawn if the image is either
outside of the screen or on top of the menu.
*/

void	gentle_slope(t_mlx *mlx, t_point *start, t_point *end, t_var v)
{
	v.x_coord = start->x * start->zoom;
	v.y_coord = start->y * start->zoom;
	v.delta_y = fabs((double)v.delta_y);
	v.delta_x = fabs((double)v.delta_x);
	v.bresenham = 2 * v.delta_y - v.delta_x;
	while (v.x_coord != (int)(end->x * end->zoom))
	{
		if (!(v.x_coord > IMG_X || v.x_coord  < 0 || v.y_coord > IMG_Y || v.y_coord < 0 \
					|| (v.y_coord < MENU_Y && v.x_coord < MENU_X)))
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, v.x_coord, \
					v.y_coord, get_color(start, end));
		if (v.bresenham < 0)
			v.bresenham = v.bresenham + 2 * v.delta_y;
		else
		{
			v.bresenham = v.bresenham + 2 * v.delta_y - 2 * v.delta_x;
			v.y_coord++;
		}
		if (v.slope > 0)
			v.x_coord++;
		else
			v.x_coord--;
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

Note:
The if statement on rows 167-168 prevents map being drawn if the image is either
outside of the screen or on top of the menu.
*/

void	steep_slope(t_mlx *mlx, t_point *start, t_point *end, t_var v)
{
	v.x_coord = start->x * start->zoom;
	v.y_coord = start->y * start->zoom;
	v.delta_y = fabs((double)v.delta_y);
	v.delta_x = fabs((double)v.delta_x);
	v.bresenham = 2 * v.delta_x - v.delta_y;
	while (v.y_coord != (int)(end->y * end->zoom))
	{
		if (!(v.x_coord > IMG_X || v.x_coord  < 0 || v.y_coord > IMG_Y || v.y_coord < 0 \
					|| (v.y_coord < MENU_Y && v.x_coord < MENU_X)))
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, v.x_coord, \
					v.y_coord, get_color(start, end));
		if (v.bresenham < 0)
			v.bresenham = v.bresenham + 2 * v.delta_x;
		else
		{
			v.bresenham = v.bresenham + 2 * v.delta_x - 2 * v.delta_y;
			if (v.slope > 0)
				v.x_coord++;
			else
				v.x_coord--;
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
	t_var	v;

	initialize_variables(&v);
	v.delta_x = end->x - start->x;
	v.delta_y = end->y - start->y;
	if (v.delta_x == 0 || v.delta_y == 0)
		draw_straight(mlx, start, end, v);
	else	
	{
		v.slope = (float)v.delta_y / (float)v.delta_x;
		if (v.slope < 1 && v.slope > 0)
			gentle_slope(mlx, start, end, v);
		else if (v.slope >= 1)
			steep_slope(mlx, start, end, v);
		else if (v.slope > -1 && v.slope < 0)
			gentle_slope(mlx, end, start, v);
		else
			steep_slope(mlx, end, start, v);
	}
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
To do this we use pointer "below", which points to the next
point with the same x value as the current point. This
pointer is set up in the function set_points_below
located in utils.c.
IMPORTANT: Since we set the last rows below -pointers
to NULL in the set_points_below function the second
draw_bresenham -function doesn't get called when
we go thourgh the last row of values since the
if (point->below) will be always false because
point->below = NULL.
*/

void	draw_map(t_mlx *mlx, t_point *point)
{
	t_point	*next;
	t_point	*head;

	head = point;
	draw_menu(mlx);
	while (point->next)
	{
		next = point->next;
		if (point->cart_y == next->cart_y && next->next)
			draw_bresenham(mlx, point, next);
		if (point->below)
			draw_bresenham(mlx, point->below, point);
		point = point->next;
	}
	point = head;
}
