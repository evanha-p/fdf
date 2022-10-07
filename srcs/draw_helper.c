/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:47:43 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/07 14:35:34 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Helper function for draw_straight located draw.c.
Only draws horizontal lines.
The if statement starting from line 31 prevents the map from
being drawn on top of the menu or outside of the screen.

Note:

The zoom variable is set to 1 by default. We can modify the value if we want
to make the object bigger or smaller (see function zoom_points in
event_modifiers.c). By using a separate varibale zoom we can alter how
we draw the lines without altering the actual x and y values of the points.
If we were to modify the coordinates we would loose accuracy when making
the object really small since x and y are stored as int so they get
rounded when modified. This would cause distortion in the object after
making the object small and then increasing the size.
*/

void	draw_horizontal(t_point *start, t_point *end, t_mlx *mlx)
{
	t_var	v;

	initialize_variables(&v);
	v.x_coord = start->x * start->zoom;
	v.y_coord = start->y * start->zoom;
	while (v.x_coord <= (int)(end->x * end->zoom))
	{
		if (!(v.x_coord > IMG_X || v.x_coord < 0 \
					|| v.y_coord > IMG_Y || v.y_coord < 0 \
					|| (v.y_coord < MENU_Y && v.x_coord < MENU_X)))
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, v.x_coord, \
					(end->y * end->zoom), get_color(start, end));
		v.x_coord++;
	}
}

/*
Helper function for draw_straight located draw.c.
Only draws vertical lines.
The if statement starting from line 56 prevents the map from
being drawn on top of the menu or outside of the screen.

Note:

The zoom variable is set to 1 by default. We can modify the value if we want
to make the object bigger or smaller (see function zoom_points in
event_modifiers.c). By using a separate varibale zoom we can alter how
we draw the lines without altering the actual x and y values of the points.
If we were to modify the coordinates we would loose accuracy when making
the object really small since x and y are stored as int so they get
rounded when modified. This would cause distortion in the object after
making the object small and then increasing the size.
*/

void	draw_vertical(t_point *start, t_point *end, t_mlx *mlx)
{
	t_var	v;

	initialize_variables(&v);
	v.x_coord = start->x * start->zoom;
	v.y_coord = start->y * start->zoom;
	while (v.y_coord <= (int)(end->y * end->zoom))
	{
		if (!(v.x_coord > IMG_X || v.x_coord < 0 \
					|| v.y_coord > IMG_Y || v.y_coord < 0 \
					|| (v.y_coord < MENU_Y && v.x_coord < MENU_X)))
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, (end->x * end->zoom), \
					v.y_coord, get_color(start, end));
		v.y_coord++;
	}
}
