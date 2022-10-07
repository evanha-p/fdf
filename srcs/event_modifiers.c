/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <evanha-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:42:41 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/07 15:02:00 by evanha-p         ###   ########.fr       */
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
The function gets called if arrow keys are pressed while the
program is running. The callee function is located in events.c.
Modifies the x and y values of each point according to the
button press. This way we can move the picture.
*/

t_point	*move_points(t_point *point, int x, int y)
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

/*
Changes the color -value in each point. The color is
stored as a int but does NOT correspond to the actual
hexadecimal colorvalue. Instead it corresponds
to the key value which program receives when a button
is pressed.

For example:
To change to color white one would press number 1
on a keyboard. When 1 is pressed the program receives
a keypress value 18. This value is stored to point->color.

Function get_color, located in utils., checks the
point->color value stored in a point and sends the right
hexadecimal colorvalue to mlx_pixel_put.

I decided to do this in this way so we can use the
same macro for the keypress and for sending the
value to change_color (see function color in events.c).
This helps with readability.
*/

t_point	*change_color(t_point *point, int color)
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

/*
Changes the y value if w or s is pressed when the program is
running. Only changes the y value for a point if its z
value is other than 0. This way pressing w or s
we can "amplify" the height values in the picture.
*/

t_point	*change_height(t_point *point, int change)
{
	t_point	*head;

	head = point;
	while (point)
	{
		if (point->z < 0)
			point->y += point->z * change;
		if (point->z > 0)
			point->y -= point->z * change;
		point = point->next;
	}
	return (head);
}
