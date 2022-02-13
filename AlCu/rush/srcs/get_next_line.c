/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:02:47 by anclarma          #+#    #+#             */
/*   Updated: 2022/02/13 05:54:23 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static int	ft_read(int fd, char **tmp, char **str, char (*buf)[2])
{
	*tmp = *str;
	*str = ft_strjoin(*tmp, *buf);
	if (*str == NULL)
		return (-1);
	free(*tmp);
	return (read(fd, *buf, 1));
}

int	get_next_line(int fd, char **line)
{
	ssize_t	ret;
	char	*str;
	char	*tmp;
	char	buf[2];

	*line = NULL;
	ret = read(fd, buf, 1);
	buf[1] = '\0';
	if (ret <= 0)
		return ((int)ret);
	str = ft_strdup("");
	if (!str)
		return (-1);
	while (ret > 0 && buf[0] != '\n')
	{
		ret = ft_read(fd, &tmp, &str, &buf);
		if (ret == -1)
			return (-1);
	}
	*line = str;
	if (buf[0] == '\n')
		return (1);
	return (0);
}
