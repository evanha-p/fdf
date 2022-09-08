/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:45:08 by evanha-p          #+#    #+#             */
/*   Updated: 2022/09/08 17:16:33 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_point	*set_values(t_point *point, char *line, t_var *v)
{
	int		i;
	char	**values;

	i = 0;
	values = ft_strsplit(line, ' ');
	while (values[i])
	{
		point->cart_y = v->y_coord;
		point->y = v->y_coord;
		point->cart_x = i;
		point->x = i;
		point->z = ft_atoi(values[i]);
		point = new_point(point);
		i++;
	}
	point->next = NULL;
	return (point);
}

t_point	*reader(char *argv)
{
	t_var	*v;
	t_point	*temp;
	t_point	*head;
	char	*line;

	v = (t_var *)malloc(sizeof(t_var));
	initialize_variables(v);
	temp = (t_point *)malloc(sizeof(t_point));
	head = temp;
	v->ret = 1;
	v->fd = open(argv, O_RDONLY);
	if (v->fd < 0)
		errors("file does not exist");
	while (v->ret > 0)
	{
		v->ret = get_next_line(v->fd, &line);
		check_line(line);
		temp = set_values(temp, line, v);
		v->y_coord++;
	}
	temp = head;
	check_nodes(temp);
	return (temp);
}
