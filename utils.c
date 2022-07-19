/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:04:24 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/19 14:24:26 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Sets all variables in struct t_var to 0*/

void	initialize_variables(t_var *var)
{
	var->i = 0;
	var->x_coord = 0;
	var->y_coord = 0;
	var->ret = 0;
	var->str_length = 0;
}
