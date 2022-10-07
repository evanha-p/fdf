/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:16:27 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/07 14:15:27 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
A function that gets called if some errors are detected.
The function receives a string from the callee function
and based on the string prints an error message corresponding
to the error detected.

It also prints the usage and uses function exit to exit the program.

Note: all the callee functions are located in error_checkers.c
*/

void	errors(char *str)
{
	ft_putstr_fd("Error: ", 2);
	if (!(ft_strcmp("invalid character", str)))
	{
		ft_putstr_fd("file content invalid.", 2);
		ft_putstr_fd("Submit a file with only numbers and spaces", 2);
		ft_putstr_fd(" or hexadecimal color value separated by , ", 2);
		ft_putstr_fd("after the height\n", 2);
	}
	if (!(ft_strcmp("mismatching line lengths", str)))
		ft_putstr_fd("amount of points per line vary.\n", 2);
	if (!(ft_strcmp("file does not exist", str)))
		ft_putstr_fd("File does not exist\n", 2);
	if (!(ft_strcmp("null pointer", str)))
		ft_putstr_fd("malloc returned null.\n", 2);
	if (!(ft_strcmp("no nodes", str)))
		ft_putstr_fd("either the file is empty or only contains spaces.\n", 2);
	if (!(ft_strcmp("directory", str)))
		ft_putstr_fd("The file is a directory.\n", 2);
	ft_putstr_fd("Usage: ./fdf <your file here>\n", 2);
	exit(0);
}
