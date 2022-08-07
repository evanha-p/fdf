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

static	void	find_longest_node(char *argv)
{
	char	**temp_arr;
	char	*line;
	t_var	v;

	initialize_variables(&v);
	v.ret = 1;
	v.fd = open(argv, O_RDONLY);
	if (fd < 0)
		errors("file does not exist");
	while (v.ret > 0)
	{
		v.ret =  get_next_line(v.fd, &line);
		temp_arr = ft_strsplit(line, ' ');
		while (temp_arr(v.i))
		{
			if (ft_strlen(temp_arr[v.i]) > v.node_max_len)
				node_max_len = ft_strlen(temp_arr[v.i]);
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

	initialize_variables(v);
	v.ret = 1;
	v->node_max_len = find_longest_node(argv);
	temp = (t_point *)malloc(sizeof(t_point));
	head = temp;
	v->fd = open(argv, O_RDONLY);
	if (v->fd < 0)
		errors("file does not exist");
	while (v->ret > 0)
	{
		v->ret = get_next_line(fd, &line);
		check_line_new(line, v);
	}
}
