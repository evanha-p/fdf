/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:56:51 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/07 18:25:59 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_ptrs	*pointers;

	pointers = (t_ptrs *)malloc(sizeof(t_ptrs));
	check_malloc((void *)pointers);
	pointers->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	check_malloc((void *)pointers->mlx);
	pointers->v = (t_var *)malloc(sizeof(t_var));
	check_malloc((void *)pointers->v);
	initialize_variables(pointers->v);
	if (argc != 2)
		errors("");
	pointers->point = reader(argv[1], pointers->v);
	pointers->point = set_points_below(pointers->point);
	pointers->point = scope(pointers->point, pointers->v);
	pointers->point = cartesian_to_isometric(pointers->point);
	pointers->point = center(pointers->point, pointers->v);
	pointers->mlx->mlx_ptr = mlx_init();
	pointers->mlx->win_ptr = mlx_new_window(pointers->mlx->mlx_ptr, \
			IMG_X, IMG_Y, "evanha-p fdf");
	draw_map(pointers->mlx, pointers->point);
	mlx_key_hook(pointers->mlx->win_ptr, key_event, pointers);
	mlx_loop(pointers->mlx->mlx_ptr);
	return (0);
}
