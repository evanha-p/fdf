/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:48:56 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/19 17:43:39 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Function gets called if an error is detected*/

void	errors(char *str)
{
	if (!(ft_strcmp("invalid file content", str)))
		ft_putstr("File content invalid. Submit a file with only \
				numbers and spaces.\n");
	if (!(ft_strcmp("too many spaces", str)))
		ft_putstr("Number of spaces doesn't match the number of points. (Two for each empty point, \
			one for each 'normal' point\n");
	if (!(ft_strcmp("file does not exist", str)))
		ft_putstr("Couldn't find a file with that name.\n");
	if (!(ft_strcmp("null pointer", str)))
		ft_putstr("Malloc returned null\n");
	/*THESE ARE NOT IMPLEMENTED YET!!!*/
	if (!(ft_strcmp("no nodes", str)))
		ft_putstr("Error. Either the file is empty or only contains spaces. Please \
				submit a file with spaces and numbers\n");
	exit(0);
}

/*
 *Static helper function for check_line. Checks spaces between numbers
 *and makes sure the number is correct.
 *There should be two spaces if the empty point is at the BEGINNING of
 *the line.
 *If the empty point is somewhere in the MIDDLE or at the END the
 *amount of spaces should always be uneven numberi since an empty
 *point takes two spaces and there is one space after the height value.
 *
 *Example (spaces replaced by '*' for readability):
 *
 *  Correct line with a empty point between 10 and 5:
 *	1*10***5
 *	
 *	Incorrect line, one space missing between 3 and 2:
 *	5*3**2
 *
 *  Incorrect line, there are two empty points between
 *  0 and 3 but there is also one extra space:
 *	0******3*5
 *
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
