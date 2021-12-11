/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:08:24 by anclarma          #+#    #+#             */
/*   Updated: 2021/12/11 14:09:01 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
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

static void	intern_dico(int mode, char *line)
{
	static t_dico	dico = {0};
	t_dico			*dico_ptr;

	if (mode == 0)
		return ;
	else if (mode == 1)
	{
		dico_ptr = &dico;
		while (*line)
		{
			if ((dico_ptr->next)[(int)*line] == NULL)
				dico_ptr->next[(int)*line] = ft_calloc(sizeof(t_dico), 1);
			dico_ptr = dico_ptr->next[(int)*line];
			line++;
		}
		get_next_line(0, &line);
		dico_ptr->value = line;
	}
	else
	{
		dico_ptr = &dico;
		while (*line)
		{
			if (dico_ptr->next[(int)*line] == NULL)
				return ;
			dico_ptr = dico_ptr->next[(int)*line];
			line++;
		}
		ft_putendl_stdout(dico_ptr->value);
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
