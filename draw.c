/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:53:43 by evanha-p          #+#    #+#             */
/*   Updated: 2022/06/29 19:19:07 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line(t_mlx *mlx, t_line *line)
{
	double	distance_x;
	double	distance_y;
	double	tan_a;
	double	location_y;

	distance_x = line->end_x - line->start_x;
	distance_y = line->end_y - line->start_y;
	tan_a = distance_y / distance_x;
	distance_x = 0;
	while (line->start_x <= line->end_x)
	{
		location_y = line->start_y + (tan_a * distance_x);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, \
		line->start_x, location_y, 0xFFFFFF);
		line->start_x++;
		distance_x++;
	}
	return (0);
}
