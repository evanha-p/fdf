/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:54:58 by evanha-p          #+#    #+#             */
/*   Updated: 2022/09/22 15:56:51 by evanha-p         ###   ########.fr       */
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
	int		x;
	int		y;
	int		z;
	int		cart_x;
	int		cart_y;
	t_point	*next;
};

typedef struct s_var
{
	int		x_coord;
	int		y_coord;
	int		ret;
	int		start;
	int		delta_x;
	int		delta_y;
	int		bresenham;
	float	slope;
	int		fd;
	float	multiplier;
	int		max_x;
	int		min_x;
	int		max_y;
	int		min_y;
}	t_var;

int		draw_line(t_mlx *mlx, t_point start, t_point end);
t_point	*reader(char *argv, t_var *v);
void	initialize_variables(t_var *var);
void	errors(char *str);
t_point	*new_point(t_point *point);
void	check_line(char *str);
void	check_nodes(t_point *point, t_var *v);
void	draw_bresenham(t_mlx *mlx, t_point *start, t_point *end);
void	gentle_slope(t_mlx *mlx, t_point *start, t_point *end, t_var v);
void	steep_slope(t_mlx *mlx, t_point *start, t_point *end, t_var v);
void	draw_map(t_mlx *mlx, t_point *point);
void	draw_straight(t_mlx *mlx, t_point *start, t_point *end, t_var v);
t_point	*scope(t_point *point, t_var *v);
t_point *nudge(int nudge, t_point *point);
int		get_color(int height);
t_point	*cartesian_to_isometric(t_point *points);
void	drawing_loop(t_point *start, t_point *end, t_mlx *mlx, char *str);
void	draw_dot(t_mlx *mlx, t_point *points);
t_point *reader_new(char *argv);
void	errors_new(char *str);
void	check_node_new(char *str, t_var *v);
void	check_line_new(char *line, t_var *v);
void	check_malloc(void *ptr);
t_point	*center(t_point *point, t_var *v);
#endif
