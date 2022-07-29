/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:54:58 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/29 19:31:02 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

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

/* Created a custom boolian to improve readability.
 * false = 0
 * true = 1
 */

typedef enum e_bool
{
	false,
	true
}	t_bool;

/* Stores properties of a single point */

typedef struct s_point	t_point;
struct s_point
{
	t_bool	exists;
	int		x;
	int		y;
	int		z;
	t_point	*next;
};

typedef struct s_var
{
	int		i;
	int		x_coord;
	int		y_coord;
	int		ret;
	int		length;
	int		start;
	int		delta_x;
	int		delta_y;
	int		bresenham;
}	t_var;

int		draw_line(t_mlx *mlx, t_line *line);
t_point	*reader(char *argv);
void	initialize_variables(t_var *var);
void	errors(char *str);
t_point	*new_point(t_point *point);
void	check_line(char *str);
void	check_nodes(t_point *point);
void	draw_bresenham(t_mlx *mlx, t_point *start, t_point *end);
void	gentle_slope(t_mlx *mlx, t_point *end, t_var v);
void	steep_slope(t_mlx *mlx, t_point *end, t_var v);
void	draw_map(t_mlx *mlx, t_point *point);
t_point	*scope(int scope, t_point *point);
t_point *nudge(int nudge, t_point *point);
#endif
