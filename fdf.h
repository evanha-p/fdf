/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:54:58 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/05 19:04:44 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

// ESC = esc
// UP = arrow up
// DOWN = arrow down
// LEFT = arrow left
// RIGHT = arrow right
// ZOOM_BIGGER = +
// ZOOM_SMALLER = -
// RAISE = w
// LOWER = s
// ROTATE = R
// ISOMETRIC = I
// WHITE = nbr 1
// RED = nbr 2
// GREEN = nbr 3
// HIGHLIGHT (color changes based on height) = nbr 4
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ZOOM_BIGGER 24
# define ZOOM_SMALLER 27
# define RAISE 13
# define LOWER 1
# define ROTATE 15
# define ISOMETRIC 34
# define WHITE 18
# define RED 19
# define GREEN 20
# define HIGHLIGHT 21

/* Stores all mlx related data */

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

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
	double	zoom;
	int		color;
	t_point	*next;
	t_point	*below;
};

typedef struct s_var
{
	int		x_coord;
	int		y_coord;
	int		ret;
	int		delta_x;
	int		delta_y;
	int		bresenham;
	float	slope;
	int		fd;
	int		multiplier;
}	t_var;

typedef struct s_ptrs
{
	t_point	*point;
	t_mlx	*mlx;
	t_var	*v;
}	t_ptrs;

//Functions located in draw.c:
void	draw_map(t_mlx *mlx, t_point *point);
void	draw_bresenham(t_mlx *mlx, t_point *start, t_point *end);
void	steep_slope(t_mlx *mlx, t_point *start, t_point *end, t_var v);
void	gentle_slope(t_mlx *mlx, t_point *start, t_point *end, t_var v);
void	draw_straight(t_mlx *mlx, t_point *start, t_point *end, t_var v);

//Functions located in errors.c
void	check_malloc(void *ptr);
void	check_nodes(t_point *point, t_var *v);
void	check_data(char **str);
void	check_line(char *str);
void	errors(char *str);

//Functions located in event_modifiers.c
t_point	*zoom_points(t_point *point, float zoom);
t_point	*move_points(t_point *point, int x, int y);
t_point	*reset_values(t_point *point);
t_point	*change_color(t_point *point, int color);
t_point	*change_height(t_point *point, int change);

//Functions located in events.c
int		key_event(int key, t_ptrs *pointers);
void	draw_menu(t_mlx *mlx);

//Functions located in modify.c
t_point *sideways_projection(t_point *points);
t_point	*cartesian_to_isometric(t_point *points);
t_point	*center(t_point *point, t_var *v);
t_point	*scope(t_point *point, t_var *v);

//Functions located in reader.c
t_point	*reader(char *argv, t_var *v);

//Functions located in utils.c
void	drawing_loop(t_point *start, t_point *end, t_mlx *mlx, char *str);
int		get_color(t_point *start, t_point *end);
t_point	*new_point(t_point *point);
void	initialize_variables(t_var *var);
t_point	*set_points_below(t_point *point);
#endif
