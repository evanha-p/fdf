/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:42:08 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/05 19:20:14 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, 0xB9FF00, \
			"esc = exit");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 30, 0xB9FF00, \
			"UP/DOWN/LEFT/RIGHT arrow keys = move image");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 50, 0xB9FF00, \
			"+/- = zoom image");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 70, 0xB9FF00, \
			"w/s = raise/lower the height");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 90, 0xB9FF00, \
			"r/i = switch between sideways and isometric projection");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 110, 0xB9FF00, \
			"w/s = raise/lower the height");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 130, 0xB9FF00, \
			"1 = set color to white");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 150, 0xB9FF00, \
			"2 = set color to red");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 170, 0xB9FF00, \
			"3 = set color to green");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 190, 0xB9FF00, \
			"4 = highlight negative and positive height values");
}
/*
Function handles the moving and zooming events. It uses
functions move_points and zoom_points that are located
in event_modifiers.c
*/

static	void	move_picture(int key, t_ptrs *pointers)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	check_malloc((void *)mlx);
	mlx = pointers->mlx;
	if (key == UP)
		pointers->point = move_points(pointers->point, 0, -10);
	if (key == DOWN)
		pointers->point = move_points(pointers->point, 0, 10);
	if (key == LEFT)
		pointers->point = move_points(pointers->point, -10, 0);
	if (key == RIGHT)
		pointers->point = move_points(pointers->point, 10, 0);
	if (key == ZOOM_BIGGER)
		pointers->point = zoom_points(pointers->point, 1.1);
	if (key == ZOOM_SMALLER)
		pointers->point = zoom_points(pointers->point, 0.9);
	if (key == RAISE)
		pointers->point = change_height(pointers->point, 1);
	if (key == LOWER)
		pointers->point = change_height(pointers->point, -1);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	draw_map(pointers->mlx, pointers->point);
}

/*
Static helper function that handles changing from a projection
to another
*/

static	void	change_projection(int key, t_ptrs *pointers)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	check_malloc((void *)mlx);
	mlx = pointers->mlx;
	pointers->point = reset_values(pointers->point);
	if (key == ISOMETRIC)
		pointers->point = cartesian_to_isometric(pointers->point);
	if (key == ROTATE)
		pointers->point = sideways_projection(pointers->point);
	center(pointers->point, pointers->v);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	draw_map(pointers->mlx, pointers->point);
}

static	void	color(int key, t_ptrs *pointers)
{
	if (key == WHITE)
		pointers->point = change_color(pointers->point, WHITE);
	if (key == RED)
		pointers->point = change_color(pointers->point, RED);
	if (key == GREEN)
		pointers->point = change_color(pointers->point, GREEN);
	if (key == HIGHLIGHT)
		pointers->point = change_color(pointers->point, HIGHLIGHT);
	mlx_clear_window(pointers->mlx->mlx_ptr, pointers->mlx->win_ptr);
	draw_map(pointers->mlx, pointers->point);
}

/*
The main function used to handle events. Calls others.
We use macros to help with the readability.
*/

int	key_event(int key, t_ptrs *pointers)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	check_malloc((void *)mlx);
	mlx = pointers->mlx;
	if (key == ESC)
	{
		ft_putstr("Exited program\n");
		exit(0);
	}
	if ((key >= LEFT && key <= UP) || key == ZOOM_BIGGER ||key == ZOOM_SMALLER \
			|| key == RAISE || key == LOWER)
		move_picture(key, pointers);
	else if (key == ROTATE || key == ISOMETRIC)
		change_projection(key, pointers);
	else if (key >= WHITE && key <= HIGHLIGHT)
		color(key, pointers);
	else
		ft_putnbr(key);
	return (0);
}
