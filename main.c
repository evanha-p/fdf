/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:56:51 by evanha-p          #+#    #+#             */
/*   Updated: 2022/08/04 17:14:19 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	/*t_mlx	*mlx;*/
	/*t_line	*line;*/
	/*t_point	*start;*/
	/*t_point	*end;*/

	/*mlx = (t_mlx *)malloc(sizeof(t_mlx));*/
	/*line = (t_line *)malloc(sizeof(t_line));*/
	/*start = (t_point *)malloc(sizeof(t_point));*/
	/*end = (t_point *)malloc(sizeof(t_point));*/
	/*start->x = 500;*/
	/*start->y = 300;*/
	/*end->x = 600;*/
	/*end->y = 300;*/
	/*if (!mlx || !line)*/
		/*return (1);*/
	/*mlx->mlx_ptr = mlx_init();*/
	/*mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 500, "test window");*/
	/*[>straight right<]*/
	/*draw_bresenham(mlx, start, end);*/
	/*[>down right<]*/
	/*end->y = 600;*/
	/*draw_bresenham(mlx, start, end);*/
	/*[>straight down<]*/
	/*end->x = 500;*/
	/*draw_bresenham(mlx, start, end);*/
	/*[>straight up<]*/
	/*end->y = 100;*/
	/*draw_bresenham(mlx, start, end);*/
	/*[>straight left<]*/
	/*end->y = 300;*/
	/*end->x = 100;*/
	/*draw_bresenham(mlx, start, end);*/
	/*[>up left<]*/
	/*end->y = 150;*/
	/*draw_bresenham(mlx, start, end);*/
	/*[>down left<]*/
	/*end->y = 450;*/
	/*draw_bresenham(mlx, start, end);*/
	/*[>up right<]*/
	/*end->x = 800;*/
	/*end->y = 150;*/
	/*draw_bresenham(mlx, start, end);*/
	/*mlx_loop(mlx->mlx_ptr);*/
	/*return (0);*/
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
	points = nudge(250, points);
	points = cartesian_to_isometric(points);
	while (points->next)
	{
		if (points->exists)
			ft_putstr("REAL NODE\n");
		else
			ft_putstr("NO NODE\n");
		ft_putnbr(points->x);
		ft_putchar('\n');
		ft_putnbr(points->y);
		ft_putchar('\n');
		ft_putnbr(points->z);
		ft_putchar('\n');
		ft_putstr("----------------\n");
		points = points->next;
		i++;
	}
	points = temp;
	ft_putstr("Number of nodes: ");
	ft_putnbr(i);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 1000, "test window");
	draw_map(mlx, points);
	nudge(50, points);
	draw_dot(mlx, points);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
