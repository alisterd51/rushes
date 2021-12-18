/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_dico.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:02:17 by anclarma          #+#    #+#             */
/*   Updated: 2021/12/18 22:56:50 by anclarma         ###   ########.fr       */
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
	while (i < 256)
	{
		recurse_free(dico->next[i]);
		i++;
	}
	free(dico->value);
	free(dico);
}

static void	intern_add(char **line_adr, t_dico *dico)
{
	size_t			i;
	char			*line;
	unsigned char	c;

	i = 0;
	line = *line_adr;
	while (line[i])
	{
		c = line[i];
		if ((dico->next)[c] == NULL)
			dico->next[c] = (t_dico *)malloc(sizeof(t_dico));
		if (dico->next[c] == NULL)
			return ;
		*(dico->next[c]) = (t_dico){0};
		dico = dico->next[c];
		i++;
	}
	free(line);
	*line_adr = NULL;
	get_next_line(0, line_adr);
	free(dico->value);
	dico->value = *line_adr;
	*line_adr = NULL;
}

static void	intern_search(char **line_adr, t_dico *dico)
{
	size_t			i;
	char			*line;
	unsigned char	c;

	i = 0;
	line = *line_adr;
	while (line[i])
	{
		c = line[i];
		if (dico->next[c] == NULL)
		{
			ft_put_error(line);
			free(line);
			line_adr = NULL;
			return ;
		}
		dico = dico->next[c];
		i++;
	}
	if (dico->value)
		ft_putendl_stdout(dico->value);
	else
		ft_put_error(line);
	free(line);
	*line_adr = NULL;
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
		while (i < 256)
		{
			recurse_free(dico.next[i]);
			i++;
		}
		free(dico.value);
	}
}
