/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:18:51 by anclarma          #+#    #+#             */
/*   Updated: 2021/12/11 16:17:23 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "hotrace.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
		((char *)s)[i++] = '\0';
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s || !c)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dst)
		return (dst);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(count * size);
	if (!new_ptr)
		return (NULL);
	ft_bzero(new_ptr, count * size);
	return (new_ptr);
}

int	get_next_line(int fd, char **line)
{
	ssize_t	ret;
	char	*str;
	char	*tmp;
	char	buf[2];

	ret = read(fd, buf, 1);
	buf[1] = '\0';
	if (ret <= 0)
		return ((int)ret);
	str = ft_strdup("");
	if (!str)
		return (-1);
	while (ret > 0 && buf[0] != '\n')
	{
		tmp = str;
		str = ft_strjoin(tmp, buf);
		if (!str)
			return (-1);
		free(tmp);
		ret = read(fd, buf, 1);
	}
	*line = str;
	return (1);
}

/*
int	get_next_line(int fd, char **line)
{
	static char *buf = NULL;
	char		*tmp;
	size_t		len;
	int			eof;
	char	buffer[BUFFER_SIZE + 1];
	char	*swap;

	eof = 1;
	while (!ft_strchr(buf, '\n') && eof > 0)
	{

		ft_bzero(buffer, BUFFER_SIZE + 1);
		eof = read(fd, buffer, BUFFER_SIZE);
		if (!buf)
			buf = ft_strdup("");
		swap = buf;
		buf = ft_strjoin(swap, buffer);
		free(swap);
	}
	if (eof >= 0)
	{
		if (eof == 0)
			len = ft_strchr(buf, '\0') - buf;
		else
			len = ft_strchr(buf, '\n') - buf;
		*line = malloc(sizeof(char) * (len + 1));
		if (!*line)
			return (-1);
		ft_memcpy(*line, buf, len);
		(*line)[len] = '\0';
		if (eof == 0)
			tmp = NULL;
		else
			tmp = ft_strdup(ft_strchr(buf, '\n') + 1);
		free(buf);
		buf = tmp;
	}
	return (eof);
}
*/
