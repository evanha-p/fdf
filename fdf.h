/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:54:58 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/06 16:15:40 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include <stdlib.h>
# include <math.h>

/* Stores all mlx related data */

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

/* Stores properties of a line */

typedef struct s_line
{
	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		color;
}	t_line;

/* Stores properties of a single point */

typedef struct s_point
{
	int		x;
	int		y;
	int		height;
	t_point	*next;
}	t_point;

/* Created a custom boolian so we can improve readability
 * by returning false/true instead of 0 or 1.
 */

typedef enum e_bool
{
	false,
	true
}	t_bool;

int		draw_line(t_mlx *mlx, t_line *line);

#endif
