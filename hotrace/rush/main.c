/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:08:24 by anclarma          #+#    #+#             */
/*   Updated: 2021/12/11 14:39:57 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "hotrace.h"

void	ft_putendl_stdout(char *s)
{
	ssize_t	ret;

	if (!s)
		return ;
	ret = ft_strlen(s);
	s[ret] = '\n';
	ret = write(1, s, ret + 1);
	(void)ret;
}

static void recurse_free(t_dico *dico)
{
	int	i;

	i = 0;
	if (dico == NULL)
		return ;
	while (i < 128)
	{
		recurse_free(dico->next[i]);
		i++;
	}
	free(dico->value);
	free(dico);
}

static void	intern_dico(int mode, char *line)
{
	static t_dico	dico = {0};
	t_dico			*dico_ptr;
	int				i;

	if (mode == 0)
		return ;
	else if (mode == 1)
	{
		dico_ptr = &dico;
		i = 0;
		while (line[i])
		{
			if ((dico_ptr->next)[(int)line[i]] == NULL)
				dico_ptr->next[(int)line[i]] = ft_calloc(sizeof(t_dico), 1);
			dico_ptr = dico_ptr->next[(int)line[i]];
			i++;
		}
		free(line);
		get_next_line(0, &line);
		dico_ptr->value = line;
	}
	else if (mode == 2)
	{
		dico_ptr = &dico;
		i = 0;
		while (line[i])
		{
			if (dico_ptr->next[(int)line[i]] == NULL)
				return ;
			dico_ptr = dico_ptr->next[(int)line[i]];
			i++;
		}
		free(line);
		ft_putendl_stdout(dico_ptr->value);
	}
	else
	{
		i = 0;
		while (i < 128)
		{
			recurse_free(dico.next[i]);
			i++;
		}
		free(dico.value);
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

static void	free_dico(void)
{
	intern_dico(3, NULL);
}

int	main(void)
{
	char	*line;

	line = NULL;
	init_dico();
	while (get_next_line(0, &line) > 0 && *line)
		add_dico(line);
	free(line);
	while (get_next_line(0, &line) > 0)
		search_dico(line);
	free_dico();
	return (0);
}
