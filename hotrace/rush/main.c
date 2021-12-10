/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:08:24 by anclarma          #+#    #+#             */
/*   Updated: 2021/12/10 23:17:44 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "hotrace.h"

void	ft_putendl_fd(char *s, int fd)
{
	ssize_t	ret;

	if (!s)
		return ;
	ret = write(fd, s, ft_strlen(s));
	ret = write(fd, "\n", 1);
	(void)ret;
}

static int	hash_dico(char *line)
{
	int	ret;

	ret = 0;
	while (*line)
	{
		ret = ret + 1 * (char)(*line);
		line++;
	}
	return (ret % 50000);
}

static void	intern_dico(int mode, char *line)
{
	static char	*dico_key[50000] = {0};
	static char	*dico_value[50000] = {0};
	int			hash;

	if (mode == 0)
		return ;
	else if (mode == 1)
	{
		hash = hash_dico(line);
		dico_key[hash] = line;
		get_next_line(0, &line);
		dico_value[hash] = line;
	}
	else
	{
		ft_putendl_fd(dico_value[hash_dico(line)], 1);
	}
}

static void	init_dico(void)
{
	intern_dico(0, NULL);
}

static void	add_dico(char *line)
{
	intern_dico(1, line);
}

static void	search_dico(char *line)
{
	intern_dico(2, line);
}

int	main(void)
{
	char	*line;

	line = NULL;
	init_dico();
	while (get_next_line(0, &line) > 0 && *line)
		add_dico(line);
	while (get_next_line(0, &line) > 0)
		search_dico(line);
	return (0);
}
