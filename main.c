/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:56:51 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/29 19:33:18 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
/*
 *    t_mlx	*mlx;
 *    t_line	*line;
 *    t_point	*start;
 *    t_point	*end;
 *
 *    mlx = (t_mlx *)malloc(sizeof(t_mlx));
 *    line = (t_line *)malloc(sizeof(t_line));
 *    start = (t_point *)malloc(sizeof(t_point));
 *    end = (t_point *)malloc(sizeof(t_point));
 *    start->x = 100;
 *    start->y = 0;
 *    end->x = 1100;
 *    end->y = 1000;
 *    if (!mlx || !line)
 *        return (1);
 *    mlx->mlx_ptr = mlx_init();
 *    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 500, "test window");
 *    line->start_x = 0;
 *    line->start_y = 0;
 *    line->end_x = 1000;
 *    line->end_y = 1000;
 *    draw_bresenham(mlx, start, end);
 *    line->start_x = 50;
 *    line->start_y = 0;
 *    line->end_x = 1050;
 *    line->end_y = 1000;
 *    draw_line(mlx, line);
 *    mlx_loop(mlx->mlx_ptr);
 *    return (0);
 */
	t_point	*points;
	t_point	*temp;
	t_mlx	*mlx;
	int		i;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	i = 0;
	if (argc != 2)
		return (0);
	points = reader(argv[1]);
	temp = points;
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
		i++;
	}
	points = temp;
	points = scope(10, points);
	points = nudge(500, points);
	ft_putstr("Number of nodes: ");
	ft_putnbr(i);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 1000, "test window");
	draw_map(mlx, points);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
