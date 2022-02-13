/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:06:56 by anclarma          #+#    #+#             */
/*   Updated: 2022/02/13 11:27:27 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	line_size(t_list *lst_line)
{
	return (ft_atoi(lst_line->content));
}

int	line_size_max(t_list *lst_line)
{
	int	max;
	int	n_current;

	max = 0;
	while (lst_line)
	{
		n_current = line_size(lst_line);
		if (n_current > max)
			max = n_current;
		lst_line = lst_line->next;
	}
	return (max);
}

int	empty_line(char *line)
{
	return (line && line[0] == '\0');
}

int	valid_line(char *line)
{
	if (!empty_line(line) && (!ft_secure_atoi(line) || !ft_strisdigit(line)
			|| ft_atoi(line) <= 0))
		return (1);
	return (0);
}

int	ft_free(char **ptr, int ret)
{
	free(*ptr);
	*ptr = NULL;
	return (ret);
}
