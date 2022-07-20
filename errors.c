/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:48:56 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/20 16:11:28 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Function gets called if an error is detected*/

void	errors(char *str)
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

void	check_nodes(t_point *point)
{
	t_point	*head;
	t_bool	found_point;

	head = point;
	found_point = false;
	while (point->next)
	{
		if (point->exists)
			found_point = true;
		point = point->next;
	}
	if (!found_point)
		errors("no nodes");
	point = head;
}

/*
 *Static helper function for check_line. Checks spaces between numbers
 *and makes sure the number is correct.
 *There should be two spaces if the empty point is at the BEGINNING of
 *the line.
 *If the empty point is somewhere in the MIDDLE or at the END the
 *amount of spaces should always be uneven number since an empty
 *point takes two spaces and there is one space after the height value.
 *
 *Examples (spaces replaced by '*' for readability):
 *
 *	10*		**
 *  --		 \
 *   \        correct way to represent an empty point
 *    \
 *     correct way to represent a point
 *
 *  Correct line with a empty point between 10 and 5:
 *	1*10***5
 *
 *	Correct line with an empty point at the end:
 *	5*3*2***
 *	
 *	Incorrect line, one space missing between 3 and 2:
 *	5*3**2
 *
 *  Incorrect line, there are two empty points between
 *  0 and 3 but there is also one extra space:
 *	0******3*5
 *
 *The values of points are stored incorrectly to the list
 *if we don't check that there are right amount of spaces
 *in each line.
 *Function calls errors() if it detects any funky stuff.
 */

static	void	check_spaces(char *str, t_var *variables)
{
	while (str[variables->i] == ' ')
	{
		variables->length++;
		variables->i++;
	}
	if (variables->start == 0 && variables->length % 2 != 0)
		errors("too many spaces");
	if (variables->start != 0 && variables->length != 0 && \
			(variables->length % 2 != 1))
		errors("too many spaces");
}

/*Validates each line sent by reader function in read.c*/

void	check_line(char *str)
{
	t_var	variables;

	initialize_variables(&variables);
	while (str[variables.i])
	{
		variables.start = variables.i;
		if (str[variables.i] != ' ' && !ft_isdigit(str[variables.i]))
			errors("invalid file content");
		check_spaces(str, &variables);
		variables.length = 0;
		if (ft_isdigit(str[variables.i]))
			variables.i++;
	}
}
