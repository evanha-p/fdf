/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:56:51 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/07 15:01:18 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_mlx	*mlx;
	t_line	*line;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	line = (t_line *)malloc(sizeof(t_line));
	if (!mlx || !line)
		return (1);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 500, "test window");
	line->start_x = 0;
	line->start_y = 500;
	line->end_x = 1000;
	line->end_y = 0;
	draw_line(mlx, line);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
