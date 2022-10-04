/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <evanha-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:42:41 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/04 21:42:42 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Function gets called if + or - are pressed while the program is running.
The callee function is located in events.c.
The function modifies the zoom variable either by
increasing or decreasing it. This way we can zoom or
"dezoom" the picture.
*/

t_point	*zoom_points(t_point *point, float zoom)
{
	t_point	*head;

	head = point;
	while (point)
	{
		point->zoom *= zoom;
		point = point->next;
	}
	return (head);
}

/*
The function gets called if W, A, S, or D is pressed while the
program is running. The callee function is located in events.c.
Modifies the x and y values of each point according to the
button press. This way we can move the picture.
*/

t_point *move_points(t_point *point, int x, int y)
{
	t_point	*head;

	head = point;
	while (point)
	{
		point->x += x;
		point->y += y;
		point = point->next;
	}
	return (head);
}

/*
Sets point->x and point->y values to the original
values they were after sent to the function scope.
Also sets the zoom back to its original value of 1.
*/

t_point	*reset_values(t_point *point)
{
	t_point	*head;

	head = point;
	while (point)
	{
		point->x = point->cart_x;
		point->y = point->cart_y;
		point->zoom = 1;
		point = point->next;
	}
	return (head);
}

t_point *change_color(t_point *point, int color)
{
	t_point	*head;

	head = point;
	while (point)
	{
		point->color = color;
		point = point->next;
	}
	return (head);
}
