/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:16:27 by evanha-p          #+#    #+#             */
/*   Updated: 2022/09/08 17:16:32 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	errors(char *str)
{
	ft_putstr_fd("Error: ", 2);
	if (!(ft_strcmp("invalid character", str)))
		ft_putstr_fd("file content invalid. Submit a file with only numbers and spaces.\n", 2);
	if (!(ft_strcmp("mismatching line lengths", str)))
		ft_putstr_fd("amount of points per line vary.\n", 2);
	if (!(ft_strcmp("file does not exist", str)))
		ft_putstr_fd("File does not exist\n", 2);
	if (!(ft_strcmp("null pointer", str)))
		ft_putstr_fd("malloc returned null.\n", 2);
	if (!(ft_strcmp("no nodes", str)))
		ft_putstr_fd("either the file is empty or only contains spaces.\n", 2);
	ft_putstr_fd("Usage: ./fdf <your file here>\n", 2);
	exit(0);
}

void	check_line(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])) && str[i] != ' ')
			errors("invalid character");
		i++;
	}
}

static	void check_row_lengths(t_point *point)
{
	t_point	*head;
	int		max_x;

	max_x = -1;
	head = point;
	while (point->next)
	{
		if (point->cart_y == 0)
			max_x = point->cart_x;
		else
		{
			if (max_x < point->cart_x)
				errors ("mismatching line lengths");
		}
		point = point->next;
	}
	point = head;
}

void	check_nodes(t_point *point)
{
	t_point	*head;
	int		i;
	int		max_x;

	i = 0;
	max_x = 0;
	head = point;
	while (point->next)
	{
		i++;
		point = point->next;
	}
	if (i == 0)
		errors("no nodes");
	point = head;
	check_row_lengths(point);
}
