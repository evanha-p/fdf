/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:42:08 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/04 19:21:11 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Function handles the moving and zooming events. It uses
functions move_points and zoom_points that are located
in modify.c
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
	if ((key >= LEFT && key <= UP) || key == ZOOM_BIGGER || key == ZOOM_SMALLER)
		move_picture(key, pointers);
	if (key == ROTATE || key == ISOMETRIC)
		change_projection(key, pointers);
	return (0);
}
