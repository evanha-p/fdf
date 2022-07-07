/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:54:58 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/07 14:17:57 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
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

int		draw_line(t_mlx *mlx, t_line *line);

#endif
