/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:56:51 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/05 19:46:18 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_point	*points;
	t_mlx	*mlx;
	t_var	*v;
	t_ptrs	*pointers;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	check_malloc((void *)mlx);
	v = (t_var *)malloc(sizeof(t_var));
	check_malloc((void *)v);
	pointers = (t_ptrs *)malloc(sizeof(t_ptrs));
	initialize_variables(v);
	if (argc != 2)
		return (0);
	points = reader(argv[1], v);
	points = set_points_below(points);
	points = scope(points, v);
	points = cartesian_to_isometric(points);
	points = center(points, v);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, IMG_X, IMG_Y, "evanha-p fdf");
	pointers->mlx = mlx;
	pointers->point = points;
	pointers->v = v;
	draw_map(mlx, points);
	mlx_key_hook(mlx->win_ptr, key_event, pointers);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}