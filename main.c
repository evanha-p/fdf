/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:56:51 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/07 18:28:50 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	/*t_mlx	*mlx;
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
	return (0);*/
	t_point	*points;

	if (argc != 2)
		return (0);
	points = reader(argv[1]);
	while (points->next)
	{
		if (points->exists)
			ft_putstr("REAL NODE\n");
		else
			ft_putstr("NO NODE\n");
		ft_putnbr(points->x);
		ft_putnbr(points->y);
		ft_putnbr(points->z);
		ft_putchar('\n');
		ft_putstr("----------------\n");
		points = points->next;
	}
	return (0);
}
