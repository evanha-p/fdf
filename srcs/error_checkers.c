/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:16:43 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/06 13:17:56 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	check_hexadecimal(char *str)
{
	int		i;

	i = 2;
	if (str[0] != 0 && str[1] != 'x')
		errors("invalid character");
	while (str[i])
	{
		if (!(ft_isdigit(str[i])) && (str[i] < 'A' \
					|| str[i] > 'F'))
			errors("invalid character");
		i++;
	}
	if (i != 8)
		errors("invalid character");
}

/*
Function checks that each point receives only contains the height and
the color for the point. Height can only contain numbers and
- for negative numbers. The color is given as a hexadecimal and separated
from the height by a , symbol.

Examples for correct values:
14
9,0xFFFFFF

Examples for incorrect values:
14ab
ab14
A
0xFFFFFF,14
14,0xFFFFFF,0

The function is called by set_values function located in reader.c.
The function calls errors() if it detects incorrect input.
*/

void	check_data(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (i > 2)
		errors("invalid character");
	i = 0;
	while (str[0][i])
	{
		if (!(ft_isdigit(str[0][i])) && str[0][0] != '-')
			errors("invalid character");
		i++;
	}
	if (str[1])
		check_hexadecimal(str[1]);
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

/*
Simple function that checks if the pointer it received is NULL.
If it detects such case it calls the errors function.
*/

void	check_malloc(void *ptr)
{
	if (!ptr)
		errors("null pointer");
}
