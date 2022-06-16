/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:43:14 by evanha-p          #+#    #+#             */
/*   Updated: 2022/06/16 15:59:24 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"

int     main()
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test_window");
    mlx_loop(mlx_ptr);
}
