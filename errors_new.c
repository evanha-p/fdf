/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <evanha-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:25:10 by evanha-p          #+#    #+#             */
/*   Updated: 2022/08/07 18:25:11 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Function gets called if an error is detected*/

void	errors_new(char *str)
{
	ft_putstr_fd("Error: ", 2);
	if (!(ft_strcmp("invalid file content", str)))
		ft_putstr_fd("File content invalid. Submit a file with only numbers and spaces.\n", 2);
	if (!(ft_strcmp("too many spaces", str)))
	{
		ft_putstr_fd("Number of spaces doesn't match the number of points.", 2);
		ft_putstr_fd("Two for each empty point, one for each 'normal' point\n", 2);
	}
	if (!(ft_strcmp("file does not exist", str)))
		ft_putstr_fd("Couldn't find a file with that name.\n", 2);
	if (!(ft_strcmp("null pointer", str)))
		ft_putstr_fd("Malloc returned null\n", 2);
	if (!(ft_strcmp("no nodes", str)))
		ft_putstr_fd("Error. Either the file is empty or only contains spaces.\n", 2);
	ft_putstr("Usage: ./fdf <your file here>");
	exit(0);
}

void	check_node_new(char *str, t_var *v)
{
	v->spaces = 0;
	if (str[v->i] == ' ')
	{
		while (str[v->i] == ' ')
		{
			v->i++;
			v->spaces++;
		}
		if (v->spaces > (v->node_max_len + 1))
			errors_new("too many spaces");
	}
	else
	{
		while (str[v->i] != ' ' && str[v->i])
		{
			if (!ft_isdigit(str[v->i]) && str[v->i] != ' ')
				errors_new("invalid file content");
			v->i++;
		}
	}
}

void	check_line_new(char *line, t_var *v)
{
	v->i = 0;
	while (line[v->i])
	{
		if (line[v->i] != ' ' && !ft_isdigit(line[v->i]))
			errors_new("invalid file content");
		check_node_new(&line[v->i], v);
	}
}
