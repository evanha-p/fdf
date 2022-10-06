/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:45:08 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/06 17:28:42 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Static helper function for reader. Stores the values to a linked list.
The function receives a row (stored in variable line) from the original
file and splits it to character string using space (' ') as a delimeter using
ft_strsplit. The strings are stored in variable values.

After splitting we go through the values and use ft_atoi
to get the height and store it to point->z.

The x-value is based on the string we are currently on.
So the first string gets the x-value of 0 and so on.

The y-value is base on what row we are currently reading.
This information is sent by the callee function (reader) and
stored in v->y_coord.
*/
static	t_point	*set_values(t_point *point, char *line, t_var *v)
{
	int		i;
	char	**values;
	char	**point_data;

	i = 0;
	values = ft_strsplit(line, ' ');
	while (values[i])
	{
		point_data = ft_strsplit(values[i], ',');
		point->cart_y = v->y_coord;
		point->y = v->y_coord;
		point->cart_x = i;
		point->x = i;
		check_data(point_data);
		point->z = ft_atoi(point_data[0]);
		point->zoom = 1;
		point->color = WHITE;
		point = new_point(point);
		free(values[i]);
		free(point_data);
		i++;
	}
	free(values);
	point->next = NULL;
	return (point);
}

/*
Main function that calls the helper function.
We use special type of variable t_var *v to store multiple variables
such as ret, fd and so on (see the struct in fdf.h for the full list).

Function errors is used throughout the program and it gets called if any
errors are detected. Based on the string used as an argument errors function
can detect what kind of an error happened and print corresponding error message.

We read the file and check that it only contains digits or spaces with
check_line -function. Then we store the values of the points to a
linked list by using function set_values.
Note: we use varibale v->y_coord to keep track on the row we are on.
When we exit the while loop we minus y_coord by 1 since while loop
"fires" once after we have already read all the rows.

Finally we check the all the nodes (the points) using check_nodes function.
The function detects if no points are stored (file was empty/contained only
spaces) and makes sure every line has the equal amount of points.
For example:

4 5 3 6 3 4
1 3 3 4 5 2 1
3 5 2 1 0 0 

Above the second row has more points stored than on the first or third
row. This would be detected by the check_nodes -function.

We must do the check since our program cannot detect "holes" in the map.
So if one would want the program to draw a box they could give a file
like:

0 0 0
0   0
0 0 0

the program would not remember where the empty spot was. As a result the program
would read the file as if it would have been like this:

0 0 0
0 0 
0 0 0

We don't want this kind of behaviour so I chose to only accept files where
every line has equal amount of points. For example:

0 0 0
0 0 0
0 0 0

is a valid file.

After the last check we return temp to the callee function.
*/
t_point	*reader(char *argv, t_var *v)
{
	t_point	*temp;
	t_point	*head;
	char	*line;

	temp = (t_point *)malloc(sizeof(t_point));
	head = temp;
	v->ret = 1;
	v->fd = open(argv, O_RDONLY);
	if (v->fd < 0)
		errors("file does not exist");
	while (v->ret > 0)
	{
		v->ret = get_next_line(v->fd, &line);
		temp = set_values(temp, line, v);
		v->y_coord++;
		free(line);
	}
	v->y_coord--;
	temp = head;
	check_nodes(temp, v);
	return (temp);
}
