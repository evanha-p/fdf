/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:16:27 by evanha-p          #+#    #+#             */
/*   Updated: 2022/09/22 15:15:10 by evanha-p         ###   ########.fr       */
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

Note: to help with readability in the notes I use "point" when talking about a point
in the linked list. I use "POINT" (in all caps) when talking about
the verb "point" (like for example when pointer POINTS to something).

On lines 78 and 79 we store the maximum number of cart_x in he first row
to a variable max_x. We use this variable to check that all the lines
have the same number of points. To achieve this we use pointer
prev_point, which POINTS to the previous point in the list (see line 93
where we set prev_point to POINT to current point before we set the set
the current point to POINT to the next point in the list).

If we detect that the cart_y in current point is greater than
in the previous we know we have switched to the next row.
Then we take the cart_x from the previous point in the previous row (prev_point->cart_x)
and make sure it is equal to max_x. If it's not we know the row before
had either more or less points stored and we call function errors.
(See notes in reader.c for further explanation on why I check this.
The explanation starts on row 68.)

After exiting the while loop we check the cart_x from the previous point.
Without this step we wouldn't check the last row in the file.

The function returns the number of rows (max_x). We have to increase max_x by one
at the end since max_x stores the max value of cart_x but we want to return
the number of points in a row.
Example:

0 0 0 0
0 0 0 0
0 0 0 0
      ^
	  |
   This point has the cart_x value of 3 (since the cart_x starts from 0)
   but it is the fourth point in the row. Hence number of points in the
   row is 4 not 3.
*/
static	int check_row_lengths(t_point *point)
{
	t_point	*head;
	t_point	*prev_point;
	int		max_x;

	head = point;
	prev_point = point;
	max_x = -1;
	while (point->next)
	{
		if (point->cart_y == 0)
			max_x = point->cart_x;
		if (prev_point->cart_y < point->cart_y)
		{
			if (prev_point->cart_x != max_x)
				errors("mismatching line lengths");
		}
		prev_point = point;
		point = point->next;
	}
	if (prev_point->cart_x != max_x)
		errors("mismatching line lengths");
	point = head;
	return (max_x + 1);
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
