/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:16:27 by evanha-p          #+#    #+#             */
/*   Updated: 2022/09/09 16:19:41 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
A function that gets called if some errors are detected.The function receives a string
from the callee function and based on the string prints an error message corresponding
to the error detected.

It also prints the usage and uses function exit to exit the program.
*/
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

/*
Checks that the line received from the callee function (see reader function in reader.c)
only contains spaces or digits.
*/
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

/*
Helper function for check_nodes. Checks that all the rows in the original
file contain same amount of points.

First we check how many points are stored in the first row and store
that to the variable max_x. Then we go through the remaining points.
If in any point the x value of a point (stored in point->cart_x) is
greater that the max_x we know that that row had more points than 
the first row. (See notes in reader.c for further explanation on why I check this.
The explanation starts on row 68.)
*/
static	int check_row_lengths(t_point *point)
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
	return (max_x);
}

/*
Checks the points (that are stored in linked list) and counts
how many there are. If no points are detected the file
was either empty or only contained spaces.

Function calls static helper function check_row_lengths which
further checks the data we have stored.
*/
void	check_nodes(t_point *point, t_var *v)
{
	t_point	*head;
	int		i;

	i = 0;
	head = point;
	while (point->next)
	{
		i++;
		point = point->next;
	}
	if (i == 0)
		errors("no nodes");
	point = head;
	v->x_coord = check_row_lengths(point);
}

void	check_malloc(void *ptr)
{
	if (!ptr)
		errors("null pointer");
}
