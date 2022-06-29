/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:54:58 by evanha-p          #+#    #+#             */
/*   Updated: 2022/06/29 17:12:08 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h> /* DELETE THIS BEFORE COMMITTING!!! */

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
} t_mlx;

typedef struct s_line
{
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		color;
} t_line;

int		draw_line(t_mlx *mlx, t_line *line);

#endif
