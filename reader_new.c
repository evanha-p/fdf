/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <evanha-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:38:07 by evanha-p          #+#    #+#             */
/*   Updated: 2022/08/07 14:38:12 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	skipper_new(char* line, t_var v)
{
	int		skips;

	skips = 0;
	while (line[v.i] == ' ' || skips <= (v.node_max_len + 1))
	{
		v.i++;
		skips++;
	}
	return (v.i);
}

static	void	set_point_values_new(t_point *point, t_bool boolean, \
		t_var v, char *line)
{
	point->x = v.x_coord;
	point->cart_x = v.x_coord;
	point->y = v.y_coord;
	point->cart_y = v.y_coord;
	if (boolean)
	{
		point->exists = true;
		point->z = ft_atoi(&line[v.i]);
	}
	else
		point->exists = false;
}

static	t_point	*read_row_new(t_point *temp, char *line, t_var v)
{
	v.i = 0;
	while (line[v.i])
	{
		v.i = 0;
		if (line[v.i] == ' ')
			set_point_values_new(temp, false, v, line);
		else
			set_point_values_new(temp, true, v, line);
		v.i = skipper_new(line, v);
		temp = new_point(temp);
	}
	temp->next = NULL;
	return (temp);
}

static	int	find_longest_node(char *argv)
{
	char	**temp_arr;
	char	*line;
	t_var	v;

	initialize_variables(&v);
	v.ret = 1;
	v.fd = open(argv, O_RDONLY);
	if (v.fd < 0)
		errors("file does not exist");
	while (v.ret > 0)
	{
		v.ret =  get_next_line(v.fd, &line);
		temp_arr = ft_strsplit(line, ' ');
		while (temp_arr[v.i])
		{
			if (ft_strlen(temp_arr[v.i]) > (size_t)v.node_max_len)
				v.node_max_len = ft_strlen(temp_arr[v.i]);
			v.i++;
		}
	}
	close(v.fd);
	return (v.node_max_len);
}

t_point	*reader_new(char *argv)
{
	t_point	*head;
	t_point	*temp;
	t_var		*v;
	char		*line;

	v = (t_var *)malloc(sizeof(t_var));
	initialize_variables(v);
	v->ret = 1;
	v->node_max_len = find_longest_node(argv);
	temp = (t_point *)malloc(sizeof(t_point));
	head = temp;
	v->fd = open(argv, O_RDONLY);
	if (v->fd < 0)
		errors("file does not exist");
	while (v->ret > 0)
	{
		v->ret = get_next_line(v->fd, &line);
		check_line_new(line, v);
		temp = read_row_new(temp, line, *v);
		v->y_coord++;
	}
	temp = head;
	return (temp);
}
