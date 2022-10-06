/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:47:43 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/06 14:06:10 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Helper function for draw_straight located draw.c.
Only draws horizontal lines.
The if statement starting from line 31 prevents the map from
being drawn on top of the menu or outside of the screen.
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
