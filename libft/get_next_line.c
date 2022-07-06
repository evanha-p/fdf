/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanha-p <evanha-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:57:41 by evanha-p          #+#    #+#             */
/*   Updated: 2022/07/06 16:31:03 by evanha-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Saves what we have in variable saved to variable line.
 * First we check where the '\n' if there is one.
 * We save everything before the first '\n' to line and the
 * rest to variable temp. After this we clear and free saved pointer
 * and set the pointer to temp and return 1.
 *
 * If we don't find '\n' we simply dublicate everything to line
 * and clear and free variable saved. We return 1 if there is
 * still something in variable line. Otherwise we return 0
 * meaning we have finished reading the file. */

int	ft_savestring(char **line, char **saved, int fd, int ret)
{
	int		i;
	char	*temp;

	i = 0;
	if (ft_strchr(saved[fd], '\n'))
	{
		while (saved[fd][i] != '\n')
			i++;
		*line = ft_strsub(saved[fd], 0, i);
		temp = ft_strsub(saved[fd], (i + 1), (ft_strlen(saved[fd]) - i));
		ft_strclr(saved[fd]);
		ft_strdel(&saved[fd]);
		saved[fd] = temp;
		return (1);
	}
	*line = ft_strdup(saved[fd]);
	ft_strclr(saved[fd]);
	ft_strdel(&saved[fd]);
	if (ret == 0)
		return (0 + (**line != 0));
	return (1);
}

/* Combines what we already have stored
 * in variable saved and what we read from buffer.
 * It stores it to temp returning it and clears
 * the variable saved. */

void	ft_joinandclean(char **saved, char *buffer, int fd)
{
	char	*temp;

	temp = ft_strjoin(saved[fd], buffer);
	ft_strclr(saved[fd]);
	ft_strdel(&saved[fd]);
	saved[fd] = temp;
}

/* The main function. First we check for errors and if
 * there is already something saved that includes '\n'. If
 * so we don't have to read again so we skip that part and
 * jump straight to ft_savestring.
 * In the while loop we read until we:
 * a) reach the end of file
 * b) find '\n'
 * In lines 76 to 79 we check if we already have something saved
 * and react respectively. If we don't we duplicate, if we do,
 * we combine the strings */

int	get_next_line(const int fd, char **line)
{
	static char	*saved[GNL_MAX_FD];
	char		buffer[GNL_BUFF_SIZE + 1];
	int			ret;

	ret = 1;
	if (fd < 0 || fd > MAX_FD || !line)
		return (-1);
	if (saved[fd] && ft_strchr(saved[fd], '\n'))
		return (ft_savestring(line, saved, fd, ret));
	while (ret)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		buffer[ret] = '\0';
		if (!saved[fd])
			saved[fd] = ft_strdup(buffer);
		else
			ft_joinandclean(saved, buffer, fd);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ft_savestring(line, saved, fd, ret));
}
