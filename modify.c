/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:48:35 by evanha-p          #+#    #+#             */
/*   Updated: 2022/10/04 19:17:47 by evanha-p         ###   ########.fr       */
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
Sets the initial size of the picture so it fits the screen better.
*/

t_point	*scope(t_point *point, t_var *v)
{
	t_point	*tmp;

	tmp = point;
	if (v->y_coord >= v->x_coord)
		v->multiplier = 500 / v->y_coord;
	else
		v->multiplier = 500 / v->x_coord;
	while (point)
	{
		point->cart_x *= v->multiplier;
		point->cart_y *= v->multiplier;
		point = point->next;
	}
	return (tmp);
}

/*
Aims to center the picture in the center of the screen.
*/

t_point *center(t_point *point, t_var *v)
{
	t_point	*head;
	float	mid_x;
	float	mid_y;

	head = point;
	mid_x = v->x_coord / 2;
	mid_y = v->y_coord / 2;
	while (point)
	{
		point->x = point->x + 500 - mid_x;
		point->y = point->y + 500 - mid_y;
		point = point->next;
	}
	return (head);
}

/*
Converts the cartesian coordinates to isometric coordinates.

To get the isometric x value we simply minus the cartesian x
value by the y value. This is because if we were to move
one unit to the right (x changes) in the cartesian coordinates the distance
moved in the isometric coordinates would also be one (hence +x).
If we were to move one unit down (y changes) in the cartesian coordinates the
distance moved in the isometric coordinates would be negative one
in the x axis (hence -y).
To get the isometric y value we add half of x when we move one unit
to the right in the cartesian coordinates. We also add half of y
because we move half of y when we move one unit down in the cartesian
coordinates.

Example:

Cartesian           Isometric        
.---.---.            .
|  ---> |       . '    ' .           \
'---'---'     '        \ . ' .       | ------ 0.5
                ' .   . \      ' .   / 
				    ' .  v    . '    
					    ' . '
				   \_______/
				       |
					   1

Example above shows the instance where we move one unit to the
right in the cartesian system. We can see that in that case when moving
in the isometric map the x value changes by one and the y value by 0.5.

Cartesian        
  .---.                   . 
  |   |               . '   ' .
  '-|-'           ..'   /       ' .
  | V |       . '    ' /.      . '    \
  '---'   . '         V  ' . '        | ----- 0.5
            ' .        . '            /
			    '  . '
				\__________/
				      |
					  -1

Example above shows the instance where we move one unit down in the
cartesian system. We can see that cartesian x in the isometric movement
decrease by 1, hence we substract y to get the x value.
The cartesian y changes by 0.5, hence we add 0.5 y to the y value.

Note: the 0 value in the screen is located at the top so
that's why we decrease the y value by the height value.
If we were to add the height value to the y the height
would seem to be negative.
*/

t_point	*cartesian_to_isometric(t_point *points)
{
	t_point	*temp;
	double	x;
	double	y;

	temp = points;
	while (points)
	{
		x = points->cart_x;
		y = points->cart_y;
		points->x = x - y;
		points->y = (x + y) / 2 - points->z;
		points = points->next;
	}
	points = temp;
	return (points);
}

/*
Converts the projection to a "sideways" view. After converting the
object is tilted to its back and viewed from the "bottom".

Example:

0 1 0

If we were to give this map to the project and ask it to convert it
the map drawn after conversion would look something like this:

   /\
__/  \__

We achieve this by setting the y value equal to the negative value
of the height and keeping the x as it is. Again we use the negative
value of the height since the 0 is at the top of the screen.
*/

t_point	*sideways_projection(t_point *points)
{
	t_point	*head;

	head = points;
	while (points)
	{
		points->y = -points->z;
		points = points->next;
	}
	return (head);
}
