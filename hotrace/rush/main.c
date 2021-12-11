/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:08:24 by anclarma          #+#    #+#             */
/*   Updated: 2021/12/11 17:07:56 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

static void	init_dico(void)
{
	intern_dico(0, NULL);
}

static void	add_dico(char **line)
{
	intern_dico(1, line);
}

static void	search_dico(char **line)
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
		add_dico(&line);
	free(line);
	while (get_next_line(0, &line) > 0)
		search_dico(&line);
	free_dico();
	return (0);
}
