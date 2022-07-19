/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:43:51 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/19 17:25:37 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Simple helper function which skips all the characters
 * in the heighth value.
 * For example:
 *
 * 0 0 1000 5
 * 1 2 3 4
 * 0 0 0 0
 *
 * If we look at the value "1000" function increments the
 * value of i until we hit the space between 1000 and 5.*/

static	int	skipper(char *str, int i)
{
	while (str[i] != ' ' && str[i])
		i++;
	return (i);
}

/* Function set correct values to the point.
 * The x value is stored in point->x,
 * the y value in point->y and
 * the heighth is stored in point->z.
 *
 * In addition we also use point->exists to keep
 * track whether the point actually exists (=has an height).*/

static	void	set_point_values(t_point *point, t_bool boolean, \
		t_var variables, char *line)
{
	point->x = variables.x_coord;
	point->y = variables.y_coord;
	if (boolean)
	{
		point->exists = true;
		point->z = ft_atoi(&line[variables.i]);
	}
	else
	{
		point->exists = false;
		point->z = 0;
	}
}

/* Function gets called everytime we get to a new row.
 * In the while loop we check wether the spot is empty or
 * contains a point and react accordingly.
 * This way we are able to draw maps which that have "holes"
 * in the middle for example.
 *
 * The first if statement in the while loop happens if we hit
 * a spot where there is no point value stored. For example:
 *
 * 1 1 1 1
 * 1 2   3
 * 1 1 1 1
 *
 * The map above has an empty slot between '2' and '3'.
 * That point will be stored but its point->exists value
 * will be set to false.
 *
 * We use a helper function "skipper" to skip to next point.
 *
 * Like mentioned below we store the values to a linked list.
 * One node contains the information of a single point.*/

static	t_point	*read_row(t_point *point, char *line, int y)
{
	t_var	variables;

	initialize_variables(&variables);
	variables.y_coord = y;
	variables.length = ft_strlen(line);
	while (variables.i < variables.length)
	{
		if (line[variables.i] == ' ' && \
				(line[variables.i + 1] == ' ' || !line[variables.i + 1]))
		{
			set_point_values(point, false, variables, line);
			variables.x_coord++;
			variables.i++;
		}
		else
		{
			set_point_values(point, true, variables, line);
			variables.x_coord++;
			variables.i = skipper(line, variables.i);
		}
		point = new_point(point);
		variables.i++;
	}
	point->next = NULL;
	return (point);
}

/* The main function. Calls others. Responsible for opening the file and
 * going through all the columns. The points are stored to a linked list.*/

t_point	*reader(char *argv)
{
	int		fd;
	char	*line;
	t_var	variables;
	t_point	*temp;
	t_point	*head;

	initialize_variables(&variables);
	variables.ret = 1;
	temp = (t_point *)malloc(sizeof(t_point));
	head = temp;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		errors("file does not exist");
	while (variables.ret > 0)
	{
		variables.ret = get_next_line(fd, &line);
		check_line(line);
		temp = read_row(temp, line, variables.i);
		variables.i++;
	}
	temp = head;
	return (temp);
}
