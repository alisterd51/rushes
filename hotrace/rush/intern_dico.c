/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_dico.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:02:17 by anclarma          #+#    #+#             */
/*   Updated: 2021/12/11 16:05:12 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

static void	recurse_free(t_dico *dico)
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

static void	intern_add(char **line_adr, t_dico *dico)
{
	size_t	i;
	char	*line;

	i = 0;
	line = *line_adr;
	while (line[i])
	{
		if ((dico->next)[(int)(line)[i]] == NULL)
			dico->next[(int)(line)[i]] = ft_calloc(sizeof(t_dico), 1);
		if (dico->next[(int)(line)[i]] == NULL)
			return ;
		dico = dico->next[(int)(line)[i]];
		i++;
	}
	free(line);
	*line_adr = NULL;
	get_next_line(0, line_adr);
	dico->value = *line_adr;
}

static void	intern_search(char **line_adr, t_dico *dico)
{
	size_t	i;
	char	*line;

	i = 0;
	line = *line_adr;
	while (line[i])
	{
		if (dico->next[(int)(line)[i]] == NULL)
		{
			ft_put_error(line);
			free(line);
			line_adr = NULL;
			return ;
		}
		dico = dico->next[(int)(line)[i]];
		i++;
	}
	free(line);
	*line_adr = NULL;
	ft_putendl_stdout(dico->value);
}

void	intern_dico(int mode, char **line)
{
	static t_dico	dico = {0};
	int				i;

	if (mode == 0)
		return ;
	else if (mode == 1)
		intern_add(line, &dico);
	else if (mode == 2)
		intern_search(line, &dico);
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
