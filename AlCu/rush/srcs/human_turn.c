/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   human_turn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:06:56 by anclarma          #+#    #+#             */
/*   Updated: 2022/02/13 12:42:59 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "alcu.h"
#include "libft.h"

static int	is_valid_move(int move, t_list *lst_line)
{
	return (move >= 1 && move <= 3
		&& move <= ft_atoi(ft_lstlast(lst_line)->content));
}

static int	human_apply_choice(char **line, t_list **lst_line)
{
	apply_move(ft_atoi(*line), lst_line);
	ft_free(line, 0);
	return (1);
}

static int	human_repeat_choice(char **line)
{
	ft_putstr_fd(*line, 1);
	ft_putendl_fd(" - Invalid choice", 1);
	ft_putendl_fd("Please choose between 1 and 3 items", 1);
	free(*line);
	return (get_next_line(0, line));
}

int	human_turn(t_list **lst_line)
{
	int		ret;
	int		valid_choice;
	char	*line;

	valid_choice = 0;
	ft_putendl_fd("Please choose between 1 and 3 items", 1);
	ret = get_next_line(0, &line);
	while (ret >= 0 && valid_choice == 0)
	{
		if (line && valid_line(line) == 0
			&& is_valid_move(ft_atoi(line), *lst_line))
			valid_choice = human_apply_choice(&line, lst_line);
		else
			ret = human_repeat_choice(&line);
	}
	free(line);
	if (*lst_line == NULL)
		return (2);
	if (ret == -1 || ft_lstlast(*lst_line)->content == NULL)
		return (-2);
	return (0);
}
